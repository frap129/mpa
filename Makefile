#########################
## Makefile for MPA
#########################
version := 0.1
name    := Unorganized Walruscide

ifndef BUILD_USE_CLANG
  CC := gcc
else
  CC:= clang
endif

.PHONY: clean mpa debug install
clean:
  rm -f mpa mpa-debug
  
mpa: 
  $(CC) mpa.c -O3 -g0 -o mpa
  
debug: 
  $(CC) mpa.c -g3 -Og -o mpa-debug

install:
  sudo mkdir -p /usr/local/bin
  sudo cp mpa /usr/bin/mpa
