/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<algorithm>
using namespace std;
struct node{
    int data,height;
    node* left,*right;
    node(int n)
    {
        this->data = n;
        this->height = 1;
        this->left  = this->right= NULL;
    }
};
int h(node* r)
{
    if(!r) return 0;
    return r->height;
}
node* root = NULL;
node* ll(node* &r){
    node* t  = r->left;
    node* t1 = t->right;
    r->left = t1;
    t->right = r;
    r->height = max(h(r->left),h(r->right))+1;
    t->height = max(h(t->left),h(t->right))+1;
    return t;
}
node* rr(node* &r){
    node* t  = r->right;
    node* t1 = t->left;
    r->right = t1;
    t->left = r;
    r->height = max(h(r->left),h(r->right))+1;
    t->height = max(h(t->left),h(t->right))+1;
    return t;
}
node* lr(node* &r)
{
    r->left = rr(r->left);
    r = ll(r);
    return r;
}
node* rl(node* &r)
{
    r->right = ll(r->right);
    r = rr(r);
    return r;
}
void insert(node* &r,int n)
{
    if(!r){
        r= new node(n);
        return;
    }
    if(r->data>n){
        insert(r->left,n);
    }
    else{
        insert(r->right,n);
    }
    if(h(r->left) - h(r->right) == 2)
    {
        if(r->left->data> n) r = ll(r);
        else r = lr(r);
    }
    else if(h(r->left) - h(r->right) == -2)
    {
        if(r->right->data< n) r = rr(r);
        else r=  rl(r);
    }
        r->height = max(h(r->left), h(r->right))+1;

}
void inorder(node* r)
{
    if(!r) return;
    inorder(r->left);
    cout<<r->data;
    inorder(r->right);
}
int main()
{
   
    insert(root , 3);
    insert(root,7);
     insert(root,2);
      insert(root,1);
       insert(root,5);
    inorder(root);

    return 0;
}
