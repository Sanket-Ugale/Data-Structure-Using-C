#include<stdio.h>
#include<conio.h>
char eexp[10],x;
int top=-1;
char stack[5];
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
	int flag=1;
    char t;
    printf("Enter Paranthesis: ");
    gets(eexp);
    for (i = 0; i < eexp[i]; i++)
    {
        if (eexp[i]=='('||eexp[i]=='{'||eexp[i]=='[')
        {
            push(eexp[i]);
        }
        else if (eexp[i]==')'||eexp[i]=='}'||eexp[i]==']')
        {
            if (top==-1)
            {
                flag=0;
            }
            else
            {
                t=pop();
                if (eexp[i]=='}' && t=='['||t=='(')
                {
                    flag=0;
                }
                 if (eexp[i]==')' && t=='['||t=='{')
                {
                    flag=0;
                }
                 if (eexp[i]==']' && t=='('||t=='{')
                {
                    flag=0;
                }
                
            }
            
            
        }
        
        
    }
    if (top>=0)
    {
        flag=0;
    }
    if (flag==0)
    {
        printf("Expression is invalid");
    }
    else
    {
        printf("Expression is valid");
    }
    
}