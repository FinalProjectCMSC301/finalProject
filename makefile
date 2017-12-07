finalProject: main.o Parser.o ALU.o ALUControl.o BinaryOperation.o DataMemory.o ProgramCounter.o Register.o SignExtend.o ControlUnit.o Multiplexer.o ShiftLeft.o InstructionMemory.o
	g++ -std=c++11 -g -Wall -o finalProject main.o Parser.o ShiftLeft.o ALU.o ALUControl.o BinaryOperation.o DataMemory.o ProgramCounter.o Register.o InstructionMemory.o SignExtend.o ControlUnit.o Multiplexer.o ShiftLeft.o 


main.o: Parser.h ShiftLeft.h Register.h DataMemory.h ProgramCounter.h ControlUnit.h ALU.h Multiplexer.h SignExtend.h BinaryOperation.h ALUControl.h InstructionMemory.h

Parser.o: Parser.h

	g++ -std=c++11 -Wall -Wno-deprecated -g -c Parser.cpp

ShiftLeft.o: ShiftLeft.o BinaryOperation.o
	g++ -std=c++11 -Wall -Wno-deprecated -g -c ShiftLeft.cpp

ALU.o: ALU.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c ALU.cpp

ALUControl.o: ALUControl.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c ALUControl.cpp

BinaryOperation.o: BinaryOperation.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c BinaryOperation.cpp

DataMemory.o: DataMemory.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c DataMemory.cpp

ProgramCounter.o: ProgramCounter.h BinaryOperation.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c ProgramCounter.cpp

Register.o: Register.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c Register.cpp

Multiplexer.o: Multiplexer.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c Multiplexer.cpp

SignExtend.o: SignExtend.h
	g++ -std=c++11 -Wall -Wno-deprecated -g -c SignExtend.cpp

ControlUnit.o: ControlUnit.h
	g++  -std=c++11 -Wall -Wno-deprecated -g -c ControlUnit.cpp
	
InstructionMemory.o: InstructionMemory.h
	g++  -std=c++11 -Wall -Wno-deprecated -g -c InstructionMemory.cpp

clean:

	/bin/rm -f *.o finalProject
