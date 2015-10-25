#########################
## Makefile for MPA
#########################
version := 0.2
name    := Unorganized Walruscide

# Environment Variables
local_flags := $(CFLAGS) $(cflags)
ifdef CC
  local_cc := $(CC)
else
  local_cc := gcc
endif

.PHONY: clean mpa debug install install-debug
clean:
	@rm -f mpa mpa-debug $<
	@echo "Build files removed!" $<
  
mpa: 
	@echo "Compiling..." $<
	@echo "" $<
	@$(local_cc) mpa.c -O3 -g0 $(local_flags) -o mpa $<
	@echo "Done! Final Binary: ./mpa" $<
  
debug: 
	@echo "Compiling..." $<
	@echo "" $<
	@$(local_cc) mpa.c -g3 -Og $(local_flags) -o mpa-debug $<
	@echo "Done! Final Binary: ./mpa-debug" $<

install:
	@echo "Installing.." $<
	@echo "" $<
	@sudo mkdir -p /usr/local/bin $<
	@sudo cp mpa /usr/bin/mpa $<
	@echo "Done!" $<
	
install-debug:
	@echo "Installing..." $<
	@echo "" $<
	@sudo mkdir -p /usr/local/bin $<
	@sudo cp mpa-debug /usr/bin/mpa $<
	@echo "Done!" $<
