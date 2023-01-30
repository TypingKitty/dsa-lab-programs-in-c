#include <stdio.h>
#include<stdlib.h>
#include<string.h>
const int hashsize = 4;//const of your wish
struct emp {
    int id;
    char name[100];
};
typedef struct emp emp;
int hash(int id)
{
    return id%hashsize; //hash function
}
int main()
{
    emp hasht[hashsize]; //hashtable
    int n;
    FILE *o,*r;
    emp e;
    printf("no of student\n");
    scanf("%d",&n);
    o = fopen("a.txt","r");//input file path
    for(int i=0;i<hashsize;i++)
    {
        hasht[i].id =-1;//to identify if the bucket is empty or not
    }
    for(int i=0;i<n;i++)
    {
        int id;
        char name[100];
        fscanf(o,"%d %s",&id,name);//reading from the input file
        int index = hash(id);
        int j =index;
        do{
            if(hasht[j].id == -1) //if bucket at the index is empty then fill in the value and break
            {
                hasht[j].id = id;
                strcpy(hasht[j].name,name);
                printf("hashvalue = %d\tid = %d\tname = %s\n",index,hasht[j].id,hasht[j].name);
                break;
            }
            j++;             //else linear probing
            j = j%hashsize;
            if(j == index) // if we did not find any empty space then the table is full
            {
                printf("table is full\n");
                break;
            }
        }while(1);
       
    }
    r = fopen("r.txt","w+");//output file
    //writing in a file
    for(int i =0;i<hashsize;i++)
        {
            if(hasht[i].id == -1)
            {
                fprintf(r,"%s","###\n");
                
            }
            else{
                fprintf(r,"id = %d  name = %s\n",hasht[i].id,hasht[i].name);
            }
        }
    return 0;
}
