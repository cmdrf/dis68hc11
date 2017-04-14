#include "Mnenomic.h"
#include "Opcodes.h"
#include <iostream>

const char* Mnenomic(uint8_t op)
{
	switch(op)
	{
	case OP_ABA: return "ABA";
	case OP_ABX: return "ABX";

	case OP_ADCA_DIR:
	case OP_ADCA_IMM:
	case OP_ADCA_EXT:
	case OP_ADCA_IND_X:
		return "ADCA";

	case OP_ADCB_DIR:
	case OP_ADCB_IMM:
	case OP_ADCB_EXT:
	case OP_ADCB_IND_X:
		return "ADCB";

	case OP_ADDA_IMM:
	case OP_ADDA_DIR:
	case OP_ADDA_EXT:
	case OP_ADDA_IND_X:
		return "ADDA";

	case OP_ADDB_IMM:
	case OP_ADDB_DIR:
	case OP_ADDB_EXT:
	case OP_ADDB_IND_X:
		return "ADDB";

	case OP_ADDD_IMM:
	case OP_ADDD_DIR:
	case OP_ADDD_EXT:
	case OP_ADDD_IND_X:
		return "ADDD";

	case OP_ANDA_IMM:
	case OP_ANDA_DIR:
	case OP_ANDA_EXT:
	case OP_ANDA_IND_X:
		return "ANDA";

	case OP_ANDB_IMM:
	case OP_ANDB_DIR:
	case OP_ANDB_EXT:
	case OP_ANDB_IND_X:
		return "ANDB";

	case OP_ASL_EXT:
	case OP_ASL_IND_X:
		return "ASL";

	case OP_ASLA: return "ASLA";
	case OP_ASLB: return "ASLB";
	case OP_ASLD: return "ASLD";
	case OP_ASR_EXT:
	case OP_ASR_IND_X:
		return "ASR";
	case OP_ASRA: return "ASRA";
	case OP_ASRB: return "ASRB";

	case OP_BCS: return "BCS";
	case OP_BEQ: return "BEQ";
	case OP_BGE: return "BGE";
	case OP_BGT: return "BGT";
	case OP_BHI: return "BHI";
	case OP_BHS: return "BHS";

	case OP_BLE: return "BLE";
//	case OP_BLO: return "BLO";
	case OP_BLS: return "BLS";
	case OP_BLT: return "BLT";
	case OP_BMI: return "BMI";
	case OP_BNE: return "BNE";
	case OP_BPL: return "BPL";
	case OP_BRA: return "BRA";
	case OP_BVC: return "BVC";
	case OP_BVS: return "BVS";

	case OP_CMPA_IMM:
	case OP_CMPA_DIR:
	case OP_CMPA_EXT:
	case OP_CMPA_IND_X:
		return "CMPA";

	case OP_CLR_EXT:
	case OP_CLR_IND:
		return "CLR";

	case OP_CLI: return "CLI";
	case OP_CLRA: return "CLRA";
	case OP_CLRB: return "CLRB";
	case OP_CLV: return "CLV";

	case OP_CMPB_IMM:
	case OP_CMPB_DIR:
	case OP_CMPB_EXT:
	case OP_CMPB_IND_X:
		return "CMPB";

	case OP_CPX_IMM:
	case OP_CPX_DIR:
	case OP_CPX_IND:
		return "CPX";

	case OP_DECA: return "DECA";
	case OP_DECB: return "DECB";
	case OP_DES: return "DES";
	case OP_DEX: return "DEX";
	case OP_FDIV: return "FDIV";

	case OP_IDIV: return "IDIV";
	case OP_INCA: return "INCA";
	case OP_INCB: return "INCB";
	case OP_INS: return "INS";
	case OP_INX: return "INX";

	case OP_INC_EXT:
	case OP_INC_IND_X:
		return "INC";

	case OP_JMP_EXT:
	case OP_JMP_IND_X:
		return "JMP";
	case OP_JSR_DIR:
	case OP_JSR_EXT:
	case OP_JSR_IND:
		return "JSR";

	case OP_EORA_IMM:
	case OP_EORA_DIR:
	case OP_EORA_EXT:
	case OP_EORA_IND_X:
		return "EORA";

	case OP_EORB_IMM:
	case OP_EORB_DIR:
	case OP_EORB_EXT:
	case OP_EORB_IND_X:
		return "EORB";

	case OP_LDAA_IMM:
	case OP_LDAA_DIR:
	case OP_LDAA_EXT:
	case OP_LDAA_IND_X:
		return "LDAA";

	case OP_LDAB_IMM:
	case OP_LDAB_DIR:
	case OP_LDAB_EXT:
	case OP_LDAB_IND_X:
		return "LDAB";

	case OP_LDD_IMM:
	case OP_LDD_DIR:
	case OP_LDD_EXT:
	case OP_LDD_IND_X:
		return "LDD";

	case OP_LDS_IMM:
	case OP_LDS_DIR:
	case OP_LDS_EXT:
	case OP_LDS_IND:
		return "LDS";

	case OP_LDX_IMM:
	case OP_LDX_DIR:
	case OP_LDX_EXT:
	case OP_LDX_IND:
		return "LDX";

		// Duplicate opcode with ASL:
//	case OP_LSL_EXT:
//	case OP_LSL_IND_X:
//		return "LSL";

	case OP_LSR_EXT:
	case OP_LSR_IND_X:
		return "LSR";

	case OP_LSRA: return "LSRA";
	case OP_LSRB: return "LSRB";
	case OP_LSRD: return "LSRD";
	case OP_MUL: return "MUL";

	case OP_ORAA_IMM:
	case OP_ORAA_DIR:
	case OP_ORAA_EXT:
	case OP_ORAA_IND_X:
		return "ORAA";

	case OP_ORAB_IMM:
	case OP_ORAB_DIR:
	case OP_ORAB_EXT:
	case OP_ORAB_IND_X:
		return "ORAB";

	case OP_PSHA: return "PSHA";
	case OP_PSHB: return "PSHB";
	case OP_PSHX: return "PSHX";
	case OP_PULA: return "PULA";
	case OP_PULB: return "PULB";
	case OP_PULX: return "PULX";
	case OP_ROLA: return "ROLA";
	case OP_ROLB: return "ROLB";
	case OP_RORA: return "RORA";
	case OP_RORB: return "RORB";
	case OP_RTS: return "RTS";

	case OP_SBA: return "SBA";
	case OP_SBCA_IMM:
	case OP_SBCA_DIR:
	case OP_SBCA_EXT:
	case OP_SBCA_IND_X:
		return "SBCA";
	case OP_SBCB_IMM:
	case OP_SBCB_DIR:
	case OP_SBCB_EXT:
	case OP_SBCB_IND_X:
		return "SBCB";

	case OP_SEC: return "SEC";
	case OP_SEI: return "SEI";
	case OP_SEV: return "SEV";

	case OP_STAA_DIR:
	case OP_STAA_EXT:
	case OP_STAA_IND_X:
		return "STAA";

	case OP_STAB_DIR:
	case OP_STAB_EXT:
	case OP_STAB_IND_X:
		return "STAB";

	case OP_STD_DIR:
	case OP_STD_EXT:
	case OP_STD_IND_X:
		return "STD";

	case OP_STOP: return "STOP";
	case OP_STS_DIR:
//	case OP_STS_EXT: // TODO
	case OP_STS_IND_X:
		return "STS";

	case OP_STX_DIR:
	case OP_STX_EXT:
	case OP_STX_IND:
		return "STX";

	case OP_SUBA_IMM:
	case OP_SUBA_DIR:
	case OP_SUBA_EXT:
	case OP_SUBA_IND_X:
		return "SUBA";
	case OP_SUBB_IMM:
	case OP_SUBB_DIR:
	case OP_SUBB_EXT:
	case OP_SUBB_IND_X:
		return "SUBB";

	case OP_SWI: return "SWI";
	case OP_TAB: return "TAB";
	case OP_TAP: return "TAP";
	case OP_TBA: return "TBA";
	case OP_TEST: return "TEST";
	case OP_TPA: return "TPA";
	case OP_TST_EXT:
	case OP_TST_IND_X:
		return "TST";
	case OP_TSTA: return "TSTA";
	case OP_TSTB: return "TSTB";
	case OP_TSX: return "TSX";
	case OP_TXS: return "TXS";
	case OP_WAI: return "WAI";
	case OP_XGDX: return "XGDX";

	default:
		std::cerr << "op: " << std::hex << int(op) << std::endl;
		return "Unkown";
	}
}

const char* MnenomicPage1(uint8_t op)
{
	switch(op)
	{
	case OP_ABY: return "ABY";
	case OP_CPY_IMM: return "CPY";
	case OP_DEY: return "DEY";
	case OP_INY: return "INY";

	case OP_TSY:
		return "TSY";

	case OP_LDY_IMM:
		return "LDY";

	case OP_STY_DIR:
	case OP_STY_EXT:
	case OP_STY_IND_Y:
		return "STY";

	case OP_STAA_IND_Y: return "STAA";
	case OP_LDAA_IND_Y: return "LDAA";

	default:
		std::cerr << "op: " << std::hex << int(op) << std::endl;
		return "Unknown";
	}
}
