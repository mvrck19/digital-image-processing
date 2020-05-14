#include <stdio.h>
#include <string.h>
#define rows 566
#define columns 534

unsigned char yplane[rows][columns];
unsigned char uplane[rows/2][columns/2];
unsigned char vplane[rows/2][columns/2];
unsigned char binary[rows][columns];
unsigned char theta[rows][columns];
unsigned char final[rows][columns];

int make_binary(int x, int y)
{
    if (yplane[x][y] >= 128)
        return 255;
    else
        return 0;
}

int create_theta(int x, int y)
{
    int result = 0;
    for (int i = (x - 1); i < (x + 2); i++)                  //  For every
        for (int j = (y - 1); j < (y + 2); j++)              //  pixel around
            if (i >= 0 && i < rows && j >= 0 && i < columns) // If it doesn't go out of limits
            {
                if (binary[i][j] >= 128)                     // If every pixel is 225
                    result = 255;                            // Then return 255
                else                                         // Otherwise return 0
                    result = 0;
            }
            else
                result = 0;
    return result;
}

int main()
{
    FILE *fd;
    FILE *fd2;
    fd = fopen("10_27a.yuv", "rb");
    fd2 = fopen("10_27a_filtered.yuv", "wb");
    // Create A
    fread(yplane, 1, sizeof(yplane), fd);
    fread(uplane, 1, sizeof(uplane), fd);
    fread(vplane, 1, sizeof(vplane), fd);

    // Create binary image of A
    for (int x = 0; x < rows; x++)
        for (int y = 0; y < columns; y++)
            binary[x][y] = make_binary(x, y);

    // Create A⊖B
    for (int x = 0; x < rows; x++)
        for (int y = 0; y < columns; y++)
            theta[x][y] = create_theta(x, y);

    // Create b(A) = A-A⊖B
    for (int x = 0; x < rows; x++)
        for (int y = 0; y < columns; y++)
            final[x][y] = (binary[x][y] - theta[x][y]);

    fwrite(final, 1, sizeof(yplane), fd2);
    fwrite(uplane, 1, sizeof(uplane), fd2);
    fwrite(vplane, 1, sizeof(vplane), fd2);
    fclose(fd2);
    fclose(fd);
    return 0;
}