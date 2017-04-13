#ifndef OPCODES_H
#define OPCODES_H

enum Opcodes
{
	OP_ABA = 0x1b,

	OP_ADDA_IMM = 0x8b,
	OP_ADDA_DIR = 0x9b,
	OP_ADDA_EXT = 0xbb,
	OP_ADDA_IND_X = 0xab,

	OP_ADDB_IMM = 0xcb,
	OP_ADDB_DIR = 0xdb,
	OP_ADDB_EXT = 0xfb,
	OP_ADDB_IND_X = 0xeb,

	OP_ANDA_IMM = 0x84,
	OP_ANDA_DIR = 0x94,
	OP_ANDA_EXT = 0xb4,
	OP_ANDA_IND_X = 0xa4,

	OP_ANDB_IMM = 0xc4,
	OP_ANDB_DIR = 0xd4,
	OP_ANDB_EXT = 0xf4,
	OP_ANDB_IND_X = 0xe4,

	OP_ASL_EXT = 0x78,
	OP_ASL_IND_X = 0x68,
	OP_ASLA = 0x48,
	OP_ASLB = 0x58,
	OP_ASLD = 0x05,
	OP_ASR_EXT = 0x77,
	OP_ASR_IND_X = 0x67,
	OP_ASRA = 0x47,
	OP_ASRB = 0x57,

	OP_BCC = 0x24,
	OP_BCS = 0x25,
	OP_BEQ = 0x27,
	OP_BGE = 0x2c,
	OP_BGT = 0x2e,
	OP_BHI = 0x22,
	OP_BHS = 0x24,

	OP_BLE = 0x2f,
	OP_BLO = 0x25, ///< Branch if Lower, same as BCS
	OP_BLS = 0x23,
	OP_BLT = 0x2d,
	OP_BMI = 0x2b,
	OP_BNE = 0x26,
	OP_BPL = 0x2a,
	OP_BRA = 0x20,
	OP_BRN = 0x21, ///< Branch Never
	OP_BRSET_DIR = 0x12, ///< Branch if Bit(s) Set, direct
	OP_BRSET_IND_X = 0x1e, ///< Branch if Bit(s) Set, indirect
	OP_BSR = 0x8d, ///< Branch to Subroutine

	OP_CLI = 0x0e,
	OP_CLRA = 0x4f,
	OP_CLRB = 0x5f,
	OP_CLV = 0x0a,

	OP_CLR_EXT = 0x7f,
	OP_CLR_IND = 0x6f,

	OP_CMPA_IMM = 0x81,
	OP_CMPA_DIR = 0x91,
	OP_CMPA_EXT = 0xb1,
	OP_CMPA_IND_X = 0xa1,

	OP_CMPB_IMM = 0xc1,
	OP_CMPB_DIR = 0xd1,
	OP_CMPB_EXT = 0xf1,
	OP_CMPB_IND_X = 0xe1,

	OP_CPX_IMM = 0x8c,
	OP_CPX_DIR = 0x9c,
	OP_CPX_EXT = 0xbc,
	OP_CPX_IND = 0xac,

	OP_DECA = 0x4a,
	OP_DECB = 0x5a,
	OP_DES = 0x34,
	OP_DEX = 0x09,

	OP_EORA_IMM = 0x88,
	OP_EORA_DIR = 0x98,
	OP_EORA_EXT = 0xb8,
	OP_EORA_IND_X = 0xa8,
	OP_EORB_IMM = 0xc8,
	OP_EORB_DIR = 0xd8,
	OP_EORB_EXT = 0xf8,
	OP_EORB_IND_X = 0xe8,

	OP_INC_EXT = 0x7c,
	OP_INC_IND_X = 0x6c,
	OP_INCA = 0x4c,
	OP_INCB = 0x5c,
	OP_INS = 0x31,
	OP_INX = 0x08,

	OP_JMP_EXT = 0x7e,
	OP_JMP_IND_X = 0x6e,

	OP_JSR_DIR = 0x9d,
	OP_JSR_EXT = 0xbd,
	OP_JSR_IND = 0xad,

	OP_LDAA_IMM = 0x86,
	OP_LDAA_DIR = 0x96,
	OP_LDAA_EXT = 0xb6,
	OP_LDAA_IND_X = 0xa6,

	OP_LDAB_IMM = 0xc6,
	OP_LDAB_DIR = 0xd6,
	OP_LDAB_EXT = 0xbf,
	OP_LDAB_IND_X = 0xe6,

	OP_LDS_IMM = 0x8e,
	OP_LDS_DIR = 0x9e,
	OP_LDS_EXT = 0xbe,
	OP_LDS_IND = 0xae,

	OP_LDX_IMM = 0xce,
	OP_LDX_DIR = 0xde,
	OP_LDX_EXT = 0xfe,
	OP_LDX_IND = 0xee,

	OP_LSL_EXT = 0x78,
	OP_LSL_IND_X = 0x68,
	OP_LSR_EXT = 0x74,
	OP_LSR_IND_X = 0x64,
	OP_LSRA = 0x44,
	OP_LSRB = 0x54,
	OP_LSRD = 0x04,
	OP_MUL = 0x3d,

	OP_ORAA_IMM = 0x8a,
	OP_ORAA_DIR = 0x9a,
	OP_ORAA_EXT = 0xba,
	OP_ORAA_IND_X = 0xaa,
	OP_ORAB_IMM = 0xca,
	OP_ORAB_DIR = 0xda,
	OP_ORAB_EXT = 0xfa,
	OP_ORAB_IND_X = 0xea,

	OP_PSHA = 0x36,
	OP_PSHB = 0x37,
	OP_PSHX = 0x3c,
	OP_PULA = 0x32,
	OP_PULB = 0x33,
	OP_PULX = 0x38,

	OP_RTS = 0x39,

	OP_SBA = 0x10,
	OP_SBCA_IMM = 0x82,
	OP_SBCA_DIR = 0x92,
	OP_SBCA_EXT = 0xb2,
	OP_SBCA_IND_X = 0xa2,
	OP_SBCB_IMM = 0xc2,
	OP_SBCB_DIR = 0xd2,
	OP_SBCB_EXT = 0xf2,
	OP_SBCB_IND_X = 0xe2,

	OP_SEC = 0x0d,
	OP_SEI = 0x0f,
	OP_SEV = 0x0b,

	OP_STAA_DIR = 0x97,
	OP_STAA_EXT = 0xb7,
	OP_STAA_IND_X = 0xa7,

	OP_STAB_DIR = 0xd7,
	OP_STAB_EXT = 0xf7,
	OP_STAB_IND_X = 0xe7,

	OP_STD_DIR = 0xdd,
	OP_STD_EXT = 0xfd,
	OP_STD_IND_X = 0xed,

	OP_STOP = 0xcf,
	OP_STS_DIR = 0x9f,
	OP_STS_EXT = 0xbf,
	OP_STS_IND_X = 0xaf,

	OP_STX_DIR = 0xdf,
	OP_STX_EXT = 0xff,
	OP_STX_IND = 0xef,

	OP_SUBA_IMM = 0x80,
	OP_SUBA_DIR = 0x90,
	OP_SUBA_EXT = 0xb0,
	OP_SUBA_IND_X = 0xa0,
	OP_SUBB_IMM = 0xc0,
	OP_SUBB_DIR = 0xd0,
	OP_SUBB_EXT = 0xf0,
	OP_SUBB_IND_X = 0xe0,
	OP_SUBD_IMM = 0x83,
	OP_SUBD_DIR = 0x93,
	OP_SUBD_EXT = 0xb3,
	OP_SUBD_IND_X = 0xa3,

	OP_SWI = 0x3f,
	OP_TAB = 0x16,
	OP_TAP = 0x06,
	OP_TBA = 0x17,
	OP_TEST = 0,
	OP_TPA = 0x07,
	OP_TST_EXT = 0x7d,
	OP_TST_IND_X = 0x6d,
	OP_TSTA = 0x4d,
	OP_TSTB = 0x5d,
	OP_TSX = 0x30,
	OP_TXS = 0x35,
	OP_WAI = 0x3e,
	OP_XGDX = 0x8f,

	// Page 1:
	OP_CPY_IMM = 0x8c,
	OP_DEY = 0x09,

	OP_INY = 0x08,

	OP_LDAA_IND_Y = 0xa6,

	OP_LDY_IMM = 0xce,
	OP_LDY_DIR = 0xde,
	OP_LDY_EXT = 0xfe,
	OP_LDY_IND_Y = 0xee,

	OP_STAA_IND_Y = 0xa7,

	OP_STY_DIR = 0xdf,
	OP_STY_EXT = 0xff,
	OP_STY_IND_Y = 0xef,
	OP_TSY = 0x30,
};

#endif // OPCODES_H
