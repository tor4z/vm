#include <stdlib.h>
#include <stdio.h>
#include "vm.h"


struct bus *new_bus()
{
    struct bus *bus;
    bus = (struct *bus)malloc(sizeof(struct bus));
    if(bus == NULL) {
        fprintf(stderr, "Can not alloc  memory for bus\n");
        return NULL
    }

    bus->ab = '\0';
    bus->cb = '\0';
    bus->db = '\0';
    bus->ram = NULL;

    return bus;
}


int wakeup_bus(struct bus *bus)
{
    if(bus->cb == LOAD) {
        // Load data to db from ram
        return ram_load(bus->ram, bus->ab, &(bus->db));
    } else if(bus->cb == STORE){
        // Store data in the db to ram
        return ram_store(bus->ram, bus->ab, bus->db);
    }
}
