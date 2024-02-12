//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node* newIntersectionLL = new Node(-1);
        Node* current = newIntersectionLL;
    
        Node* temp1 = head1;
        Node* temp2 = head2;

        while(temp1 != NULL && temp2!= NULL) {
            // if values are same (intersecting data)
                if(temp1->data == temp2->data) {
                Node* newnode = new Node(temp1->data); // create a new node for that value 
            
                current->next = newnode; // add the newnode to "newIntersectionLL" LIST 
                current = current->next;

                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->data < temp2->data) {  //IF data in first List1 is smaller than L2
                temp1 = temp1->next;
            }
            else if(temp1->data > temp2->data){ //IF data in first List1 is larger than L2
                temp2 = temp2->next;
            }
        }
        return newIntersectionLL->next;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends