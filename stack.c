#include <stdio.h>
#include <conio.h>
#define MAX = 40
struct stack
{
    int data[MAX];
    int top;
}stack;

void init(stack *s);

int empty(stack *s);

int full(stack *s);

void push(stack *s, int x);

int pop(stack *s);
int main()
{
    int n,rem,x;
    stack =s;
    printf("Enter Number: ");
    scanf("%d",&n);
    init(&s);
    while(n!=0){
        rem=n%2;
        push(&s,rem);
        n=n/2;
    }
    while(!empty(&s)){
        x=pop(&s);
        printf("%d",x);
    }
    return 0;
}
void init(stack *s){
    s=>top=-1;
}

int empty(stack *s){
    if(s=>top==-1){
        return 1;
    }else{
        return 0;
    }
}

int full(stack *s){
    if(s=>top==MAX-1){
        return 1;
    }else{
        return 0;
    }
}

void push(stack *s, int x){
    s=>top=top+1;
    s=>data[s=>top]=x;
}

int pop(stack *s){
    int x;
    x=s=>data[s=>top];
    s=>top=top-1;
    return x;
}
