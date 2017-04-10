#include <iostream>
#include <sstream>
#include "Opcodes.h"
#include <stdio.h>
#include <vector>

const char* Mnenomic(uint8_t op)
{
	switch(op)
	{
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
		return "CPX";

	case OP_DECA: return "DECA";
	case OP_DECB: return "DECB";
	case OP_DES: return "DES";
	case OP_DEX: return "DEX";

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

//	case OP_LSL_EXT:
//	case OP_LSL_IND_X:
//		return "LSL";
	case OP_LSR_EXT:
	case OP_LSR_IND_X:
		return "LSR";

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
	case OP_PULB: return "PULY";
	case OP_PULX: return "PULX";
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

	case OP_STAA_DIR:
	case OP_STAA_EXT:
	case OP_STAA_IND_X:
		return "STAA";

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

	case OP_TSX: return "TSX";

	default:
		return "Unkown";
	}
}

const char* MnenomicPage1(uint8_t op)
{
	switch(op)
	{
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
		return "Unknown";
	}
}

std::string AddressString(uint16_t addr)
{
	switch(addr)
	{
	case 0x1000: return "PORTA";
	case 0x1003: return "PORTC";
	case 0x1004: return "PORTB";
	case 0x1008: return "PORTD";
	case 0x1009: return "DDRD";
	case 0x1028: return "SPCR";
	case 0x1029: return "SPSR";
	case 0x102b: return "BAUD";
	case 0x102c: return "SCCR1";
	case 0x102d: return "SCCR2";
	case 0x1030: return "ADCTL";
	case 0x1031: return "ADR1";
	case 0x1032: return "ADR2";
	case 0x1033: return "ADR3";
	case 0x1034: return "ADR4";
	case 0x1039: return "OPTION";
	case 0x103a: return "COPRST";
	case 0x103f: return "CONFIG";
	}
	std::ostringstream oss;
	oss << "$";
	oss.width(4);
	oss.fill('0');
	oss << std::hex << addr;
	return oss.str();
}

void Page1(const uint8_t* data, unsigned int& pc)
{
	uint8_t op = data[pc];
	switch(op)
	{

	// Inherent:
	case OP_DEY:
	case OP_INY:
		std::cout << MnenomicPage1(op);
		break;

	// Direct:
	case OP_STY_DIR:
		std::cout << MnenomicPage1(op) << "\t#" << std::hex << (int)data[++pc];
		break;

	// Immediate two byte:
	case OP_LDY_IMM:
	case OP_CPY_IMM:
	{
		uint8_t p0 = data[++pc];
		uint8_t p1 = data[++pc];
		uint16_t value = (uint16_t(p0) << 8) | p1;
		std::cout << MnenomicPage1(op) << "\t#$" << std::hex << value;
	}
		break;

		// Indexed:
	case OP_STAA_IND_Y:
	case OP_LDAA_IND_Y:
	{
		std::cout << MnenomicPage1(op);
		uint8_t p = data[++pc];
		if(p != 0)
			std::cout << '\t' << std::dec << p << ",Y";
		else
			std::cout << "\tY";
	}
		break;

	default:
		{
			std::ostringstream oss;
			oss << std::hex << int(data[pc]);
			throw std::runtime_error("Unknown opcode in page 1: " + oss.str());
		}
	}
}

void Page0(const uint8_t* data, unsigned int& pc)
{
	uint8_t op = data[pc];
	switch(op)
	{
	// No parameter:
	case OP_ASLA:
	case OP_ASLB:
	case OP_ASLD:
	case OP_ASRA:
	case OP_ASRB:
	case OP_CLI:
	case OP_CLRA:
	case OP_CLRB:
	case OP_CLV:
	case OP_DECA:
	case OP_DECB:
	case OP_DES:
	case OP_DEX:
	case OP_INX:
	case OP_LSRA:
	case OP_LSRB:
	case OP_LSRD:
	case OP_MUL:
	case OP_PSHA:
	case OP_PSHB:
	case OP_PSHX:
	case OP_PULA:
	case OP_PULB:
	case OP_PULX:
	case OP_RTS:
	case OP_SBA:
	case OP_TSX:
		std::cout << Mnenomic(op);
		break;

	// Immediate one byte:
	case OP_ADDA_IMM:
	case OP_ADDB_IMM:
	case OP_ANDA_IMM:
	case OP_CMPA_IMM:
	case OP_CMPB_IMM:
	case OP_EORA_IMM:
	case OP_EORB_IMM:
	case OP_LDAA_IMM:
	case OP_LDAB_IMM:
	case OP_ORAA_IMM:
		std::cout << Mnenomic(op) << "\t#" << std::hex << (int)data[++pc];
		break;

	// One byte parameter:
	case OP_ADDB_DIR:
	case OP_ANDA_DIR:
	case OP_ANDB_DIR:
	case OP_BCS:
	case OP_BEQ:
	case OP_BGE:
	case OP_BGT:
	case OP_BHI:
	case OP_BHS:
	case OP_BLE:
//	case OP_BLO:
	case OP_BLS:
	case OP_BLT:
	case OP_BMI:
	case OP_BNE:
	case OP_BPL:
	case OP_BRA:
	case OP_CMPA_DIR:
	case OP_LDAA_DIR:
	case OP_LDAB_DIR:
	case OP_ORAA_DIR:
	case OP_ORAB_DIR:
	case OP_STAA_IND_X:
	case OP_STAA_DIR:
	case OP_STAB_DIR:
	case OP_STX_DIR:
	case OP_SUBA_DIR:
	case OP_SUBB_DIR:
		std::cout << Mnenomic(op) << '\t' << std::dec << (int)data[++pc];
		break;

		// Immediate two byte:
	case OP_LDX_IMM:
	case OP_LDS_IMM:
	case OP_CPX_IMM:
	{
		uint8_t p0 = data[++pc];
		uint8_t p1 = data[++pc];
		uint16_t value = (uint16_t(p0) << 8) | p1;
		std::cout << Mnenomic(op) << "\t#$" << std::hex << value;
	}
		break;
		// Two byte parameter:
	case OP_CLR_EXT:
	case OP_INC_EXT:
	case OP_JMP_EXT:
	case OP_JSR_EXT:
	case OP_LDAA_EXT:
	case OP_LDX_EXT:
	case OP_LSR_EXT:
	case OP_STAA_EXT:
		{
			uint8_t p0 = data[++pc];
			uint8_t p1 = data[++pc];
			uint16_t addr = (uint16_t(p0) << 8) | p1;
			std::cout << Mnenomic(op) << "\t" << AddressString(addr);
		}
	break;

		// Indexed:
	case OP_CLR_IND:
	case OP_CMPA_IND_X:
	case OP_INC_IND_X:
	case OP_LDX_IND:
	case OP_LDAA_IND_X:
	case OP_LDAB_IND_X:
	case OP_SUBA_IND_X:
	case OP_SUBB_IND_X:
	{
		std::cout << Mnenomic(op);
		uint8_t p = data[++pc];
		if(p != 0)
			std::cout << '\t' << std::dec << int(p) << ",Y";
		else
			std::cout << "\tY";
	}
		break;


	case 0x18:
		pc++;
		Page1(data, pc);
		break;


	default:
		{
			std::ostringstream oss;
			oss << std::hex << int(data[pc]);
			throw std::runtime_error("Unknown opcode " + oss.str());
		}
	}
}

void Loop(const uint8_t* data, unsigned int pc)
{
	while(true)
	{
		std::cout << "$";
		std::cout.width(4);
		std::cout.fill('0');
		std::cout << std::hex << pc + 0xe000 << '\t';

		Page0(data, pc);
		std::cout << std::endl;
		pc++;
	}
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cerr << "Usage: dis68hc11 <binary file>\n";
		return EXIT_FAILURE;
	}
	FILE* inFile = fopen(argv[1], "rb");
	if(!inFile)
	{
		std::cerr << "Could not open file\n";
		return EXIT_FAILURE;
	}
	fseek(inFile, 0, SEEK_END);
	size_t length = ftell(inFile);
	fseek(inFile, 0, SEEK_SET);
	std::vector<uint8_t> fileData(length);
	fread(fileData.data(), 1, length, inFile);

	try
	{
		Loop(fileData.data(), 0x1f7);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		fclose(inFile);
		return 1;
	}
	fclose(inFile);
	return 0;
}
