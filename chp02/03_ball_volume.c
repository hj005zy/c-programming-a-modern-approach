#include <stdio.h>

int main(void)
{
    int radius;
    
    printf("Enter radius of ball: ");
    scanf("%d", &radius);

    float volume = 4.0f / 3.0f * 3.14159f * radius * radius * radius;
    printf("Volume %f\n", volume);

    return 0;
}
