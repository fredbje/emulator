#pragma once

#include <cinttypes>
#include <bit>
#include <array>


class R6502 {

    void reset() {
        // 6 cycles init time
        // Set mask interrupt flag
        // Load pc from memory vector lcoations FFFC and FFFD
        
    }

    void IRQ() {
        // Read I from the status register
        // If I is not set:
        // Store PC on stack
        // Store Status register on stack
        // Set I high, so no further interrupts can occur
        // Load PCL from FFFE and PCH from FFFF
        // RDY must be set high for interrupt to be reckognized
    }

    void NMI() {
        // Non maskable interrupt
        // Will start interrupt regardless of I
        // Store PC and status registers on stack
        // Load PCL from FFFA and PCH from FFFB
        // 
    }

    void SO() {
        // Set overflow flag in status register
    }


private:
    uint8_t PCL() const {
        return PC & 0x00ff;
    }
    uint8_t PCH() const {
        return PC & 0xff00;
    }

    enum class AM {
        // AddressingMode
        Accum,
        IMM,
        Absolute,
        ZP,
        ZP_X,
        ZP_Y,
        ABS_X,
        ABS_Y,
        Implied,
        Relative,
        IND_X,
        IND_Y,
        Indirect
    };

    uint16_t PC;
    uint8_t X;  // Index register
    uint8_t Y;  // Index register
    uint8_t SP; // Stack pointer
    struct StatusRegister {
        uint8_t N : 1; // Negative (1=negative)
        uint8_t V : 1; // Overflow (1=true)
        uint8_t   : 1;
        uint8_t B : 1; // BRK Command (1=BRK)
        uint8_t D : 1; // Decimal Mode (1=true)
        uint8_t I : 1; // IRQ Disable (1=Disable)
        uint8_t Z : 1; // Zero (1=Result zero)
        uint8_t C : 1; // Carry (1=true)
    };
    uint8_t SR; // Processor status register
    uint8_t A;  // Accumulator 
    
    struct Op {
        std::function<
    };

    struct BRK {
        // Force break
        AM mode{AM::Implied};
        uint8_t cycles{7};
        uint8_t instruction_bytes{1};
        uint8_t address{0x00};
    };
    struct ORA {
        // "OR" memory with accumulator
        AM mode{AM::IND_X};
        uint8_t cycles{6};
        uint8_t instruction_bytes{2};
        uint8_t address{0x01};
    };
    struct 
};