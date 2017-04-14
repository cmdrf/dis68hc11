#include "Description.h"
#include "Opcodes.h"

const char* Description(uint8_t op)
{
	switch(op)
	{
	case OP_ABA: return "Add Accumulator B to Accumulator A";
	case OP_ABX: return "Add B to X";
	case OP_ADCB_DIR: return "Add with carry to B, direct";
	case OP_ADCB_EXT: return "Add with carry to B, extended";
	case OP_ADCB_IMM: return "Add with carry to B, immediate";
	case OP_ADCB_IND_X: return "Add with carry to B, indexed";
	case OP_ANDA_DIR: return "AND A with Memory, direct";
	case OP_ANDA_EXT: return "AND A with Memory, extended";
	case OP_ANDA_IMM: return "AND A with Memory, immediate";
	case OP_ANDA_IND_X: return "AND A with Memory, indexed";
	case OP_ANDB_DIR: return "AND B with Memory, direct";
	case OP_ANDB_EXT: return "AND B with Memory, extended";
	case OP_ANDB_IMM: return "AND B with Memory, immediate";
	case OP_ANDB_IND_X: return "AND B with Memory, indexed";
	case OP_ASLA: return "Arithmetic Shift Left A";
	case OP_ASLB: return "Arithmetic Shift Left B";
	case OP_BCS: return "Branch if Carry Set";
	case OP_BEQ: return "Branch if Equal";
	case OP_BHI: return "Branch if Higher";
	case OP_BNE: return "Branch if Not Equal to Zero";
	case OP_CLI: return "Clear Interrupt Mask";
	case OP_CLRA: return "Clear Accumulator A";
	case OP_CLRB: return "Clear Accumulator B";
	case OP_CMPA_DIR: return "Compare A, direct";
	case OP_CPX_DIR: return "Compare X to Memory 16-Bit, direct";
	case OP_CPX_EXT: return "Compare X to Memory 16-Bit, extended";
	case OP_CPX_IMM: return "Compare X to Memory 16-Bit, immediate";
	case OP_CPX_IND: return "Compare X to Memory 16-Bit, indexed";
	case OP_DEX: return "Decrement Index Register X";
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
	case OP_LSR_EXT: return "Logical Shift Right, extended";
	case OP_LSR_IND_X: return "Logical Shift Right, indexed";
	case OP_LSRA: return "Logical Shift Right A";
	case OP_LSRB: return "Logical Shift Right B";
	case OP_LSRD: return "Logical Shift Right D";
	case OP_ORAA_DIR: return "Inclusive OR accumulator A, direct";
	case OP_ORAA_IMM: return "Inclusive OR accumulator A, immediate";
	case OP_ORAA_IND_X: return "Inclusive OR accumulator A, indexed";
	case OP_PULX: return "Pull Index Register X from Stack";
	case OP_ROLB: return "Rotate Left B";
	case OP_RTS: return "Return from Subroutine";
	case OP_SBA: return "Subtract B from A";
	case OP_SEI: return "Set Interrupt Mask";
	case OP_STAA_DIR: return "Store Accumulator A, direct";
	case OP_STAA_EXT: return "Store Accumulator A, extended";
	case OP_STAA_IND_X: return "Store Accumulator A, indexed";
	case OP_STAB_DIR: return "Store Accumulator B, direct";
	case OP_STAB_EXT: return "Store Accumulator B, extended";
	case OP_STAB_IND_X: return "Store Accumulator B, indexed";
	case OP_STX_DIR: return "Store Index Register X, immediate";
	case OP_STX_EXT: return "Store Index Register X, extended";
	case OP_STX_IND: return "Store Index Register X, indexed";
	case OP_TAB: return "Transfer A to B";
	case OP_TSX: return "Transfer Stack Pointer to X";
	case OP_XGDX: return "Exchange D with X";

	default:
		return "";
	}
}
