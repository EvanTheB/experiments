all: addrs judy

test: all
	< ints xargs time -v ./judy 10000 2>&1 | grep -v Command
	< ints xargs time -v ./addrs 10000 2>&1 | grep -v Command

clean:
	rm judy addrs *.gperf *.c ints

ints: generate.py
	python3 generate.py 4000 > ints

addrs.gperf: addrs.gperf.head addrs.gperf.tail ints int_to_cstr.py
	python3 int_to_cstr.py < ints | cat addrs.gperf.head - addrs.gperf.tail > addrs.gperf

addrs.c: addrs.gperf
	gperf -l addrs.gperf > addrs.c

judy.c: judy.head ints int_to_carr.py
	python3 int_to_carr.py < ints | cat judy.head - > judy.c

judy: LDLIBS += -lJudy
