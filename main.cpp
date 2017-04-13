#include <iostream>
#include <sstream>
#include "Opcodes.h"
#include "Mnenomic.h"
#include "Description.h"
#include <stdio.h>
#include <vector>

std::string AddressString(uint16_t addr)
{
	switch(addr)
	{
	case 0x1000: return "PORTA";
	case 0x1002: return "PIOC";
	case 0x1003: return "PORTC";
	case 0x1004: return "PORTB";
	case 0x1005: return "PORTCL";
	case 0x1006: return "DDRC";
	case 0x1008: return "PORTD";
	case 0x1009: return "DDRD";
	case 0x100b: return "CFORC";
	case 0x100c: return "OC1M";
	case 0x100d: return "OC1D";
	case 0x1020: return "TCTL1";
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
	case 0x103b: return "PPROG";
	case 0x103c: return "HPRIO";
	case 0x103d: return "INIT";
	case 0x103e: return "TEST1";
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

void Page0(const uint8_t* data, unsigned int& pc, unsigned int epromStart)
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
		std::cout << Mnenomic(op) << '\t';
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

	// Direct:
	case OP_ADDB_DIR:
	case OP_ANDA_DIR:
	case OP_ANDB_DIR:
	case OP_CMPA_DIR:
	case OP_LDAA_DIR:
	case OP_LDAB_DIR:
	case OP_ORAA_DIR:
	case OP_ORAB_DIR:
	case OP_STAA_DIR:
	case OP_STAB_DIR:
	case OP_STX_DIR:
	case OP_SUBA_DIR:
	case OP_SUBB_DIR:
		std::cout << Mnenomic(op) << '\t' << std::dec << (int)data[++pc];
		break;

		// Relative (signed):
	case OP_BCC:
	case OP_BCS:
	case OP_BEQ:
	case OP_BGE:
	case OP_BGT:
	case OP_BHI:
//	case OP_BHS: // Same as BCC
//	case OP_BLO:
	case OP_BLS:
	case OP_BLE:
	case OP_BLT:
	case OP_BMI:
	case OP_BNE:
	case OP_BPL:
	case OP_BRA:
	{
		// calculate destination address:
		int offset = int8_t(data[++pc]);
		std::cout << Mnenomic(op) << "\t$" << std::hex << pc + offset + 1 + epromStart;
	}
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
		// Extended (two byte) parameter:
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
	case OP_STAA_IND_X:
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

void Disassemble(const uint8_t data[], unsigned int length)
{
	unsigned int epromStart = 0xffff - length + 1;
	uint8_t fffe = data[length - 2];
	uint8_t ffff = data[length - 1];
	unsigned int pc = ((uint16_t(fffe) << 8) | ffff) - epromStart;
	while(pc < length)
	{
		std::cout << "$";
		std::cout.width(4);
		std::cout.fill('0');
		std::cout << std::hex << pc + epromStart << ":\t";

		uint8_t op = data[pc];
		Page0(data, pc, epromStart);
		std::cout << "\t; " << Description(op) << std::endl;
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
		Disassemble(fileData.data(), fileData.size());
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
