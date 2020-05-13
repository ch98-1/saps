SAPS
==========

Small ARM-Like Processor Simulator. Processor simulator/emulator that can simulate a small 16 bit processor with 16 words regfile, a 64k-word Instruction Memory, and 64k-word Data Meory.   

Usage:   
saps <cpu type id number> <number of cycles to simulate> <register file input/output file directiry> <Instruction Memory input/output file directiry> <Data Memory input/output file directiry>    

all input files must be hex with 1 element per line   

CPU type ID's:   
0: Standard baseline cpu. Not implemented yet   
1: Standard cpu with 4 bit Rd for MOV and MOVS   
