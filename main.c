#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //checking argument
 if(argc!=2)
 {
    printf("Usage: ./recover IMAGE\n");
    return 1;
 }
    //file opening
 FILE *file = fopen(argv[1], "r");

 BYTE buffer[512];
 char filename[8];
 int filenum=0;
 bool newfile=false;
 FILE* outfile=NULL;

 if (file==NULL)
 {
    fclose(file);
    printf("File error\n");
    return 2;

 }

 while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
{
    if(buffer[0]== 0xff && buffer[1]==0xd8 && buffer[2]== 0xff && (buffer[3] & 0xf0)==0xe0)
        {
            if(outfile!=NULL)
            {
                fclose(outfile);
            }
            sprintf(filename,"%03i.jpg",filenum);
            outfile=fopen(filename,"w");
            filenum++;


        }
    if(outfile!=NULL)
    {
        fwrite(buffer,sizeof(BYTE)*512,1,outfile);
    }




}
fclose(outfile);
fclose(file);

return 0;


}
