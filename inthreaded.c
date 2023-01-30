#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    bool lt,rt; //if left ptr is a thread , lt =true. same applies for rt
    struct node* left,*right; //left ptr and right ptr 
}typedef node;

node* getnode(int n)
{
    node* t = (node*)malloc(sizeof(node));
    t->lt = t->rt = true;
    t->left = t->right = NULL;
    t->data = n;
}
node* insert(node* root , int data)
{
    if(!root) return root = getnode(data);
    node* cur = root,*par = NULL;
    while(cur) // go to the desired location for the input
    {
        par = cur;
        if(data == cur->data) return root;
        if(data< cur->data)
        {
            if(!cur->lt) cur = cur->left; 
            else break; // this is the place for the node to be inserted
        }
        else{
            if(!cur->rt) cur = cur->right;
            else break; // this is the place for the node to be inserted
        }
    }
    node* t =getnode(data); //create the node and insert
    if(data< par->data)
    {
        t->right = par;
        t->left = par->left;
        par->left = t;
        par->lt = false;//this link is no longer a thread 
    }
    else{
        t->right = par->right;
        t->left = par;
        par->right = t;
        par->rt= false;
    }
    return root;
}
node* successor(node* r)
{ if(r->rt) return r->right; //if right ptr is a thread return r->right
     r = r->right; //else go to the right 
    while(!r->lt) r = r->left; //go to the left until left ptr is a thread and return
    return r;
}
void inorder(node* r)
{
    while(!r->lt) r = r->left;
   while(r) // print until you encounter a null node i.e until you traverse the whole tree
   {
    printf("%d ",r->data);
    r = successor(r); //returns the next node in the inorder traversal
   }
}
int main()
{
    node* root = NULL;
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,1);
    root = insert(root,32);
    root = insert(root,3);
    inorder(root);
    
    return 0;
}
