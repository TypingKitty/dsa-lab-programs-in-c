#include<stdio.h>
#define MAX 20
int top =-1;
char stack[MAX];
char pop()
{
    if(top == -1) return '\n';
    return stack[top--];
}
void push(char n)

{
    if(top == MAX-1){
        printf("overflow");
        return;
    }
    stack[++top] = n;
}
int priority(char c)
{
    switch(c)
    {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }

}
void helper(char c)
{
    if(top == -1) push(c);
    else{
        while(priority(stack[top])>=priority(c))
        printf("%c",pop());
        push(c);
    }
}

void post(char* e)
{
    for(int i=0;e[i]!='\0';i++)
    {
        char c = e[i];
        if(c =='(') push(c);
        else if((c>='a' && c<='z')|| (c>='0' && c<='9')) printf("%c",c);
        else if(c == ')')
        {
            
            while(stack[top]!='(') printf("%c",pop());
            pop();
        }
        else helper(c);
    }
    while(top!=-1)
    printf("%c",pop());
}
void main()
{
    char arr[] = "(1+2)*(4/2)";
    post(arr);

}