# dis68hc11
Simple 68HC11 disassembler.

## Compiling

This project is built with CMake. After downloading the source code, navigate to the source directory and run:

    mkdir build
    cd build
    cmake ..
    make
    
An executable called dis68hc11 will appear inside the build directory.

## Usage

This is a command line utility. It takes an EPROM file as argument. The address of the last byte of the EPROM image is always considered to be 0xffff, with the first address adjusted to the size of the image. By default, the disassembler reads the initial program counter from addresses 0xfffe and 0xffff (the INIT interrupt). Starting from that address, it disassembles the program until it reaches an unknown opcode. This can either be a unimplemented opcode, or non-program data. To disassemble specific subroutines, use the -s argument to set a start address instead of reading it from 0xfffe and 0xffff.

## Known Issues

Not all opcodes are implemented yet, expecially rarely-used multi-byte opcodes.

## License

BSD-2-Clause. See LICENSE file for details.
