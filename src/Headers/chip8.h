#include <cstdint>

namespace chp{
    class chip8{
        #define NUM_REGISTERS 16
        #define STACK_MEM 16
        #define MAIN_MEM 4096
        #define RESOLUTION 64 * 32
        
        // 15 general purpose registers and the 16th is used for is used for flagging and should not be accessed
        uint8_t V[NUM_REGISTERS];
        //
        uint8_t ST;
        uint8_t DT;
        //
        uint16_t stack[STACK_MEM];
        uint16_t* sp;
        // The index (I) and program counter (PC) registers are meant for memory addresses and 
        uint16_t I;
        uint16_t PC;
        //
        uint8_t memory[MAIN_MEM];
        //
        uint8_t screen[RESOLUTION];

        void decode();
        void draw();

        public:
        // Constructor initializes registers and memory
        chip8();

        void cycle();
        void load(char[] filename);

        ~chip8();

    };
}