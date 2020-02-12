#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
bool isKeyword(char s[]);
bool identifier(char s[], int i);
bool isOperator(char s[], int i);
bool isSymbol(char s[], int i);
int main(){
    char str[] = "int c = a + b ; ";
    char temp[100][25]= {0};
    int i, j=0, jj=0;
    for(i=0; i<strlen(str); i++){
        if(str[i]!=' '){
            temp[j][jj++] = str[i];
        }
        else{
            j++;
            jj = 0;
        }
    }
    for(i=0; i<j; i++){
        define(temp[i], strlen(temp[i]));
    }

}
void define(char s[], int i){
    if(isKeyword(s)){
        printf("'%s' is a keyword\n", s);
    }
    else if(identifier(s, i)){
        printf("'%s' is an identifier\n", s);
    }
    else if(isOperator(s, i)){
        printf("'%s' is an Operator\n", s);
    }
    else if(isSymbol(s, i)){
        printf("'%s' is a Symbol\n", s);
    }
    return 0;

}
bool isSymbol(char s[], int i){
    char oper[] = ";,{}()";
    for(int k=0; k<i; k++){
        for(int j=0; j<strlen(oper); j++){
            if(s[k]==oper[j]){
                return true;
            }
        }
    }
    return false;
}
bool isOperator(char s[], int i){
    char oper[] = "+-*/<>=";
    for(int k=0; k<i; k++){
        for(int j=0; j<strlen(oper); j++){
            if(s[k]==oper[j]){
                return true;
            }
        }
    }
    return false;
}
bool isKeyword(char s[]){
    char  myKeyword[10][10] = {"int", "double", "float", "long","char"};
    for(int j=0; j<5; j++){
        if(strcmp(s, myKeyword[j])==0){
            return true;
        }
    }
    return false;
}
bool identifier(char s[], int i){
    for(int j=0; j<i; j++){
        if(!isalpha(s[j])){
            return false;
        }
    }
    return true;
}
