all: loops recursives recursived loopd mains maindloop maindrec

# object
basicClassification.o: basicClassification.c
	gcc -c basicClassification.c -o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -c advancedClassificationLoop.c -o advancedClassificationLoop.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

# shared objects
basicClassificationShared.o: basicClassification.c
	gcc -c basicClassification.c -o basicClassificationShared.o -fPIC

advancedClassificationLoopShared.o: advancedClassificationLoop.c
	gcc -c advancedClassificationLoop.c -o advancedClassificationLoopShared.o -fPIC

advancedClassificationRecursionShared.o: advancedClassificationRecursion.c
	gcc -c advancedClassificationRecursion.c -o advancedClassificationRecursionShared.o -fPIC

# static libs
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

# dynamic libs
libclassrec.so: basicClassificationShared.o advancedClassificationRecursionShared.o
	gcc -shared basicClassificationShared.o advancedClassificationRecursionShared.o -o libclassrec.so

libclassloops.so: basicClassificationShared.o advancedClassificationLoopShared.o
	gcc -shared basicClassificationShared.o advancedClassificationLoopShared.o -o libclassloops.so

# library targets
loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

# programs
mains: main.c libclassrec.a
	gcc -Wl,-R . main.c -L. -lclassrec -o mains -lm

maindloop: main.c libclassloops.so
	gcc -Wl,-R . main.c -L. -lclassloops -o maindloop -lm

maindrec: main.c libclassrec.so
	gcc -Wl,-R . main.c -L. -lclassrec -o maindrec -lm

clean:
	rm mains maindloop maindrec *.a *.so *.o