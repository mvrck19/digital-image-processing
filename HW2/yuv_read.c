#include <stdio.h>
unsigned char yplane[240][416]; 
unsigned char uplane[120][208]; 
unsigned char vplane[120][208]; 
int main()
{
    FILE *fd;
    FILE *fd2;
    fd = fopen("/HW2_images/house.yuv", "rb");
    fd2 = fopen("/HW2_images/house_filtered.yuv", "wb");
    fread(yplane, 1, sizeof(yplane), fd);
    fread(uplane, 1, sizeof(uplane), fd);
    fread(vplane, 1, sizeof(vplane), fd);
    fwrite(yplane, 1, sizeof(yplane), fd2);
    fwrite(uplane, 1, sizeof(uplane), fd2);
    fwrite(vplane, 1, sizeof(vplane), fd2);
    fclose(fd2);
    fclose(fd);
    return 0;
}
