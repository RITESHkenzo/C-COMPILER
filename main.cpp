#include <iostream>
#include <cstdint> 

// 1. Main Memory (RAM)
// Allocating an array of unsigned 8-bit integers to represent 64KB of RAM.
uint8_t memory[65536]; 

// 2. Registers
// Defining an enumeration for our general-purpose registers and special registers.
enum Registers {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, // Program Counter: tracks the memory address of the next instruction to execute
    R_COUNT // A handy trick to keep track of the total number of registers
};

// Mapping the enumerated registers to a uint16_t array.
uint16_t registers[R_COUNT];

int main() {
    // Initialize the Program Counter to start at memory address 0
    registers[R_PC] = 0;
    
    std::cout << "Virtual Hardware Initialized Successfully.\n";
    std::cout << "RAM: 64KB\n";
    std::cout << "Registers: " << R_COUNT << "\n";
    
    return 0;
}
