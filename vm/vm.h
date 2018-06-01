#ifndef _VM_H
#define _VM_H

#define MAX_RAM 256
#define REG_COUNT 13
#define MAX_STACK 128

/* PSW:
-----------------------------------------------------------------
| bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 |
-----------------------------------------------------------------
|  CY   |   AC  |  F0   |  RS1  |  RS0  |  OV   |   Z   |  N    |
-----------------------------------------------------------------
CY: Carry falge
AC: Auxiliary carry flag
F0: Flag 0
RS1, RS0: Working register bank and address
OV: Overflow flag
Z: Zero flag
N: Negative flag
*/
#define PSW_CY  0x80  // 1000 0000
#define PSW_AC  0x40  // 0100 0000
#define PSW_F0  0x20  // 0010 0000
#define PSW_RS1 0x10  // 0001 0000
#define PSW_RS0 0x08  // 0000 1000
#define PSW_OV  0x04  // 0000 0100
#define PSW_Z   0x02  // 0000 0010
#define PSW_N   0x01  // 0000 0001


// Specific regiseter address
#define SP_ADDR 0x09
#define DR_ADDR 0x0a
#define AR_ADDR 0x0b
#define PC_ADDR 0x0c
#define IR_ADDR 0x0d


enum reg {
	R0 = 0x01,
	R1 = 0x02,
	R2 = 0x03,
	R3 = 0x04,
	R4 = 0x05,
	R5 = 0x06,
	R6 = 0x07,
	R7 = 0x08,
	SP = 0x09,
	DR = 0x0a,
	AR = 0x0b,
	PC = 0x0c,
	IR = 0x0d
}


enum addr {
	dire = 0x01,
	reg  = 0x02
}


struct cpu {
	// registers[0] is empty
	char registers[REG_COUNT + 1];
	char psw;
};


struct ins {
	char ins;
	char arg1;
	char arg2;
};


struct ram {
	char m[MAX_RAM];
};

char stack[MAX_STACK]

#endif // _VM_H