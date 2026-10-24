#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char* input;
    int Array[] = {'0','1','2','3','4','5','6','7','8','9'};
    int results[] = {0,0,0,0,0,0,0,0,0,0};
    input = malloc(1024 * sizeof(char));
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    scanf("%s",input);
    input = realloc(input, strlen(input) + 1);
   // printf("%s",input);
    for(int i=0;i<strlen(input);i++){
       // printf("%c",input[i]);
       for(int j =0;j<10;j++){
            if(input[i] ==Array[j]){
                results[j]++;
            }
            }
    }
    for(int k =0;k<10;k++){
      printf("%d ",results[k])  ;
    }
    
    return 0;
}
