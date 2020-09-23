#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

int main(int argc, char *argv[]) {

	FILE *fpi;	//input file
	FILE *fpo	//output file
	int i = 1;
	
	if (argc != 2){
		printf("\nERROR: Correct Sequence: ./assembler_mips <input file>\n");
	}
	
	fpi = fopen(argv[1], "r");
	fpo = fopen("Output.in", "w");
	
	if (fpi == NULL || fpo == NULL){
		printf("\nERROR: Can't open one or more files\n");
		exit(-1);
	}
	
	char line[100];
	while(fgets(line, 100, fpi) != NULL){
		printf("Line %d is: %s\n", i, line);
		i++;
	}
	

	return 0;

}
