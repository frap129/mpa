#########################
## Makefile for MPA
#########################
version := 0.1
name    := Unorganized Walruscide

.PHONY: clean mpa debug install install-debug
clean:
	@rm -f mpa mpa-debug $<
	echo "Build files removed!
  
mpa: 
	echo "Compiling..."
	echo ""
	@gcc mpa.c -O3 -g0 -o mpa $<
	echo "Done! Final Binary: ./mpa"
  
debug: 
	echo "Compiling..."
	echo ""
	@gcc mpa.c -g3 -Og -o mpa-debug $<
	echo "Done! Final Binary: ./mpa-debug"

install:
	echo "Installing.."
	echo ""
	@sudo mkdir -p /usr/local/bin $<
	@sudo cp mpa /usr/bin/mpa $<
	echo "Done!"
	
install-debug:
	echo "Installing..."
	echo ""
	@sudo mkdir -p /usr/local/bin $<
	@sudo cp mpa-debug /usr/bin/mpa $<
	echo "Done!"
