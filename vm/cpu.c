#include <stdlib.h>
#include <string.h>
#include "vm.h"


static void init_bp(struct cpu *cpu);


struct cpu * new_cpu()
{
	struct cpu *cpu = (struct cpu*)malloc(sizeof(struct cpu));
	memcpy(cpu->registers, '\0', REG_COUNT + 1);
	return cpu;
}


void run_ins(struct cpu *cpu, struct ins *ins)
{

}


void free_cpu(struct cpu *cpu)
{
	free(cpu);
}


static void init_bp(struct cpu *cpu)
{
    cpu->registers[BP_ADDR] = MAX_STACK;
}


void init_cpu(struct cpu *cpu)
{
	init_bp(cpu);
}
