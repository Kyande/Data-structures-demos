///dynamic structures.
///double linked list.
///p15/34906/2014.

#include <iostream>
#include <string>

using namespace std;

void display();///prototype.

class node{
public:
    node *Llink;
    string val;
    node *Rlink;
};///end of class node.
node *lead;
node *pointer;
node *conductor;
int main()
{
    int n,counter,c=0;
    string x;
    cout << "enter the number of elements:\n";
    start:///label.
    cin >> n;
    if (n<=0){
        cout << "Invalid entry enter again\n";
        goto start;
    }
    else{
        cout << "enter values for the list.\n";
        for(counter=1;counter<=n;counter++){
            cin >> x;
            conductor = new node;
            conductor->val=x;
            if(counter == 1){
                lead = conductor;
                pointer = lead;
                pointer->Llink=NULL;
            }
            if(counter != 1){
                conductor->Llink = pointer;
                pointer->Rlink = conductor;
                pointer = conductor;
            }
            if(counter == n){
                conductor->Rlink = NULL;
            }
        }
    }
    display();///display the list.
    cout << "\n\n\nThe following are operations that can be done one the list:\n";
    start2:
    cout << "1.To search for an element in the list.\n";
    cout << "2.To insert a new element before a certain element.\n";
    cout << "3.To insert a new element after a certain element.\n";
    cout << "4.To delete an element from a list.\n";
    cout << "5.To stop.\n";
    start1:///label.
    cin >> c;
    switch(c){
        case 1:{
            cout << "enter the element to search for:\n";
            cin >> x;
            conductor = lead;
            while (conductor != NULL){
                if (conductor->val == x)
                {
                    cout << "Element found\n";
                    goto start2;
                }
            conductor = conductor->Rlink;
            }
            cout << "The element is not in the list!\n\n";
            goto start2;
        }
        case 2:{
            cout << "enter the element to insert before\n";
            cin >> x;
            conductor = lead;
            while (conductor->val != x){
                conductor = conductor->Rlink;
                if(conductor!=NULL){
                    continue;
                }
                else{
                    cout << "The element is not in the list!\n\n";
                    goto start2;
                }
            }
            cout << "enter the element to insert\n";
            cin >> x;
            pointer = new node;
            pointer->val=x;
            if(conductor==lead){
                lead = pointer;
                lead->Llink = NULL;
                lead->Rlink = conductor;
            }
            else{
                pointer->Llink = conductor->Llink;
                pointer->Rlink = conductor;
                (conductor->Llink)->Rlink = pointer;
                conductor->Llink = pointer;
            }
            display();
            goto start2;
        }
        case 3:{
            cout << "enter the element to insert after\n";
            cin >> x;
            conductor = lead;
            while (conductor->val != x){
                conductor = conductor->Rlink;
                if(conductor!=NULL){
                    continue;
                }
                else{
                    cout << "The element is not in the list!\n\n";
                    goto start2;
                }
            }
            cout << "enter the element to insert\n";
            cin >> x;
            pointer = new node;
            pointer->val=x;
            if(conductor->Rlink==NULL){
                conductor->Rlink = pointer;
                pointer->Llink = conductor;
                pointer->Rlink = NULL;
            }
            else{
                pointer->Rlink = conductor->Rlink;
                pointer->Llink = conductor;
                (conductor->Rlink)->Llink = pointer;
                conductor->Rlink = pointer;
            }
            display();
            goto start2;
        }
        case 4:{
            if(lead->Rlink == NULL){
                lead = NULL;
            }
            else{
                cout << "enter element to delete:\n";
                cin >> x;
                conductor = lead;
                while (conductor->val != x){
                    conductor = conductor->Rlink;
                    if(conductor!=NULL){
                        continue;
                    }
                    else{
                        cout << "The element is not in the list!\n\n";
                        goto start2;
                    }
                }
                if(conductor == lead){
                    lead = lead->Rlink;
                    lead->Llink = NULL;
                }
                else{
                    (conductor->Llink)->Rlink = conductor->Rlink;
                    (conductor->Rlink)->Llink = conductor->Llink;
                }
            }
            display();
            goto start2;
        }
        case 5:{
            goto end;
        }
        default:{
            cout << "Invalid operation try again.\n";
            goto start1;
        }
    }
    end:
    pointer = NULL;
    conductor= NULL;
    return 0;
}///end of main.
void display(){
    if (lead == NULL){
        cout << "the lists is empty\n" << endl;
        cout << " no more operation possible press 5 to exit!!\n\n\n";
    }
    else{
        cout << "list is present\n" << endl;
        conductor=lead;
        cout << "list elements are:\n";
        while (conductor->Rlink!=NULL){
            cout << conductor->val<<endl;
            conductor=conductor->Rlink;
        }
        cout << conductor->val << "\n\n\n" << endl;
    }
}


