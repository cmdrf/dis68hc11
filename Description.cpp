#include "Description.h"
#include "Opcodes.h"

const char* Description(uint8_t op)
{
	switch(op)
	{
	case OP_ABA: return "Add Accumulator B to Accumulator A";
	case OP_BCS: return "Branch if Carry Set";
	case OP_BEQ: return "Branch if Equal";
	case OP_BHI: return "Branch if Higher";
	case OP_BNE: return "Branch if Not Equal to Zero";
	case OP_CLI: return "Clear Interrupt Mask";
	case OP_CMPA_DIR: return "Compare A, direct";
	case OP_CPX_DIR: return "Compare X to Memory 16-Bit, direct";
	case OP_CPX_EXT: return "Compare X to Memory 16-Bit, extended";
	case OP_CPX_IMM: return "Compare X to Memory 16-Bit, immediate";
	case OP_CPX_IND: return "Compare X to Memory 16-Bit, indexed";
	case OP_EORA_DIR: return "Exclusive OR, direct";
	case OP_EORA_EXT: return "Exclusive OR, extended";
	case OP_EORA_IMM: return "Exclusive OR, immediate";
	case OP_EORA_IND_X: return "Exclusive OR, indexed";
	case OP_INS: return "Increment Stack Pointer";
	case OP_INX: return "Increment Index Register X";
	case OP_JSR_EXT: return "Jump to Subroutine, extended";
	case OP_JSR_IND: return "Jump to Subroutine, indexed";
	case OP_LDAA_DIR: return "Load Accumulator A, direct";
	case OP_LDAA_IMM: return "Load Accumulator A, immediate";
	case OP_LDAA_EXT: return "Load Accumulator A, extended";
	case OP_LDS_DIR: return "Load Stack Pointer, direct";
	case OP_LDS_EXT: return "Load Stack Pointer, extended";
	case OP_LDS_IMM: return "Load Stack Pointer, immediate";
	case OP_ORAA_DIR: return "Inclusive OR accumulator A, direct";
	case OP_ORAA_IMM: return "Inclusive OR accumulator A, immediate";
	case OP_PULX: return "Pull Index Register X from Stack";
	case OP_RTS: return "Return from Subroutine";
	case OP_STAA_DIR: return "Store Accumulator A, direct";
	case OP_STAA_EXT: return "Store Accumulator A, extended";
	case OP_STAA_IND_X: return "Store Accumulator A, indexed X";
	case OP_STAB_DIR: return "Store Accumulator B, direct";
	case OP_STAB_EXT: return "Store Accumulator B, extended";
	case OP_STAB_IND_X: return "Store Accumulator B, indexed X";
	case OP_STX_DIR: return "Store Index Register X, immediate";
	case OP_STX_EXT: return "Store Index Register X, extended";
	case OP_STX_IND: return "Store Index Register X, indexed";
	case OP_TSX: return "Transfer Stack Pointer to X";

	default:
		return "";
	}
}
