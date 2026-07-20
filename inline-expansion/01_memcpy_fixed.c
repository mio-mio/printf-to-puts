#include <stdio.h>
#include <string.h>

int main(void){
	char source[4] = {'A', 'B', 'C', '\0'};
	char destination[4];

	memcpy(destination, source, 4);
	puts(destination);

	return 0;

}
