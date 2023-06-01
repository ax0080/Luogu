#include <stdio.h>

int main(void) {

    int input;
    int in_num;

    int num5 = 0, num0 = 0;

    scanf("%d", &in_num);

    for (int i = 0; i < in_num; i++)
    {
        scanf("%d", &input);
        if (input == 5) num5++;
        else if (input == 0) num0++;
    }

    num5 /= 9;

    if (num0 == 0) printf("-1");
    else
    {
        if (num5 != 0)
        {
            for (int i = 1; i <= num5; i++)
            {
                printf("555555555");
            }
            for (int i = 1; i <= num0; i++)
            {
                printf("0");
            }
        }
        else printf("0");
        
    }

    return 0;
}