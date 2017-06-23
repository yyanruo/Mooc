/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    //set the block_size
    int block_size = 512 ; 
    FILE *f;

    //in case of file open 
    if((f = fopen("card.raw", "r")) == NULL){
    	printf("Error opening this file\n");
    	return 1;
    }

    //setup the buffer array
    uint8_t buffer[block_size];
    int counter = 0;

    //creat the file point to be write
    FILE *fnew = NULL;

    while(fread(buffer,block_size,1,f)){

    	//find the magic number of the jpeg
    	if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
    		
    		//If open a file, close the file
    		if(fnew != NULL){
    			fclose(fnew);
    		}

    		char temp[8];
            sprintf(temp, "%03d.jpg", counter);
             
            // open a new jpeg file for writing
            fnew = fopen(temp, "w");

            counter++;
    	}

    	if (fnew != NULL){
            fwrite(buffer, block_size, 1, fnew);
        }

    }
    if(fnew != NULL){
   		fclose(fnew);
   	}
   	
   	fclose(f);
   	
   	return 0;
}