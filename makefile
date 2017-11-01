finalProject: Parser.o main.o
	g++ -g -Wall -o finalProject Parser.o main.o

Parser.o: Parser.h
	g++ -Wall -Wno-deprecated -g -c Parser.cpp

main.o: Parser.h
	g++ -Wall -Wno-deprecated -g -c main.cpp
clean:
	/bin/rm -f *.o finalProject
