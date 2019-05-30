CFLAGS=-Wall -ansi -std=c11
LDFLAGS=

Score_H_DEP=Sources/Score.h
Utils_H_DEP=Sources/Utils.h
Test_H_DEP=Sources/Test.h
Assignment_H_DEP=Sources/Assignment.h ${Score_H_DEP} ${Test_H_DEP}
Category_H_DEP=Sources/Category.h ${Score_H_DEP} ${Assignment_H_DEP}
Unit_H_DEP=Sources/Unit.h ${Category_H_DEP} ${Assignment_H_DEP}
Evaluation_H_DEP=Sources/Evaluation.h ${Category_H_DEP} ${Assignment_H_DEP}

Score_C_DEP=${Score_H_DEP}
Utils_C_DEP=${Utils_H_DEP}
Test_C_DEP=${Test_H_DEP} ${Utils_H_DEP}
Assignment_C_DEP=${Assignment_H_DEP} ${Utils_H_DEP}
Category_C_DEP=${Category_H_DEP} ${Utils_H_DEP} ${Unit_H_DEP}
Unit_C_DEP=${Unit_H_DEP}
Evaluation_C_DEP=${Evaluation_H_DEP} ${Unit_H_DEP} ${Score_H_DEP} ${Utils_H_DEP}
Tests_C_DEP=${Evaluation_H_DEP} ${Assignment_H_DEP} ${Category_H_DEP}

LIB_OBJECTS=Objects/Score.o Objects/Utils.o Objects/Test.o Objects/Assignment.o Objects/Category.o Objects/Unit.o Objects/Evaluation.o
TESTS_OBJECTS=Objects/Tests.o

TARGET=Library/Evaluation.a
TESTS=Bin/Tests


all: ${TARGET}

tests: ${TESTS}

Objects:
	mkdir Objects

Objects/Score.o: Sources/Score.c ${Score_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Objects/Utils.o: Sources/Utils.c ${Utils_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Objects/Test.o: Sources/Test.c ${Test_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Objects/Assignment.o: Sources/Assignment.c ${Assignment_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Objects/Category.o: Sources/Category.c ${Category_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Objects/Unit.o: Sources/Unit.c ${Unit_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Objects/Evaluation.o: Sources/Evaluation.c ${Evaluation_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Objects/Tests.o: Tests/Tests.c ${Tests_C_DEP}
	gcc -o $@ -c $< ${CFLAGS}

Library:
	mkdir Library

Library/Evaluation.a: Objects ${LIB_OBJECTS} Library
	ar rcs $@ ${LIB_OBJECTS}

Bin:
	mkdir Bin

Bin/Tests: Library/Evaluation.a ${TESTS_OBJECTS} Bin
	gcc -o $@ ${TESTS_OBJECTS} ${TARGET} 

clean:
	rm -f ${TARGET} ${TESTS} ${LIB_OBJECTS} ${TESTS_OBJECTS}
