#include <stdlib.h>
#include <stdio.h>
#include "vm.h"


struct bus *new_bus()
{
    struct bus *bus;
    bus = (struct bus*)malloc(sizeof(struct bus));
    if(bus == NULL) {
        fprintf(stderr, "Can not alloc  memory for bus\n");
        return NULL;
    }

    bus->ab = '\0';
    bus->cb = '\0';
    bus->db = '\0';
    bus->ram = NULL;

    return bus;
}


void init_bus(struct bus *bus, struct ram *ram)
{
    bus->ram = ram;
}
