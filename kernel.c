#include "console.h"
#include "keyboard.h"
void main() 
{
	clearTerminal();
	printCharacter('H');
	printString("ello");
	printLine("world");
	printString("TODAY");
	
	unsigned char byte;
        while (1) {
                while (byte = scan()) {
                        
                        printCharacter(charmap[byte]);
                        }
                
        }
	return;
}
