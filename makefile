finalProject: Parser.o ALU.o ALUControl.o BinaryOperations.o DataMemory.o ProgramCounter.o Register.o RegisterParser.o SignExtend.o controlUnit.o 
	g++ -g -Wall -o finalProject Parser.o ALU.o ALUControl.o BinaryOperations.o DataMemory.o ProgramCounter.o Register.o RegisterParser.o SignExtend.o controlUnit.o 



Parser.o: Parser.h

	g++ -Wall -Wno-deprecated -g -c Parser.cpp


ALU.o: ALU.h
	g++ -Wall -Wno-deprecated -g -c ALU.cpp

ALUControl.o: ALUControl.h
	g++ -Wall -Wno-deprecated -g -c ALUControl.cpp

BinaryOperations.o: BinaryOperations.h
	g++ -Wall -Wno-deprecated -g -c BinaryOperations.cpp

DataMemory.o: DataMemory.h
	g++ -Wall -Wno-deprecated -g -c DataMemory.cpp

ProgramCounter.o: ProgramCounter.h
	g++ -Wall -Wno-deprecated -g -c ProgramCounter.cpp

Register.o: Register.h
	g++ -Wall -Wno-deprecated -g -c Register.cpp

RegisterParser.o: RegisterParser.h
	g++ -Wall -Wno-deprecated -g -c RegisterParser.cpp

SignExtend.o: SignExtend.h
	g++ -Wall -Wno-deprecated -g -c SignExtend.cpp

controlUnit.o: controlUnit.h
	g++ -Wall -Wno-deprecated -g -c controlUnit.cpp

clean:

	/bin/rm -f *.o finalProject