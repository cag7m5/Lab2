#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>


unsigned int convert_register(char* input_register)//this takes the conventional name of a register and returns the register number(table in lab1 pdf)
{
    unsigned int result;
    if(strcmp(input_register, "$zero") == 0)
        result = 0;
    else if(strcmp(input_register, "$at") == 0)
        result = 1;
    else if(strcmp(input_register, "$v0") == 0)
        result = 2;
    else if(strcmp(input_register, "$v1") == 0)
        result = 3;
    else if(strcmp(input_register, "$a0") == 0)
        result = 4;
    else if(strcmp(input_register, "$a1") == 0)
        result = 5;
    else if(strcmp(input_register, "$a2") == 0)
        result = 6;
    else if(strcmp(input_register, "$a3") == 0)
        result = 7;
    else if(strcmp(input_register, "$t0") == 0)
        result = 8;
    else if(strcmp(input_register, "$t1") == 0)
        result = 9;
    else if(strcmp(input_register, "$t2") == 0)
        result = 10;
    else if(strcmp(input_register, "$t3") == 0)
        result = 11;
    else if(strcmp(input_register, "$t4") == 0)
        result = 12;
    else if(strcmp(input_register, "$t5") == 0)
        result = 13; 
    else if(strcmp(input_register, "$t6") == 0)
        result = 14;
    else if(strcmp(input_register, "$t7") == 0)
        result = 15;
    else if(strcmp(input_register, "$s0") == 0)
        result = 16;
    else if(strcmp(input_register, "$s1") == 0)
        result = 17;
    else if(strcmp(input_register, "$s2") == 0)
        result = 18;
    else if(strcmp(input_register, "$s3") == 0)
        result = 19;
    else if(strcmp(input_register, "$s4") == 0)
        result = 20;
    else if(strcmp(input_register, "$s5") == 0)
        result = 21;
    else if(strcmp(input_register, "$s6") == 0)
        result = 22;
    else if(strcmp(input_register, "$s7") == 0)
        result = 23;
    else if(strcmp(input_register, "$t8") == 0)
        result = 24;
    else if(strcmp(input_register, "$t9") == 0)
        result = 25;
    else if(strcmp(input_register, "$k0") == 0)
        result = 26;
    else if(strcmp(input_register, "$k1") == 0)
        result = 27;
    else if(strcmp(input_register, "$gp") == 0)
        result = 28;
    else if(strcmp(input_register, "$sp") == 0)
        result = 29;
    else if(strcmp(input_register, "$fp") == 0)
        result = 30;
    else if(strcmp(input_register, "$ra") == 0)
        result = 31;
    else
        result = -1;//error
    return result;
}

int main(int argc, char *argv[]) {

    FILE *fpi;  //input file
    FILE *fpo;  //output file


    if (argc != 2){
        printf("\nERROR: Correct Sequence: ./assembler_mips <input file>\n");
    }

    fpi = fopen(argv[1], "r");
    fpo = fopen("out1.in", "w");

    if (fpi == NULL || fpo == NULL){
        printf("\nERROR: Can't open one or more files\n");
        exit(-1);
    }


    
    char *instruct = (char*)malloc(10*sizeof(char));
    char *rs = (char*)malloc(10*sizeof(char));
    char *rt = (char*)malloc(10*sizeof(char));
    char *rd = (char*)malloc(10*sizeof(char));

    unsigned int op;
    unsigned int immediate;
    unsigned int target;
    unsigned int funct; 
    unsigned int shamt;
    unsigned int converted_rs, converted_rt, converted_rd;
    unsigned int output;
    
    //this while loop runs a single time for every line read in
    while(!feof(fpi))//stops at end of file
    {    
        //reinitialize ints each time
        op = 0;
        immediate = 0;
        target = 0;
        shamt = 0;
        funct = 0;
        converted_rs = 0;
        converted_rt = 0;
        converted_rd = 0;
        output = 0;

        if(fscanf(fpi, "%s", instruct) == 1)// scan instruction at beginning of line
        {
            //one if for every possible operation
            if (strcmp(instruct,"addiu") == 0)//ADDIU
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)// %[^,] reads in a string and stops at the comma
                    { // THIS SPACE ^ HAS!! TO BE HERE EVERYTIME OR IT WILL READ IN THE FIRST REGISTER INCORRECTLY!!!!!!
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x24000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
      
            }
            else if (strcmp(instruct, "add") == 0)//ADD
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100000;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "addu") == 0)//ADDU
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100001;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "and") == 0)//AND
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100100;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "div") == 0)//DIV
            {
                    if(fscanf(fpi, " %[^,], %s", rs, rt) != 0)
                    {
                   
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b011010;
                        output = converted_rt + converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            else if (strcmp(instruct, "divu") == 0)//DIVU
            {
                    if(fscanf(fpi, " %[^,], %s", rs, rt) != 0)
                    {
                   
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b011011;
                        output = converted_rt + converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "jalr") == 0)//JALR(using the first listed format: JALR rs)
            {
                    if(fscanf(fpi, " %s", rs) != 0)
                    {
                   
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b001001;
                        output = converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "jr") == 0)//JR
            {
                    if(fscanf(fpi, " %s", rs) != 0)
                    {
                   
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b001000;
                        output = converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "mfhi") == 0)//MFHI
            {
                    if(fscanf(fpi, " %s", rd) != 0)
                    {
                   
                        converted_rd = convert_register(rd);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        funct = 0b010000;
                        output = converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "mflo") == 0)//MFLO
            {
                    if(fscanf(fpi, " %s", rd) != 0)
                    {
                   
                        converted_rd = convert_register(rd);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        funct = 0b010010;
                        output = converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "mthi") == 0)//MTHI
            {
                    if(fscanf(fpi, " %s", rs) != 0)
                    {
                   
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b010001;
                        output = converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "mtlo") == 0)//MTLO
            {
                    if(fscanf(fpi, " %s", rs) != 0)
                    {
                   
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b010011;
                        output = converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "mult") == 0)//MULT
            {
                    if(fscanf(fpi, " %[^,], %s", rs, rt) != 0)
                    {
                   
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b011000;
                        output = converted_rt + converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "multu") == 0)//MULTU
            {
                    if(fscanf(fpi, " %[^,], %s", rs, rt) != 0)
                    {
                   
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b011001;
                        output = converted_rt + converted_rs + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "nor") == 0)//NOR
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100111;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "or") == 0)//OR
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100101;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "sll") == 0)//SLL
            {
                    if(fscanf(fpi, " %[^,], %[^,], %X", rd, rt, &shamt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        shamt = ((shamt << 6) & 0x000007C0);
                        output = converted_rt + converted_rd + shamt;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "slt") == 0)//SLT
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b101010;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "sra") == 0)//SRA
            {
                    if(fscanf(fpi, " %[^,], %[^,], %X", rd, rt, &shamt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        shamt = ((shamt << 6) & 0x000007C0);
                        funct = 0b000011;
                        output = converted_rt + converted_rd + shamt + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "srl") == 0)//SRL
            {
                    if(fscanf(fpi, " %[^,], %[^,], %X", rd, rt, &shamt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        shamt = ((shamt << 6) & 0x000007C0);
                        funct = 0b000010;
                        output = converted_rt + converted_rd + shamt + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "sub") == 0)//SUB
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100010;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "subu") == 0)//SUBU
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100011;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "syscall") == 0)//SYSCALL
            {
                        output = 0x0000000C;
                        fprintf(fpo, "%X\n", output);
                  
            }
            
            else if (strcmp(instruct, "xor") == 0)//XOR
            {
                    if(fscanf(fpi, " %[^,], %[^,], %s", rd, rs, rt) != 0)
                    {
                        
                        converted_rd = convert_register(rd);
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rd = ((converted_rd << 11) & 0x0000F800);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        funct = 0b100110;
                        output = converted_rt + converted_rs + converted_rd + funct;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "j") == 0)//J
            {
                    if(fscanf(fpi, " %X", &target) != 0)
                    {
                        op = 0x08000000;
                        output = target + op;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct, "jal") == 0)//JAL
            {
                    if(fscanf(fpi, " %X", &target) != 0)
                    {
                        op = 0x0C000000;
                        output = target + op;
                        fprintf(fpo, "%X\n", output);
                    } 
                    else
                        printf("line not read/stored correctly");
                    
            }
            
            else if (strcmp(instruct,"addi") == 0)//ADDI
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    {
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x20000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }
      
            else if (strcmp(instruct,"andi") == 0)//ANDI
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x30000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }
      
            else if (strcmp(instruct,"beq") == 0)//BEQ
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x10000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }   
            
            else if (strcmp(instruct,"bgez") == 0)//BGEZ
            {
                  
                    if(fscanf(fpi, " %[^,], %X", rs, &immediate) != 0)
                    { 
  
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x04000000;
                        output = immediate + converted_rs + op + 0x00010000;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }
            
            else if (strcmp(instruct,"bltz") == 0)//BLTZ
            {
                  
                    if(fscanf(fpi, " %[^,], %X", rs, &immediate) != 0)
                    { 
  
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x04000000;
                        output = immediate + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }
            
            else if (strcmp(instruct,"bgtz") == 0)//BGTZ
            {
                  
                    if(fscanf(fpi, " %[^,], %X", rs, &immediate) != 0)
                    { 
  
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x1C000000;
                        output = immediate + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }
            
            else if (strcmp(instruct,"blez") == 0)//BLEZ
            {
                  
                    if(fscanf(fpi, " %[^,], %X", rs, &immediate) != 0)
                    { 
  
                        converted_rs = convert_register(rs);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x18000000;
                        output = immediate + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }
            
            else if (strcmp(instruct,"bne") == 0)//BNE
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x14000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }   
            
            else if (strcmp(instruct,"lb") == 0)//LB*****
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x10000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }   
            
            else if (strcmp(instruct,"lh") == 0)//LH*****
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x10000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }   
            
            else if (strcmp(instruct,"lui") == 0)//LUI
            {
                  
                    if(fscanf(fpi, " %[^,], %X", rt, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rt = ((converted_rs << 16) & 0x001F0000);
                        op = 0x3C000000;
                        output = immediate + converted_rt + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }
            
            else if (strcmp(instruct,"lw") == 0)//LW*****
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x10000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }  
            
            else if (strcmp(instruct,"ori") == 0)//ORI
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x34000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }   
            
            else if (strcmp(instruct,"sb") == 0)//SB*****
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x10000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }  
            
            else if (strcmp(instruct,"sh") == 0)//SH*****
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x10000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }  
            
            else if (strcmp(instruct,"slti") == 0)//SLTI
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x28000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }   
            
            else if (strcmp(instruct,"sw") == 0)//SW*****
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x10000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }  
            
            else if (strcmp(instruct,"xori") == 0)//XORI
            {
                  
                    if(fscanf(fpi, " %[^,], %[^,], %X", rt, rs, &immediate) != 0)
                    { 
  
                        converted_rt = convert_register(rt);
                        converted_rs = convert_register(rs);
                        converted_rt = ((converted_rt << 16) & 0x001F0000);
                        converted_rs = ((converted_rs << 21) & 0x03E00000);
                        op = 0x38000000;
                        output = immediate + converted_rt + converted_rs + op;
                        fprintf(fpo, "%X\n", output);
                    }
                    else
                        printf("line not read/stored correctly");
            }   
            //all the rest of the instructions go here in the same way as the ones above
            
            
            else //this is the final else, all operations go above this
            {
                    printf("no instruction associated with that name");
                    
            }
        }
     
        else//if the file ends or the instruction at the beginning of the line doesn't read
        {
            printf("\nend of file(ok) or instruction not found\n");
            break;
        }




    }//end while
    
    fclose(fpi);
    
    return 0;
}
