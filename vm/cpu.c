#include <stdlib.h>
#include <string.h>
#include "vm.h"


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
