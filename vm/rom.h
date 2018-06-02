#ifndef _ROM_H
#define _ROM_H

#define OP_COUNT 12

enum oprerator {
    ADD   = 0x01,
    SUB   = 0x02,
    MOV   = 0x03,
    JZ    = 0x04,
    POP   = 0x05,
    PUSH  = 0x06,
    CALL  = 0x07,
    JUMP  = 0x08,
    DIS   = 0x09,
    LOAD  = 0x0a,
    STORE = 0x0b,
    RET   = 0x0c
};


typedef int (*operation)(struct cpu*, struct ins*);

struct rom {
    // op[0] is empty
    operation op[OP_COUNT + 1];
};

void init_rom(struct rom *rom);
void free_rom(struct rom *rom);
struct rom *new_rom();


int op_add(struct cpu *cpu, struct ins *ins);
int op_sub(struct cpu *cpu, struct ins *ins);
int op_mov(struct cpu *cpu, struct ins *ins);
int op_jz(struct cpu *cpu, struct ins *ins);
int op_jump(struct cpu *cpu, struct ins *ins);
int op_pop(struct cpu *cpu, struct ins *ins);
int op_push(struct cpu *cpu, struct ins *ins);
int op_call(struct cpu *cpu, struct ins *ins);
int op_ret(struct cpu *cpu, struct ins *ins);
int op_dis(struct cpu *cpu, struct ins *ins);
int op_load(struct cpu *cpu, struct ins *ins);
int op_store(struct cpu *cpu, struct ins *ins);


#endif