//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     Node* reverse(Node* head){
        Node* prev=NULL;
    Node* curr=head;
    Node* after;
    while(curr!=NULL){
         after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
       
    }
    return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int add=0,carry=0;
    Node* temp1=reverse(first);
    Node* temp2=reverse(second);
    stack<int> s;
    while(temp1!=NULL&&temp2!=NULL){
    add=temp1->data+temp2->data+carry;
    carry=0;
    if(add<=9){
        s.push(add);
    }
    else{
        s.push(add%10);
        carry=add/10;
    }
       temp1=temp1->next;
       temp2=temp2->next;
    }
    
  while(temp1!=NULL){
        add=temp1->data+carry;
    if(add<=9){
        s.push(add);
           carry=0;
    }
    else{
        s.push(add%10);
        carry=add/10;
    }

        temp1=temp1->next;
    }
    
    
     while(temp2!=NULL){
             add=temp2->data+carry;
    if(add<=9){
        s.push(add);
           carry=0;
    }
    else{
        s.push(add%10);
        carry=add/10;
    }
 
            temp2=temp2->next;
        }
    if(carry!=0){
        s.push(carry);
    }
    Node* sum=new Node(s.top());
    Node*ans=sum;
    s.pop();
    while(!s.empty()){
        sum->next=new Node(s.top());
        s.pop();
        sum=sum->next;
    }
    return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends