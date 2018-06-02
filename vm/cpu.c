#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vm.h"


static void init_bp(struct cpu *cpu);


static void init_bp(struct cpu *cpu)
{
    cpu->registers[BP_ADDR] = MAX_STACK;
}


struct cpu *new_cpu()
{
	struct cpu *cpu = (struct cpu*)malloc(sizeof(struct cpu));
	if(cpu == NULL) {
		fprintf(stderr, "Can not alloc memory to cpu\n");
		return NULL;
	}
	memset(cpu->registers, '\0', REG_COUNT + 1);
	return cpu;
}


void run_ins(struct cpu *cpu, struct ins *ins)
{

}


void free_cpu(struct cpu *cpu)
{
	free(cpu);
}


void init_cpu(struct cpu *cpu)
{
	init_bp(cpu);
}
