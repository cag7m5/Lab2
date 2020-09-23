#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

int main(int argc, char *argv[]) {

	FILE *fpi;	//input file
	FILE *fpo;	//output file
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
	char instruct[10];	//Store instruction name
	char R1[2];	//Store first register
	char R2[2];	//Store second register
	char R3[2];	//Store third register
	int i = 0;	//Used to parse line
	
	while(fgets(line, 100, fpi) != NULL){		//Reads through file line by line
		printf("Line %d is: %s\n", i, line);	//Debug
		i++;
		
		instruct = strtok(line, " ");	//Breaks line into instruction name by looking for space char
		printf("Instruction: %s\n", instruct);	//Debug
		
		if(strcmp(instruct, "addiu") == 0){
			while(line != NULL){
				if(i == 0){
					R1 = strtok(line, " $(),");
					printf("%s", R1);
					i++
				}
				else if(i == 2){
					R2 = strtok(line, " $(),");
					printf("%s", R2);
					i++;
				}
				else if(i == 3){
					R3 = strtok(line, " $(),");
					printf("%s", R3);
					i++;
				}
			}
		}
	}
	
	fclose(fpi);

	return 0;

}
