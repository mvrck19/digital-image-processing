#include <stdio.h>
#include <stdlib.h>
unsigned char yplane[240][416]; //array for the y component i.e. your greyscale image
unsigned char uplane[120][208]; //array for the u component. Needed to create the .yuv output file
unsigned char vplane[120][208]; //array for the v component. Needed to create the .yuv output file
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
    FILE *fd;
    FILE *fd2;

    fd = fopen("BlowingBubbles_416x240.yuv", "rb");
    fd2 = fopen("BlowingBubbles_416x240_filtered.yuv", "wb");

    fread(yplane, 1, sizeof(yplane), fd);
    fread(uplane, 1, sizeof(uplane), fd);
    fread(vplane, 1, sizeof(vplane), fd);

    int counter = 0;
    int array[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int x = 0; x < 1; x++)
        for (int y = 0; y < 1; y++)
            for (int i = x - 1; i < x + 2; i++)
                for (int j = y - 1; j < y + 2; j++)
                    if (i >= 0 && i < 240 && j >= 0 && i < 416)
                    {
                        array[counter] = yplane[i][j];
                        counter++;
                    }
                    else
                    {
                        array[counter] = 0;
                        counter++;
                    }
    qsort(array,9,sizeof(int),cmpfunc);
    for (int i = 0; i < 9; i++)
    {
        printf("|%d|\t",array[i]);
    }
    
    

    /*End of code*/

    fclose(fd2);
    fclose(fd);

    return 0;
}
