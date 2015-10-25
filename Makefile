#########################
## Makefile for MPA
#########################
version := 0.1
name    := Unorganized Walruscide

.PHONY: clean mpa debug install install-debug
clean:
	rm -f mpa mpa-debug
  
mpa: 
	gcc mpa.c -O3 -g0 -o mpa
  
debug: 
	gcc mpa.c -g3 -Og -o mpa-debug

install:
	sudo mkdir -p /usr/local/bin
	sudo cp mpa /usr/bin/mpa
install-debug:
	sudo mkdir -p /usr/local/bin
	sudo cp mpa-debug /usr/bin/mpa
