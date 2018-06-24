///dynamic structures.
///Kyande Michael John.
///P15/34906/2014.

#include <iostream>
#include <string>

using namespace std;
///prototype.
void display();
///create node with data field and address field to link with next node.
class node{
public:
    string val;///data field.
    node *NXTptr;///next node address.
};///end of class.
node *conductor;///global.
node *lead;
node *trail;
node *pointer;
int main()///main function
{
    int n,c,counter=0;
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
                trail = lead;
            }
            if(counter != 1){
                trail->NXTptr = conductor;
                trail = conductor;
            }
            if(counter == n){
                conductor->NXTptr =NULL;
            }
        }
    }
    cout << "\n\n\nThe following are operations that can be done one the list:\n";
    start2:
    cout << "1.To search for an element in the list.\n";
    cout << "2.To insert a new element before a certain element.\n";
    cout << "3.To insert a new element after a certain element.\n";
    cout << "4.To delete an element from a list.\n";
    cout << "5.To stop.\n";
    start1:///label.
    cin >> c;
    switch(c){///switch case.
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
            conductor = conductor->NXTptr;
            }
            cout << "The element is not in the list!\n\n";
            goto start2;
        }
        case 2:{
            cout << "enter the element to insert before\n";
            cin >> x;
            conductor = lead;
            while (conductor->val != x){
                trail = conductor;
                conductor = conductor->NXTptr;
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
                pointer->NXTptr= conductor;
            }
            else{
                trail->NXTptr=pointer;
                pointer->NXTptr=conductor;
            }
            display();
            goto start2;
        }
        case 3:{
            cout << "enter the element to insert after\n";
            cin >> x;
            conductor = lead;
            while (conductor->val != x){
                trail = conductor;
                conductor = conductor->NXTptr;
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
            if(conductor->NXTptr==NULL){
                conductor->NXTptr=pointer;
                pointer->NXTptr=NULL;
            }
            else{
                pointer->NXTptr=conductor->NXTptr;
                conductor->NXTptr=pointer;
            }
            display();
            goto start2;
        }
        case 4:{
            cout << "enter element to delete:\n";
            cin >> x;
            conductor = lead;
            while (conductor->val != x){
                trail = conductor;
                conductor = conductor->NXTptr;
                if(conductor!=NULL){
                    continue;
                }
                else{
                    cout << "The element is not in the list!\n\n";
                    goto start2;
                }
            }
            if(conductor == lead){
                lead =conductor->NXTptr;
                conductor=NULL;
            }
            else{
                trail->NXTptr=conductor->NXTptr;
                conductor=NULL;
                trail=NULL;
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
    }///end of switch case.
    end:///label
    conductor = NULL;
    trail = NULL;
    return 0;///successful termination.
}///end of main.
void display(){
    if (lead == NULL){
        cout << "the lists is empty\n" << endl;
        cout << "unable to do operations on the list\n";
    }
    else{
        cout << "list is present\n" << endl;
        conductor=lead;
        cout << "list elements are:\n";
        while (conductor->NXTptr!=NULL){
            cout << conductor->val<<endl;
            conductor=conductor->NXTptr;
        }
        cout << conductor->val << "\n\n\n" << endl;
    }
}
