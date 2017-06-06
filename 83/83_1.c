#include "stdio.h" 

void* memmove(void *dest, const void* src, size_t n)  
{  
    if(dest == NULL || src == NULL)  
        return NULL;  
    char* p =(char*) dest;  
    char* q =(char*) src;  
    while(n--)  
    {  
        *p++ = *q++;  
    }  
    return dest;  
}  
int main()  
{  
    char* p = "hello,world";  
    char dest[6] = {0};  
    char *q = (char*)memmove(dest,p,5);  
    printf("%s\n",dest);  
    printf("%s\n",q);  
    return 0;  
}