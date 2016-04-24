all: RSA_Function.o RSA_main_1.0.o
	gcc RSA_Function.o RSA_main_1.0.o -o RSA2.0 -lm

RSA_Function.o: RSA_Function.c
	gcc -c RSA_Function.c -o RSA_Function.o -std=c99 

RSA_main_1.0.o: RSA_main_1.0.c
	gcc -c RSA_main_1.0.c -o RSA_main_1.0.o -std=c99

clean: 
	rm -f  *.o
	rm -f RSA2.0

uninstall:RSA_Function.o RSA_main_1.0.o
	gcc RSA_Function.o RSA_main_1.0.o -o RSA2.0
	rm -f *.o
	rm -f *.c
	rm -f *.h
