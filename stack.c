#include<stdio.h>
#include<stdbool.h>
int top =-1;
#define MAX 5
int stack[MAX];
void push(int n)
{
    if(top== MAX-1)
    {
        printf("stack overflow");
        return;
    }
    stack[++top] = n;
}
int pop()
{
    if(top==-1){
        printf("stack underflow");
        return -1;
    }
    return stack[top--];
}
bool palindrome()
{
    int i=0,j=top; //two pointer approch
    while(i<j)
    {
        if(stack[i++]!=stack[j--]) return false;

    }
    return true;
}
void main()
{
    push(2);
    push(3);
    push(2);
    printf("%d",palindrome());
  //do the menu yourself
}
