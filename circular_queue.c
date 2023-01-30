#include<stdio.h>
#define MAX 10
int queue[MAX];
int f =0,b=-1,c=0;
void insert(int n){
    if(c == MAX) return;
    queue[(++b)%MAX] =n;
    c++;
}
int delete()
{
    int n =queue[f];
    f = (f+1)%MAX;
    c--;
    return n;
}
void dis()
{
    int i= f,co =c;
    while(co--!=0)
    {
        printf("%d",queue[i]);
        i = (i+1)%MAX;
    }
}
void main()
{
    insert(3);
    insert(4);
    delete();
    dis();
  //write the menu yourself
}
