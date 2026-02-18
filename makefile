students: main.o date.o address.o students.o
	g++ -g main.o date.o address.o students.o  -o students
	
main.o: main.cpp date.h address.h students.h
	g++ -g -c main.cpp

date.o: date.cpp date.h
	g++ -g -c date.cpp

address.o: address.cpp address.h
	g++ -g -c address.cpp

students.o: students.cpp students.h
	g++ -g -c students.cpp

run: students
	./students

clean: 
	rm students
	rm *.o

debug: students
	gdb students

valgrind: students
	valgrind --leak-check=full ./students
