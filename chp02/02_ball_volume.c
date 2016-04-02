#include <stdio.h>

int main(void)
{
    int radius = 10;
    float volume = 4.0f / 3.0f * 3.14159f * radius * radius * radius;
    
    printf("Volume %f\n", volume);

    return 0;
}
