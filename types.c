#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int num1;
    int num2;
    float num3;
    float num4;
    scanf("%d %d\n%f %f",&num1,&num2,&num3,&num4);
    //printf("%d %d %f %f\n", num1, num2, num3, num4);
    int sum = num1 + num2;
    int diff = num1 - num2;
    printf("%d %d\n",sum,diff );
    float sum2 = num3 + num4;
    float diff2 = num3 - num4;
    printf("%.1f %.1f",sum2,diff2);
    return 0;
}
