#include<stdio.h>
int main(){
    char str[100];

    printf("Enter a date: ");
    gets(str);

    int i, p=0, j=0;

    for(i=0; i<strlen(str); i++){
        if(isdigit(str[i])){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    for(i=0; i<strlen(str); i++){
        if(str[i]!=str[strlen(str)-i-1]){
            p=1;
            break;
        }
    }
    if(p==0){
        printf("Palindrome\n");
    }
    else{
        printf("Not Palindrome\n");
    }
}
