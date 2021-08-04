#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include "hosplay.h"
#include <iomanip>
using namespace std;
splay*SplayTree::RR_Rotate(splay*k2)
{
    splay* k1 = k2->lchild;
    k2->lchild = k1->rchild;
    k1->rchild = k2;
    return k1;
}
splay*SplayTree::LL_Rotate(splay* k2)
{
    splay* k1 = k2->rchild;
    k2->rchild = k1->lchild;
    k1->lchild = k2;
    return k1;
}
splay*SplayTree::Splay(int key, splay* root)
{  
    if (root == NULL || root->key == key)  
    return root;  
    if (root->key > key) 
    {  
        if (root->lchild == NULL) 
		return root;
        if (root->lchild->key > key)
        {  
            root->lchild->lchild = Splay(key , root->lchild->lchild);  
            root = RR_Rotate(root);  
        }  
        else if (root->lchild->key < key)   
        {  
            root->lchild->rchild = Splay(key , root->lchild->rchild);   
            if (root->lchild->rchild != NULL)  
            root->lchild = LL_Rotate(root->lchild);  
        }  
        return (root->lchild == NULL)? root: RR_Rotate(root);  
    }  
    else  
    {    
        if (root->rchild == NULL) 
		return root;  
        if (root->rchild->key > key)  
        {   
            root->rchild->lchild = Splay(key , root->rchild->lchild);    
            if (root->rchild->lchild != NULL)  
            root->rchild = RR_Rotate(root->rchild);  
        }  
        else if (root->rchild->key < key)
        {    
            root->rchild->rchild = Splay(key , root->rchild->rchild);  
            root = LL_Rotate(root);  
        }  
        return (root->rchild == NULL)? root: LL_Rotate(root);  
    }  
}
splay* SplayTree::New_Node(int key,hospital h)
{
    splay* p_node = new splay;
    if (!p_node)
	{
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    p_node->key = key;
    p_node->val.pname = h.pname;
    p_node->val.age = h.age;
    p_node->val.phone = h.phone;
    p_node->val.email = h.email;
    p_node->val.gender = h.gender;
    p_node->val.Inc_id = h.Inc_id;
    p_node->lchild = p_node->rchild = NULL;
    return p_node;
}
splay* SplayTree::Insert(int key,hospital h, splay* root)
{
    splay* p_node = NULL;
    if (!p_node)
	p_node = New_Node(key,h);
    else
    p_node->key = key;
    if (!root)
    {
        root = p_node;
        p_node = NULL;
        return root;
    }
    root = Splay(key, root);
    if (key < root->key)
    {
        p_node->lchild = root->lchild;
        p_node->rchild = root;
        root->lchild = NULL;
		root = p_node;
    }
    else if (key > root->key)
    {
        p_node->rchild = root->rchild;
        p_node->lchild = root;
        root->rchild = NULL;
        root = p_node;
    }
    else
    return root;
    p_node = NULL;
    return root;
}
splay* SplayTree::Delete(int key, splay* root)
{
    splay* temp;
    if (!root)
    return NULL;
    root = Splay(key, root);
    if (key != root->key)
	{
        cout<<"\n"<<key<<" is not present in the tree";
        return root;
	}
    else
    {
        if (!root->lchild)
        {
            temp = root;
            root = root->rchild;
        }
        else
        {
            temp = root;
            root = Splay(key, root->lchild);
            root->rchild = temp->rchild;
        }
        MessageBox(0,("PATIENT "+temp->val.pname+" DELETED!!!").c_str(), "DELETION", MB_OK|MB_ICONQUESTION);
        free(temp);
        return root;
    }
}
splay* SplayTree::Search(int key, splay* root)
{
    return Splay(key, root);
}
void SplayTree::InOrder(splay* root)
{   
    if (root)
    {
        InOrder(root->lchild);
        cout<< "key: " <<root->key;
        if(root->lchild)
            cout<< " | left child: "<< root->lchild->key<<"\n";
        if(root->rchild)
            cout << " | right child: " << root->rchild->key<<"\n";
        cout<< "\n";
        InOrder(root->rchild);
    }
}
void SplayTree::PreOrder(splay *root)
{
    if(root)
	{
        cout<<setw(15)<<root->key<<setw(15)<<root->val.pname<<setw(15)<<root->val.phone<<setw(20)<<root->val.email<<setw(15)<<root->val.gender<<setw(15)<<root->val.Inc_id;
        cout<<"\n";
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}
