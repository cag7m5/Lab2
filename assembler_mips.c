#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct{
    char *instruct, *rs, *rt, *rd;// *shamt, *funct; I don't think we ever have to read in shamt or funct
    unsigned int immediate;
    unsigned int target;
    unsigned int converted_rs2, converted_rt2, converted_rd;
} line;

unsigned int convert_register(char* input_register)//this takes the conventional name of a register and returns the register number(table in lab1 pdf)
{
    unsigned int result;
    if(strcmp(input_register, " $zero") == 0)
        result = 0;
    else if(strcmp(input_register, " $at") == 0)
        result = 1;
    else if(strcmp(input_register, " $v0") == 0)
        result = 2;
    else if(strcmp(input_register, " $v1") == 0)
        result = 3;
    else if(strcmp(input_register, " $a0") == 0)
        result = 4;
    else if(strcmp(input_register, " $a1") == 0)
        result = 5;
    else if(strcmp(input_register, " $a2") == 0)
        result = 6;
    else if(strcmp(input_register, " $a3") == 0)
        result = 7;
    else if(strcmp(input_register, " $t0") == 0)
        result = 8;
    else if(strcmp(input_register, " $t1") == 0)
        result = 9;
    else if(strcmp(input_register, " $t2") == 0)
        result = 10;
    else if(strcmp(input_register, " $t3") == 0)
        result = 11;
    else if(strcmp(input_register, " $t4") == 0)
        result = 12;
    else if(strcmp(input_register, " $t5") == 0)
        result = 13; 
    else if(strcmp(input_register, " $t6") == 0)
        result = 14;
    else if(strcmp(input_register, " $t7") == 0)
        result = 15;
    else if(strcmp(input_register, " $s0") == 0)
        result = 16;
    else if(strcmp(input_register, " $s1") == 0)
        result = 17;
    else if(strcmp(input_register, " $s2") == 0)
        result = 18;
    else if(strcmp(input_register, " $s3") == 0)
        result = 19;
    else if(strcmp(input_register, " $s4") == 0)
        result = 20;
    else if(strcmp(input_register, " $s5") == 0)
        result = 21;
    else if(strcmp(input_register, " $s6") == 0)
        result = 22;
    else if(strcmp(input_register, " $s7") == 0)
        result = 23;
    else if(strcmp(input_register, " $t8") == 0)
        result = 24;
    else if(strcmp(input_register, " $t9") == 0)
        result = 25;
    else if(strcmp(input_register, " $k0") == 0)
        result = 26;
    else if(strcmp(input_register, " $k1") == 0)
        result = 27;
    else if(strcmp(input_register, " $gp") == 0)
        result = 28;
    else if(strcmp(input_register, " $sp") == 0)
        result = 29;
    else if(strcmp(input_register, " $fp") == 0)
        result = 30;
    else if(strcmp(input_register, " $ra") == 0)
        result = 31;
    else
        result = -1;//error
    return result;
}

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

    }

    while(j < 5)//just for now, later this will be "while(!feof(fpi))" so it stops at end of file
    {
        if(fscanf(fpi, "%s", struct_array[j].instruct) == 1)// scan instruction at beginning of line
        {

            if (strcmp(struct_array[j].instruct,"addiu") == 0)//ADDIU
            {
                    uint8_t test_rt;
                    if(fscanf(fpi, "%[^,], %[^,], %X", struct_array[j].rt, struct_array[j].rs, &struct_array[j].immediate) != 0)
                    {
                        printf("\n%s %s, %s, %X", struct_array[j].instruct, struct_array[j].rt, struct_array[j].rs, struct_array[j].immediate);//just for testing
                        test_rt = convert_register(struct_array[j].rt);
                        printf("\nhere is the register number of rt: %d", test_rt);
                    }
                    else
                        printf("line not read/stored correctly");
                    j++;
            }
            else if (strcmp(struct_array[j].instruct, "add") == 0)//ADD
            {
                    if(fscanf(fpi, "%[^,], %[^,], %s", struct_array[j].rd, struct_array[j].rs, struct_array[j].rt) != 0)
                        printf("\nread in ADD");
                    else
                        printf("line not read/stored correctly");
                    j++;
            }
            
            else if (strcmp(struct_array[j].instruct, "addi") == 0)//ADDI
            {
                    if(fscanf(fpi, "%[^,], %[^,], %X", struct_array[j].rt, struct_array[j].rs, &struct_array[j].immediate) != 0)
                        printf("\nread in ADDI");
                    else
                        printf("line not read/stored correctly");
                    j++;
            }
            
            else if (strcmp(struct_array[j].instruct, "and") == 0)//AND
            {
                    if(fscanf(fpi, "%[^,], %[^,], %X", struct_array[j].rt, struct_array[j].rs, &struct_array[j].immediate) != 0)
                        printf("\nread in AND");
                    else
                        printf("line not read/stored correctly");
                    j++;
            }
            
            else if (strcmp(struct_array[j].instruct, "add") == 0)//ANDI
            {
                    if(fscanf(fpi, "%[^,], %[^,], %X", struct_array[j].rt, struct_array[j].rs, &struct_array[j].immediate) != 0)
                        printf("\nread in ADD");
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
