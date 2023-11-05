// a program to create reverse of a string

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100],rev[100];
    int i,j,len;
    printf("Enter the string: ");
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1,j=0;i>=0;i--,j++)
    {
        rev[j]=str[i];
    }
    rev[j]='\0';
    printf("The reverse string is: %s\n",rev);
    return 0;
}
