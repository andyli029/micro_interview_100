
#include <stdio.h>
#include <stdlib.h>

void findSameChar(char* test){
  char temp[256] = {0};
  char *cur = test;
  
  for(; *cur != '\0'; cur++){
    if(temp[*cur] == 1){
        printf("%c is a chongfu char\n", *cur);
        temp[*cur]++;
    }else{
       temp[*cur]++;
    }
  }
}


int main()
{
    char test[]="dfdsfsdfdsfsdgreyerthgfjhtrutrjhgjrewrtwe";
    findSameChar(test);
    return 0;
}

