#ifndef _ROM_H
#define _ROM_H

enum oprerator {
    ADD   = 0x01;
    SUB   = 0x02;
    MOV   = 0x03;
    JZ    = 0x04;
    POP   = 0x05;
    PUSH  = 0x06;
    CALL  = 0x07;
    JUMP  = 0x08;
    DIS   = 0x09;
    LOAD  = 0x0a;
    STORE = 0x0b;
    RET   = 0x0c;
};

#endif