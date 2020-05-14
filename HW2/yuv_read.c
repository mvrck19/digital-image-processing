#include <stdio.h>
#include <string.h>

unsigned char yplane[512][512];
unsigned char uplane[256][256];
unsigned char vplane[256][256];
unsigned char binary[512][512]; 
unsigned char theta[512][512];
unsigned char final[512][512];

int make_binary(int x, int y){
    if(yplane[x][y]>=128) return 255;
    else return 0;

}


int create_theta(int x, int y)
{
    int result=0;
    for (int i = (x - 1); i < (x + 2); i++)                 //  For every
        for (int j = (y - 1); j < (y + 2); j++)             //  pixel around 
            if (i >= 0 && i < 512 && j >= 0 && i < 512)     // If it doesn't go out of limits
            {
               if (binary[i][j]>=128)   result=255;               
               else                     result=0;               
            }
            else                        result=0;
    return result;
}

int bound(int x){
    if (x>255)  x=255;
    if (x<0)    x=0;
    return x;
}

int main()
{
    FILE *fd;
    FILE *fd2;
    fd = fopen("cameraman.yuv", "rb");
    fd2 = fopen("cameraman_filtered.yuv", "wb");
    fread(yplane, 1, sizeof(yplane), fd);   // Create A
    fread(uplane, 1, sizeof(uplane), fd);
    fread(vplane, 1, sizeof(vplane), fd);

    // Create binary image
    for (int x = 0; x < 512; x++)
    {
        for (int y = 0; y < 512; y++)
        {
            binary[x][y] = make_binary(x,y);
        }
    }

    // Create theta
    for (int x = 0; x < 512; x++)
        for (int y = 0; y < 512; y++)
            theta[x][y]= create_theta(x,y);



    for (int x = 0; x < 512; x++)
        for (int y = 0; y < 512; y++)
            final[x][y]= (binary[x][y]-theta[x][y]);


    fwrite(final, 1, sizeof(yplane), fd2);
    fwrite(uplane, 1, sizeof(uplane), fd2);
    fwrite(vplane, 1, sizeof(vplane), fd2);
    fclose(fd2);
    fclose(fd);
    return 0;
}
