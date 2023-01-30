#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct poly
{
    int coef , powx,powy,powz,flag;
    struct poly* next;
};
typedef struct poly poly;
poly* getnode()
{
  poly* p = (poly*)malloc(sizeof(poly));
  p->next =p;
  return p;

}
poly* insertrear(poly* head,poly* p)
{ poly* h = head->next;

    while(h->next!=head) h = h->next;
    h->next = p;
    p->next = head;
    return head;

}
int com(poly* h1,poly* h2)
{
    if(h1->powx == h2->powx && h1->powy == h2->powy && h1->powz == h2->powz) return 1;
    return 0;
}
poly* readpoly(poly* head)
{
    printf("enter the no of terms\n");
    int n;
    scanf("%d",&n);
    while(n--)
{    poly* p =getnode();
    printf("enter pow x,y and z\n");
  scanf("%d %d %d",&p->powx,&p->powy,&p->powz);
  printf("enter the coefficient\n");
  scanf("%d",&p->coef);
  p->flag =0;
  insertrear(head,p);
}
    
}
void display(poly* head)
    {
        poly* h =head->next;
        while(h!=head){
        printf("%dx^%dy^%dz^%d",h->coef,h->powx,h->powy,h->powz);
        h = h->next;
        if(h!=head) printf(" + ");
        }
    }
void evaluate()
{
   poly* head = getnode();
   head->next = head;
   readpoly(head);
   display(head);
   printf("enter the value of x y and z\n");
   int x,y,z;
   scanf("%d %d %d",&x,&y,&z);
 poly* h =head->next;
   long ans=0;
   while(h!=head)
   {
     ans+= h->coef*(pow(x,h->powx)*(pow(y,h->powy)*(pow(z,h->powz))));
     h = h->next;
   }
   printf("eval is %ld",ans);
}
void sum()
{
    poly* head1 =getnode();
    poly* head2 = getnode();
    readpoly(head1);
    readpoly(head2);
    printf("poly1 = ");
    display(head1);
    printf("poly2 = ");
    display(head2);
    poly* h1=head1->next;
    poly* h2 = head2->next;
    while(h1!=head1)
    {
         h2 = head2->next;
        while(h2 != head2)
        {
            if(h2->flag == 0){
            if(com(h1,h2)) 
            {h1->coef+=h2->coef;
            h2->flag=1;
            }
            }
            h2 = h2->next;
        }
        h1 = h1->next;
    }
    h2 = head2->next;
    while(h2!=head2)
    {
        if(h2->flag == 0)
        {
            poly* p =getnode();
            p->coef = h2->coef;
            p->powx = h2->powx;
            p->powy = h2->powy;
            p->powz = h2->powz;
            insertrear(head1,p);
            h2->flag =1;
        }
        h2 = h2->next;
    }
    printf("sum is ");
    display(head1);
}
void main()
{
   evaluate();
    sum();
}
