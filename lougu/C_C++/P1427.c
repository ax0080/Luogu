#include <stdio.h>

int main(void) {

    int num[100];
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        scanf("%d", num + i);
        if (*(num + i) == 0)
        {
            break;
        }
        count++;
    }

    //printf("%d", count);

    for (int i = count-1; i >= 0; i--)
    {
        printf("%d ", *(num + i));
    }

    return 0;
}