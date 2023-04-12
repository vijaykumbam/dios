#include "../include/console.h"
int terminalPosition = 0;
void clearTerminal(){
	for(int i=0; i<VGA_WIDTH*VGA_HEIGHT*VGA_BYTES_PER_CHARACTER; i+=2){
		VGA_BUFFER[i] = 0;
		VGA_BUFFER[i+1] = 0X07;
	}
}
void handleNewLineCharacter(){
	terminalPosition = terminalPosition + 160 - (terminalPosition % (VGA_WIDTH*VGA_BYTES_PER_CHARACTER));
}

void handleSpecialCharacter(char c){
	switch(c){
		case '\n':
		handleNewLineCharacter();
		break;
		
	}
}
int isSpecialCharacter(char c) {
	if(c >= '0' && c <= '9'){
    		return  0;
	}else if(c >= 'A' && c <= 'Z'){
    		return  0;
    	}else if(c >= 'a' && c <= 'z'){
    		return  0;
    	}else{
    		return 1;
    	} 
}
void printCharacter(char c){
	if(isSpecialCharacter(c)){
		handleSpecialCharacter(c);
		return;	
	}
	VGA_BUFFER[terminalPosition++] = c;
	VGA_BUFFER[terminalPosition++] = 0X07;
}
void printString(char* str){
	for(int i=0; str[i] != '\0'; i++){
		printCharacter(str[i]);
	}
}

void printLine(char* str){
	printString(str);
	printCharacter('\n');
}
