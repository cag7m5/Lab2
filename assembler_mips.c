#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

int main(int argc, char *argv[]) {

	FILE *fpi;	//input file
	FILE *fpo;	//output file
	
	if (argc != 2){
		printf("\nERROR: Correct Sequence: ./assembler_mips <input file>\n");
	}
	
	fpi = fopen(argv[1], "r");
	fpo = fopen("Output.in", "w");
	
	if (fpi == NULL || fpo == NULL){
		printf("\nERROR: Can't open one or more files\n");
		exit(-1);
	}
	
	/*char line[100];
	char linecopy[100];
	char instruct[8];	//Store instruction name
	char R1[5];	//Store first register
	char R2[5];	//Store second register
	char R3[5];	//Store third argument
	*/
	size_t linesize = 100;	//needed for getline function
	char *line = malloc(100 * sizeof(char));
	char *linecopy = malloc(100 * sizeof(char));
	char *instruct = malloc(10 * sizeof(char));
	char *R1 = malloc(10 * sizeof(char));
	char *R2 = malloc(10 * sizeof(char));
	char *R3 = malloc(10 * sizeof(char));
	int i = 0;

	while(getline(&line, &linesize, fpi) != 0){		//Reads through file line by line
		printf("Line is: %s\n", line);	//Debug
		i = 0;	//Used to parse line
		linecopy = strtok(line, " ");	//Breaks line into instruction by looking for space char
		instruct = linecopy;
		printf("Instruction: %s\n", instruct);	//Debug
		
		if(strcmp(instruct, "addiu") == 0){
			while(line != NULL){
				if(i == 0){
					printf("Test\n");
					linecopy = strtok(NULL, " $(), ");
					R1 = linecopy;
					printf("%s", R1);
					i++;
				}
				else if(i == 1){
					linecopy = strtok(NULL, " $(), ");
					R2 = linecopy;
					printf("%s", R2);
					i++;
				}
				else if(i == 2){
					linecopy = strtok(NULL, " (),");
					R3 = linecopy;
					printf("%s", R3);
					i++;
				}
		}
	}
	
	fclose(fpi);

	return 0;

}
