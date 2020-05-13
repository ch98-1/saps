//Copyright (C) 2020  Corwin Hansen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//common stuff
#include "common.h"

//supported cpus
#include "cpu1.h"

int main(int argc, char *argv[]){
  if (argc != 6){
    printf("wrong number of arguments. \n \n Usage:\n \
    %s <type #> <# of cycles> <register file> <Instruction Memory> <Data Memory>\n", argv[0]); //print out error and usage
    exit(1); //exit with error
  }

  uint16_t rf[16] = {0}; //memories for the cpu
  uint16_t im[65536] = {0};;
  uint16_t dm[65536] = {0};;

  uint16_t type = (uint16_t)atoi(argv[1]);//cpu type to simulate

  uint32_t cycles = (uint32_t)atoi(argv[2]); //number of cycles to run

  FILE *fp_rf;//file pointers for memories
  FILE *fp_im;
  FILE *fp_dm;

  //read the memories from file
  fp_rf = fopen(argv[3], "r");//open the files for reading
  fp_im = fopen(argv[4], "r");
  fp_dm = fopen(argv[5], "r");

  if(fp_rf != NULL){ //if the file exists
    int i, l;
    int lc = 0; //line count
    for (i = 0; i < 16; i++){
      char string[128];//string to be filled
      char* str;
      l = fgets(string, 128, fp_rf);//read string
      if (!(feof(fp_rf) && !l)){ //check that data is read in correctly
        lc++;
        rf[i] = (uint16_t)strtol(string, &str, 16); //convert to data and write to memory
      }
      else {
        break;
      }
    }
    printf("read in %d lines of data in to rf\n", lc);//print out the number of lines of data read
    fclose ( fp_rf ); //close the file
  }

  if(fp_im != NULL){ //if the file exists
    int i, l;
    int lc = 0; //line count
    for (i = 0; i < 65536; i++){
      char string[128];//string to be filled
      char* str;
      l = fgets(string, 128, fp_rf);//read string
      if (!(feof(fp_rf) && !l)){ //check that data is read in correctly
        lc++;
        im[i] = (uint16_t)strtol(string, &str, 16); //convert to data and write to memory
      }
      else {
        break;
      }
    }
    printf("read in %d lines of data in to im\n", lc);//print out the number of lines of data read
    fclose ( fp_im ); //close the file
  }

  if(fp_dm != NULL){ //if the file exists
    int i, l;
    int lc = 0; //line count
    for (i = 0; i < 65536; i++){
      char string[128];//string to be filled
      char* str;
      l = fgets(string, 128, fp_rf);//read string
      if (!(feof(fp_rf) && !l)){ //check that data is read in correctly
        lc++;
        dm[i] = (uint16_t)strtol(string, &str, 16); //convert to data and write to memory
      }
      else {
        break;
      }
    }
    printf("read in %d lines of data in to dm\n", lc);//print out the number of lines of data read
    fclose ( fp_dm ); //close the file
  }

  //run cpu
  switch (type) {
    case 0: ;//basic baseline processor. Not implemented yet.
    case 1: cpu1(rf, im, dm, cycles);//standard cpu with 4 bit Rd for MOV and MOVS
    default: ;//basic baseline processor. Not implemented yet.
  }



  //write the memories to file
  fp_rf = fopen(argv[3], "w");//open the files for reading
  fp_im = fopen(argv[4], "w");
  fp_dm = fopen(argv[5], "w");

  int i;
  for (i = 0; i < 16; i++){ //write the data files
    fprintf(fp_rf, "%.4x\n", (int)rf[i]); //write data
  }
  for (i = 0; i < 65536; i++){
    fprintf(fp_im, "%.4x\n", (int)im[i]); //write data
  }
  for (i = 0; i < 65536; i++){
    fprintf(fp_dm, "%.4x\n", (int)dm[i]); //write data
  }

  return(0);
}
