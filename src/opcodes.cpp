#include "opcodes.h"

#define OPHIGH opcode & 0xF000
#define OPHIGH_LOW opcode & 0xF00F
#define OPX opcode & 0x0F00
#define OPY opcode & 0x00F0
#define OP4 opcode & 0x000F
#define OP8 opcode & 0x00FF
#define OP12 opcode & 0x0FFF
#define VX V[OPX >> 8]
#define VY V[OPY >> 4]

namespace chp{
    void chip8::decode(uint16_t opcode){

        switch(OPHIGH){
            case 0x0000: 
                switch(OP12){
                    case CLS:

                        break;

                    case RET:
                        PC = *sp
                        sp += 2;

                        break;
                            
                    default:
                        break;
                }
            
            case JP:
                PC = OP12;

                break;

            case CALL:
                sp -= 2;
                *sp = PC;
                PC = OP12;

                break;

            case SEVx:
                if(VX == OP8)
                    PC += 2;

                break;

            case SNEVx:
                if(VX != OP8)
                    PC += 2;
                break;

            case SEVxVy:
                if(OPHIGH_LOW == SEVxVY && VX == VY)
                    PC += 2;

                break;

            case LDVx:
                V[(opcode & 0xF00) >> 8] = OP8;

                break;

            case ADDVx:
                if(OPHIGH_LOW == ADDVx)
                    VX += OP8;

                break;

            case 0x8000: 
                switch(OPHIGH_LOW){
                    case LDVxVy:
                        VX = VY;

                        break;

                    case ORVxVy:
                        VX |= VY;

                        break;

                    case ANDVxVy:
                        VX &= VY;

                        break;

                    case XORVxVy:
                        VX ^= VY;

                        break;

                    case ADDVxVy:
                        VX += VY;

                        break;

                    case SUBVxVy:
                        VX -= VY;

                        break;

                    case SHRVx:
                        VX >>= 1;

                        break;

                    case SUBNVxVy:
                        VX = VY - VX;

                        break;

                    case SHLVx:
                        VX <<= 1

                        break;
                    
                    default:
                        break;
                }

                break;

            case SNEVxVy:
                if(OPHIGH_LOW == SNEVxVY && VX != VY)
                    PC += 2;
                
                break;

            case LDDI:
                I = OP12;

                break;

            case JPV0:
                PC = V[0] + (OP12)

                break;

            case RNDVx:
                VX = rand() & OP8;

                break;

            case DRWVxVy:

                break;

            case SKPVx:

                break;

            case SKNPVx:

                break;

            case LDVxDT:
                VX = DT;

                break;

            case LDVxK:

                break;

            case LDDTVx:
                DT = VX;

                break;
            
            case LDSTVx:
                ST = VX;

                break;

            case ADDIVx:
                I += VX;

                break;

            case LDFVx:
                I = fontset[VX];

                break;

            case LDBVx:
                uint8_t bin = VX;
                uint16_t bcd = 0;

                for(uint8_t i = 0; i < 8; i++){
                    bcd = bin << 1;
                    bin <<= 1;

                    if((bcd & 0x0F00) >> 8 > 5)
                        bcd += 0x0300;

                    if((bcd & 0x00F0) >> 4 > 5)
                        bcd += 0x0030;

                    if((bcd & 0x000F) > 5)
                        bcd += 0x0003;
                }

                memory[I] = bcd & 0x0F00;
                memory[I + 1] = bcd & 0x00F0;
                memory[I + 2] = bcd & 0x000F;

                break;

            case LDIVx:
                for(uint8_t i = 0; i < OPX; i++){
                    memory[I + i] = V[i];

                }

                break;

            case LDVxI:
                for(uint8_t i = 0; i < OPX; i++){
                    V[i] = memory[I + i];

                }

                break;
            
            default:            
                break;
        }
    }
}