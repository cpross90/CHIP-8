/*
    Bitmasks for CHIP-8 opcodes
        - Op Codes commands are AND masked and otherwised XOR masked

*/

#include <stdint.h>
#include "chip8.h"

// Clear screen
#define CLS 0x00E0
// Return
#define RET 0x00EE
// Jump
#define JP 0x1000
// Call subroutine
#define CALL  0x2000
// Increment PC by 2 if Vx == NN
#define SEVx 0x3000
// Increment PC by 2 if Vx != NN
#define SNEVx 0x4000
// Increment PC by 2 if Vx == VY
#define SEVxVy 0x5000
// Sets Vx to NN
#define LDVx 0x6000
// Adds NN to VX
#define ADDVx 0x7000
// Set Vx = Vy
#define LDVxVy 0x8000
// Set Vx = Vx || Vy
#define ORVxVy 0x8001
// Set Vx = Vx && Vy
#define ANDVxVy 0x8002
// Set Vx = Vx ^ Vy
#define XORVxVy 0x8003
// Set Vx = Vx + Vy, and set VF = carry
#define ADDVxVy 0x8004
// Set Vx = Vx - Vy, and if Vx < Vy, set VF = 1, else VF = 0
#define SUBVxVy 0x8005
// Set Vx = Vx >> 1, and if LSB in Vx == 1, set VF = 1, else VF = 0
#define SHRVx 0x8006
// Set Vx = Vy - Vx, and if Vy < Vx, set VF = 1, else VF = 0
#define SUBNVxVy 0x8007
// Set Vx = Vx << 1, and if MSB in Vx == 1, then VF = 1, else VF = 0
#define SHLVx 0x8008
// Increment PC by 2 if Vx != Vy
#define SNEVxVy 0x9000
// Set I = NNN
#define LDDI 0xA000
// Set PC = NNN
#define JPV0 0xB000
// Set Vx = rand() && NN
#define RNDVx 0xC000
// Display n-byte sprite at pos (Vx, Vy), set VF = collision; sprite is XOR with existing pixels, pixels wrap around screen
#define DRWVxVy 0xD000
// Increment PC by 2 if key pressed == Vx; checks if key Vx is in down pos
#define SKPVx 0xE09E
// Increment PC by 2 if key pressed != Vx; checks if key Vx is in up pos
#define SKNPVx 0xE0A1
// Set Vx to delay timer
#define LDVxDT 0xF007
// Store value key press in Vx; exec paused until key pressed
#define LDVxK 0xF00A
// Set delay timer to Vx
#define LDDTVx 0xF015
// Set sound timer to Vx
#define LDSTVx 0xF018
// Set I = I + Vx
#define ADDIVx 0xF01E
// Set I = Vx (sprite loc)
#define LDFVx 0xF029
// Store BCD rep of Vx at I, I + 1, I + 2 
#define LDBVx 0xF033
// Store V0 to Vx at I, set I = I + x + 1
#define LDIVx 0xF055
// Fill V0 to Vx with val from I, set I = I + x + 1
#define LDVxI 0xF065

void chp::decode(uint8_t opcode);
