#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct{
    char *instruct, *rs, *rt, *rd, *shamt, *funct, *immediate, *target;
} line;


int main(int argc, char *argv[]) {

    FILE *fpi;  //input file
    FILE *fpo;  //output file

    int j = 0;


    if (argc != 2){
        printf("\nERROR: Correct Sequence: ./assembler_mips <input file>\n");
    }

    fpi = fopen(argv[1], "r");
    fpo = fopen("Output.in", "w");

    if (fpi == NULL || fpo == NULL){
        printf("\nERROR: Can't open one or more files\n");
        exit(-1);
    }


    line struct_array[100];//create array of structs to store each line in

    for(int i = 0; i < 100; i++)//initialize each string in every struct
    {
        struct_array[i].instruct = (char*)malloc(10*sizeof(char));
        struct_array[i].rs = (char*)malloc(10*sizeof(char));
        struct_array[i].rt = (char*)malloc(10*sizeof(char));
        struct_array[i].rd = (char*)malloc(10*sizeof(char));
        struct_array[i].shamt = (char*)malloc(10*sizeof(char));
        struct_array[i].funct = (char*)malloc(10*sizeof(char));
        struct_array[i].immediate = (char*)malloc(10*sizeof(char));
        struct_array[i].target = (char*)malloc(10*sizeof(char));

    }

    while(j < 5)//just for now, later this will be "while(!feof(fpi))" so it stops at end of file
    {
        if(fscanf(fpi, "%s", struct_array[j].instruct) == 1)// scan instruction at beginning of line
        {

            if (strcmp(struct_array[j].instruct,"addiu") == 0)//ADDIU
            {

                    if(fscanf(fpi, "%[^,], %[^,], %s", struct_array[j].rt, struct_array[j].rs, struct_array[j].immediate) != 0)
                        printf("\n%s %s, %s, %s", struct_array[j].instruct, struct_array[j].rt, struct_array[j].rs, struct_array[j].immediate);
                    else
                        printf("line not read/stored correctly");
                    j++;
            }
            else if (strcmp(struct_array[j].instruct, "add") == 0)//ADD
            {
                    if(fscanf(fpi, "%[^,], %[^,], %s", struct_array[j].rd, struct_array[j].rs, struct_array[j].immediate) != 0)
                        printf("\n%s, %s, %s, %s", struct_array[j].instruct, struct_array[j].rd, struct_array[j].rs, struct_array[j].immediate);
                    else
                        printf("line not read/stored correctly");
                    j++;
            }
            
            //all the rest of the instructions go here in the same way as the ones above
            
            
            else //this is the final else, all instructions go above this
            {
                    printf("no instruction associated with that name");
                    j++;
            }
        }

        else//if the instruction at the beginning of the line doesn't read
        {
            printf("\nfailed to read instruction");
            j++;
        }




    }
    
    fclose(fpi);
    
    return 0;
}
