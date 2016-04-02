#include <stddef.h>
#include <stdio.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(void)
{
    struct s *s_ptr;

    printf("Size of a: %ld, offset of a: %ld\n",
           sizeof(s_ptr->a), offsetof(struct s, a));
    printf("Size of b: %ld, offset of b: %ld\n",
           sizeof(s_ptr->b), offsetof(struct s, b));
    printf("Size of c: %ld, offset of c: %ld\n",
           sizeof(s_ptr->c), offsetof(struct s, c));
    printf("Size of struct s: %ld\n", sizeof(*s_ptr));

    return 0;
}
