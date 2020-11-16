#include "chip8.h"

namespace chp{
    chip8::Chip8(){
        memset(stack, 0, uint8_t);
        memset(registers, 0, uint8_t);
        memset(memory, 0, uint8_t)

        PC = 0;
        I = 0;
        sp = stack + STACK_MEM;

        

    }

    void chip8::cycle(){
        if(PC == I)
            reset();

        uint16_t opcode = (memory[PC] << 8 | memory[PC + 1]);
        
        PC += 2;

        decode(opcode);

    }

    void chip8::load(char[] filename){

    }

    void chip8::draw(){

    }

}