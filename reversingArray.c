#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;
    scanf("%d", &num);
    int* arr = (int*)malloc(num * sizeof(int));
    for (i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    int iteration = num / 2;
    //printf("%d\n",iteration);
    for (int i = 0; i < iteration; i++) {
       
        int num2 = num - 1 - i;
        int holder;
        holder = arr[i];
        arr[i] = arr[num2];
        arr[num2] = holder;
        num2--;
    }

    /* Write the logic to reverse the array. */

    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
