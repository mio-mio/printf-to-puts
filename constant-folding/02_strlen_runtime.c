#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	if (argc < 2){
		return 1;
	}

	size_t length = strlen(argv[1]);
	printf("%zu\n", length);
	return 0;
}

