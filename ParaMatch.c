#include<stdio.h>
#include<conio.h>
#include<string.h>
char eexp[10],x;
int top=-1;
int circularBracket=-1,squareBracket=-1,curlyBracket=-1;
char stack[5],t;
int i;
char push(char x){
    top++;
    stack[top]=x;
    return 0;
}
char pop(){
    char z;
    z=stack[top];
    top--;
    return(z);
}
int main(){
    printf("Enter Paranthesis: ");
    gets(eexp);
    // scanf("&c",eexp);
    printf("ENTERED ELEMENT: %C\n",eexp);
    for (i = 0; i < strlen(eexp); i++)
    {
        push(eexp[i]);
        printf("PUSHED ELEMENT: %c\n",eexp[i]);
    }
    while (top!=-1)
    {
        t=pop();
        printf("POPEED ELEMENT: %c\n",t);
        if (t=='(')
        {
            circularBracket++;
        }
        else if (t=='[')
        {
            squareBracket++;
        }
        else if (t=='{')
        {
            curlyBracket++;
        }
        else if (t==')')
        {
            circularBracket--;
        }
        else if (t==']')
        {
            squareBracket--;            
        }
        else if (t=='}')
        {
            curlyBracket--;
        }
    }
    printf("%d %d %d \n",circularBracket,curlyBracket,squareBracket);
    if (circularBracket==-1 && curlyBracket== -1 && squareBracket==-1)
    {
          printf("Expression is valid");
    }
    else
    {
          printf("Expression is invalid");
    }
}