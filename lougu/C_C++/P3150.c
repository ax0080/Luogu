#include <stdio.h>

int main(void) {

    int count;
    scanf("%d", &count);

    int num;
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &num);

        if (num % 2 == 0) printf("pb wins\n");
        else printf("zs wins\n");

    }

    return 0;
}