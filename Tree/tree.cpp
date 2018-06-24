//header file.
#include <iostream>
#include <string>

using namespace std;

//defined data structure.
class node{
public:
	node *Lchild;//points to the address of the left child.
	string val;//store data.
	node *Rchild;//points to the address of the right child.
	
};
// global variable.
node *root;
node *conductor;
node *p;

// main program.
int main()
{
	/* code */
	int top,y;
	node *s[top];//stack
	string x;

	conductor = new node;
	root = conductor;
	cin >> x;
	conductor->val = x;
	conductor = NULL;

	conductor = new node;
	root->Lchild = conductor;
	cin >> x;
	conductor->val = x;
	conductor->Lchild = NULL;
	conductor->Rchild = NULL;
	conductor = NULL;

	conductor = new node;
	root->Rchild = conductor;
	cin >> x;
	conductor->val = x;
	conductor->Rchild = NULL;
	conductor = NULL;

	conductor = new node;
	(root->Rchild)->Lchild = conductor;
	cin >> x;
	conductor->val = x;
	conductor->Rchild = NULL;
	conductor->Lchild = NULL;
	conductor = NULL;

	cout << "\n";

	start1:	
	cout << "1-to print the list in inorder traversal\n";
	start2:
	cout << "2-to print the list in preorder traversal\n";
	cout << "3-to insert new root\n";
	cout << "4-to insert a new node\n";
	cout << "5-to exit\n";
	cin >> y;
	switch(y){
	case 1:{
		cout << "inorder traversal of the tree:\n";
		if (root != NULL)
		{
		/* code */
			p = root;
			top = 0;
			while(p != NULL){
				top=top+1;
				s[top]=p;
				p=p->Lchild;
				while(p == NULL)
				{
					if (top != 0){
						p = s[top];
						top=top-1;
						cout << p->val<< "\n";
						p=p->Rchild;
					}
					else{
						break;
					}
				}
			}
		goto start1;
		}
		else{
			cout << "the list is empty\n";
			goto end;
		}
	}
	case 2:{
		if (root != NULL){
			cout << "preorder traversal of the tree:\n";
			p = root;
			top = 0;
			while(p!=NULL)
			{
				while(p!=NULL){
					top=top+1;
                	s[top]=p;
                	cout << p->val << "\n";
                	p=p->Lchild;
                	while(p==NULL){
                		if(top!=0){
                			p=s[top];
                    		top=top-1;
                    		p=p->Rchild;
                    	}
                    	else{
                    		break;
                    	}
                    }
                }
            }
        goto start1;
        }
        else{
        	cout << "the lists is empty\n" << endl;
        	goto end;
        }
	}
	case 3:{
		if (root != NULL){
			cout << "Please enter new node to replace root:\n";
			cin >> x;

			conductor = new node;
			conductor->val=x;

			conductor->Lchild=root;
			root = conductor;
			conductor->Rchild=NULL;
			conductor=NULL;

			goto start2;
		}
		else{
			cout << "tree is empty\n";
			goto end;
		}
	}
	case 4:{
		if (root != NULL){
			if (root != NULL){
				p = root;
				top = 0;
				while()
			}
			else{
				cout << "tree is empty\n";
				goto end;
			}			
		}
		else{
			cout << "tree is empty\n";
			goto end;
		}
	}
	case 5:{
		goto end;
	}
	default:{
		cout << "Invalid entry try again\n";
		goto start1;
	}
}
	end:
	return 0;// successful execution.
}//end of main.