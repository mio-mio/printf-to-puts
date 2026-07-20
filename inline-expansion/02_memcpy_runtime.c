#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	if (argc < 2){
		return 1;
	}

	size_t size = strlen(argv[1]) + 1;
	char *destination = malloc(size);

	if (destination == NULL){
		return 1;
	}

	memcpy(destination, argv[1], size);
	puts(destination);

	free(destination);
	return 0;

}
