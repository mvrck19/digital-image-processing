#include <stdio.h>

int main()
{

    int counter = 0;

    for (int x = 0; x < 1; x++)
        for (int y = 0; y < 1; y++)
            for (int i = x - 7; i < x + 8; i++)
                for (int j = y - 7; j < y + 8; j++)
                {
                    printf("x=%d\ty=%d\ti=%d\tj=%d\n", x, y, i, j);
                    counter++;
                }
    printf("counter is %d", counter);
}
