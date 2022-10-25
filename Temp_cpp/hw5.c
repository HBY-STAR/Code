#include <stdio.h>

// Bubble sort: Pointer version
void bubble_p(long *data, long count)
{
    for (long *p2 = &data[count - 1]; p2 != &data[0]; p2--)
    {
        for (long *p1 = &data[0]; p1 != p2; p1++)
        {
            if (*(p1 + 1) < *p1)
            {
                long t = *(p1 + 1);
                *(p1 + 1) = *p1;
                *p1 = t;
            }
        }
    }
}

/* Test code
int main()
{
    long data[5] = {2,3,4,5,1};
    bubble_p(data, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", data[i]);
    }
    getchar();
    return 0;
}
*/