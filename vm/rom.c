#include <stdio.h>
#include "rom.h"
#include "vm.h"


static enum addr arg_addressing(char *arg);
static int get_arg_value(struct cpu* cpu, char *arg);
static void set_reg_value(struct cpu *cpu, char reg_id, char value);

static char get_pc(struct cpu *cpu);
static void set_pc(struct cpu *cpu, char value);
static void inc_pc(struct cpu *cpu);

static char get_sp(struct cpu *cpu);
static void set_sp(struct cpu *cpu, char value);
static void inc_sp(struct cup *cpu);
static void dec_sp(struct cpu *cpu);
static int stack_pop(struct cpu *cpu, char *value);
static int stack_push(struct cpu *cpu, char value);

static int set_dr(struct cpu *cpu, char data);
static int get_dr(strcuct cpu *cpu, char *data);

static char psw_flag(struct cpu *cpu, char which);


static int arg_value(struct cpu* cpu, char *arg)
{
    enum addr addressing;
    addressing = arg_addressing(arg);

	if(addressing == dier) {
		// arg is a number
		return *arg | 0x80;
	} else {
		// arg is register id
		return cpu->arg[*arg];
	}
}


static void set_reg_value(struct cpu *cpu, char reg_id, char value)
{
    cpu->registers[reg_id] = value;
}


static char get_sp(struct cpu *cpu)
{
    return cpu->registers[SP_ADDR];
}


static void set_sp(struct cpu *cpu, char value)
{
    cpu->registers[SP_ADDR] = value;
}


static char get_pc(struct cpu *cpu)
{
    return cpu->registers[PC_ADDR];
}

static void set_pc(struct cpu *cpu, char value)
{
    cpu->registers[PC_ADDR] = value;
}


static void inc_pc(struct cpu *cpu)
{
    char old = get_pc(cpu);
    set_cpu(cpu, old + 1);
}


static enum addr arg_addressing(char *arg)
{
    if((*arg & 0x80) > 0)
        return dire;
    else
        return reg;
}


static char psw_flag(struct cpu *cpu, char which)
{
    return cpu->psw & which;
}


static void inc_sp(struct cup *cpu)
{
    char old = get_sp(cpu);
    set_sp(cpu, old + 1);
}


static void dec_sp(struct cpu *cpu)
{
    char old = get_sp(cpu);
    set_sp(cpu, old - 1);
}


static int stack_pop(struct cpu *cpu, char *value)
{
    char sp = get_sp(cpu);
    if(sp < 0) {
        fprintf(stderr, "Stack empty\n");
        return 1;
    }
    *value = stack[sp];
    dec_sp(cpu);
    return 0;
}

static int stack_push(struct cpu *cpu, char value)
{
    char sp = get_sp(cpu);
    inc_sp(cpu);

    if(sp >= MAX_STACK) {
        fprintf(stderr, "Stack full\n");
        return 1;
    }
    stack[sp] = vlaue;
    return 0;
}


static int set_dr(struct cpu *cpu, char data)
{
    cpu->registers[DR_ADDR] = data;
    return 0;
}


static int get_dr(strcuct cpu *cpu, char *data)
{
    *data = cpu->registers[DR_ADDR];
    return 0;
}


int op_add(struct cpu *cpu, struct ins *ins)
{
    char result;

    if(arg_addressing(&(ins->arg1)) == dire) {
        fprintf(stderr, "first args should be a register address\n");
        return 1;
    }

    result = arg_value(ins->arg1) + arg_value(ins->arg2);
    set_reg_value(cpu, ins->arg1, result);
    return 0;
}


int op_sub(struct cpu* cpu, struct ins *ins)
{
    char result;

    if(arg_addressing(&(ins->arg1)) == dire) {
        fprintf(stderr, "first args should be a register address\n");
        return 1;
    }

    result = arg_value(ins->arg1) - arg_value(ins->arg2);
    set_reg_value(cpu, ins->arg1, result);
    return 0;
}


int op_mov(struct cpu* cpu, struct ins *ins)
{
    char value;

    if(arg_addressing(&(ins->arg1)) == dire) {
        fprintf(stderr, "first args should be a register address\n");
        return 1;
    }

    value = arg_value(ins->arg2);
    set_reg_value(cpu, ins->arg1, value);
    return 0
}


int op_jz(struct cpu* cpu, struct ins *ins)
{
    if(psw_flag(cpu, PSW_Z) == 0)
        return op_jump(cup, ins);
    return 0;
}


int op_jump(struct cpu* cpu, struct ins *ins)
{
    char target = get_arg_value(ins->arg1);
    set_pc(cpu, target);
    return 0;
}


int op_pop(struct cpu* cpu, struct ins *ins)
{
    char value;
    int status;

    status = stack_pop(cpu, &value);
    if(status != 0)
        return 1;

    set_reg_value(cpu, ins->arg1, value);
    return 0;
}


int op_push(struct cpu* cpu, struct ins *ins)
{
    int status;

    status = stack_push(cpu, get_arg_value(ins->arg1));
    if(status != 0)
        return 1

    return 0;
}


int op_call(struct cpu* cpu, struct ins *ins)
{
    
}


int op_ret(struct cpu* cpu, struct ins *ins)
{
    
}


int op_dis(struct cpu* cpu, struct ins *ins)
{
    char value = get_arg_value(ins->arg1);
    printf("%d\n", value);
    return 0;
}


int op_load(struct cpu* cpu, struct ins *ins)
{
    struct bus *bus;
    bus = cpu->bus;

    bus->cb = LOAD;
    bus->ab = get_arg_value(ins->arg1);
    if(wakeup_bus(bus) != 0) {
        fpritnf(stderr, "I/O error\n");
        return 1;
    }

    return set_dr(cpu, bus->db);
}


int op_store(struct cpu* cpu, struct ins *ins)
{
    struct bus *bus;
    bus = cpu->bus;

    bus->cb = STORE;
    bus->ab = get_arg_value(ins->arg1);
    get_dr(cpu, &(bus->db));

    return wakeup_bus(bus);
}


void init_cpu(struct cpu *cpu)
{

}
