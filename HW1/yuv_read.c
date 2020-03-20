//
//  main.c
//  yuv_read
//
//  This program opens a 4:2:0 yuv file and saves each of the three components (y, u, v) in a seperate array.
//  Each array can be treated seperately. For example one can treat the y component a greascale image
//  The three components are stored in an other 4:2:0 yuv file
//
//  Created by Maria Koziri on 24/10/2018.
//  Copyright © 2018 Maria Koziri. All rights reserved.
//

#include <stdio.h>

unsigned char yplane[240][416]; //array for the y component i.e. your greyscale image
unsigned char uplane[120][208]; //array for the u component. Needed to create the .yuv output file
unsigned char vplane[120][208]; //array for the v component. Needed to create the .yuv output file

int main()
{
    FILE *fd;
    FILE *fd2;
    
    fd = fopen("BlowingBubbles_416x240.yuv", "rb");
    fd2 = fopen("BlowingBubbles_416x240_filtered.yuv", "wb");
    
    fread(yplane, 1, sizeof(yplane), fd);
    fread(uplane, 1, sizeof(uplane), fd);
    fread(vplane, 1, sizeof(vplane), fd);
    
/*
 code to handle one or more of the components
 For example the y component can be "seen" as a greyscale image with dimension 416X240
 So, the data or the raw image are already stored in the yplane[240][416] array.
 */
    fwrite(yplane, 1, sizeof(yplane), fd2);
    fwrite(uplane, 1, sizeof(uplane), fd2);
    fwrite(vplane, 1, sizeof(vplane), fd2);

    fclose(fd2);
    fclose(fd);
    
    return 0;
}
