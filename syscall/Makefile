all: syscall1 helloworld_sys helloworld helloworld32.o helloworld32

helloworld32.o: helloworld32.s
	as -v --64  helloworld32.s -o helloworld32.o

helloworld32: helloworld32.o
	ld helloworld32.o -o helloworld32
