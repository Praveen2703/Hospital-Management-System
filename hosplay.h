#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
struct hospital
{
    string pname;
    char gender;
    long Inc_id;
    int age;
    string phone;
    string email;
};
struct splay
{
    int key;
    hospital val;
    splay* lchild;
    splay* rchild;
};
class SplayTree
{
    public:
    	splay* RR_Rotate(splay*);
        splay* LL_Rotate(splay*);
        splay* Splay(int, splay*);
        splay* New_Node(int,hospital);
        splay* Insert(int,hospital, splay*);
        splay* Delete(int, splay*);
        splay* Search(int, splay*);
        void InOrder(splay*);
        void PreOrder(splay*);
};
