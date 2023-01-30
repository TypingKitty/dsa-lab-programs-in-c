#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct emp
{
    /* data */
    struct emp* prv,*next;
    char name[10],dept[10],design[10];
    int ssn,sal,phno;    
};
typedef struct emp emp;
emp* first = NULL;
int count=0;
emp* create(){
    emp* t;
    t = (emp*) malloc(sizeof(emp));
    t->prv = NULL;
    t->next = NULL;
    printf("enter name , dept and design\n");
    scanf("%s %s %s", t->name,t->dept,t->design);
    printf("enter ssn,sal and phone no\n");
    scanf("%d %d %d",&t->ssn,&t->sal,&t->phno);
count++;
return t;    
}
void display(){
    if(!first){
        printf("list is empty cant display\n");
        return;
    }
    emp* t= first;
    while(t){
    printf("name = %s\tdept = %s\tdesign = %s\t",t->name,t->dept,t->design);
    printf("ssn = %d\tsal = %d\tphone no = %d\n",t->ssn,t->sal,t->phno);
    t = t->next;
    }
    printf("number of nodes = %d\n",count);
}
void insertb(){
    emp* t = create();
    if(!first) {
        first = t;
        return;
    }
    t->next = first;
    first->prv = t;
    first = t;
}
void inserte(){
    emp* temp = create();
   if(!first) 
   {
    first = temp;
    return;
   }
   emp* t = first;
   while(t->next) t = t->next;
   t->next = temp;
   temp->prv = t;
}
void delatb(){
    if(!first) return;
  emp* temp = first;
  first = first->next;
  free(temp);
  count--;
}
void delate(){
   if(!first) return;
   emp* t = first;
   if(count == 1 )
   {
    first =NULL;
    free(t);
    count--;
    return;
   }
   while(t->next->next) t=t->next;
   emp* temp = t->next;
   t->next = NULL;
   free(temp);
   count--;
}
int main(){
    int c;
    while(1)
    {
        printf("0 for bulk insertion\n1 for insert from end\n2 for insert from begining\n3 for display  \n4 for delete at end\n5 for delete ate begining\n6 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 0: {
                printf("enter no of nodes");
                int n;
                scanf("%d",&n);
                while(n--){
                    insertb();
                }
            }
            break;
            case 1: inserte();
            break;
            case 2:insertb();
            break;
            case 3: display();
            break;
            case 4: delate();
            break;
            case 5: delatb();
            break;
            case 6: exit(0);
        }
        }    return 0;
}
