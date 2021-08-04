#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include "hosplaydef.h"
#include <iomanip>
using namespace std;
int main()
{   
	system("Color B4");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tPress Any key to continue";
    getchar();
    system ("CLS");
    SplayTree st;
    splay *root;
    root = NULL;
    const int length = 10;
    int i;
    int choice;
    hospital h;
    while(1)
    {   
        system ("CLS");
	    cout<<"**********************HOSPITAL*********************\n";
        //MessageBox(0,"1. Insert Patient\n2. Delete Patient\n3. Search Patient\n4. Display most recently Searched Patient\n5. Display All patient details stored in the Database\n6. Exit Program", "HOSPITAL", MB_OKCANCEL);
        cout<<"1. Insert Patient"<<endl;
        cout <<"2. Delete Patient"<<endl;
        cout<<"3. Search Patient"<<endl;
        cout<<"4. Display most recently Searched Patient"<<endl;
        cout<<"5. Display All patient details stored in the Database"<<endl;
        cout<<"6. Exit Program"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        cout<<"\n";
        int input;
        system ("CLS");
        switch(choice)
        {
        case 1:
            cout<<"\nEnter Patient number to be inserted: ";
            cin>>input;
            cout<<"\nEnter Patient name:";
            cin>>h.pname;
            cout<<"\nEnter Patient Age:";
            cin>>h.age;
            cout<<"\nEnter Insurance ID:";
            cin>>h.Inc_id;
            cout<<"\nEnter Patient Gender:";
            cin>>h.gender;
            cout<<"\nEnter Patient Email:";
            cin>>h.email;
            cout<<"\nEnter Patient Phone No:";
            cin>>h.phone;
            root = st.Insert(input,h,root);
            cout<<"\nAfter Insert: "<<input<<endl;
            st.InOrder(root);
            MessageBox(0,("PATIENT "+h.pname+" INSERTED!!!").c_str(), "INSERTION", MB_OK|MB_ICONQUESTION);
            cout<<"\nPress any key to continue......";
            cin.ignore(256,'\n');
			getchar();
            break;
        case 2:
            cout<<"Enter Patient to be deleted-:";
            cin>>input;
            root = st.Delete(input, root);
            cout<<"\nAfter Delete: "<<input<<endl;
            st.InOrder(root);
            cout<<"\nPress any key to continue......";
            cin.ignore(256,'\n');
			getchar();
            break;
            
        case 3:
            cout<<"\nEnter Patient No to be searched: ";
            cin>>input;
            root = st.Search(input, root);
            if(root->key == input){
                cout<<"\nElement to be searched is found";
                cout<<"\nAfter Search "<<input<<endl;
                st.InOrder(root);
            }
            else{
                cout<<"Element Not found";
            }
            cout<<"\nPress any key to continue......";
            cin.ignore(256,'\n');
			getchar();
            break;
 
        case 4:
            
            cout<<"\nMost Recent Searched element: ";
            cout<<"\nKey:";
            cout<<root->key;
            cout<<"\nName:";
            cout<<root->val.pname;
            cout<<"\nPress any key to continue......";
            cin.ignore(256,'\n');
			getchar();
            break;
        case 5:
            
            cout<<setw(50)<<"PATIENT DETAILS\n";
            cout<<"\n";
            cout<<setw(15)<<"PATIENT NO"<<setw(15)<<"NAME"<<setw(15)<<"PHONE"<<setw(20)<<"EMAIL"<<setw(15)<<"GENDER"<<setw(15)<<"INC_ID";
            cout<<"\n";
            st.PreOrder(root);
            cout<<"\nPress any key to continue......";
            cin.ignore(256,'\n');
			getchar();
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"\nInvalid type! \n";
        }
    }
    cout<<"\n";
    return 0;
}
