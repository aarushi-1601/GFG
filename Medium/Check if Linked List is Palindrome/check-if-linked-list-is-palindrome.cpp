//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        int n=findlen(head)/2;
        Node *p=head;
        while(0<n){
            p=p->next;
            n--;
        }
        if(findlen(head)%2==1){
            p=p->next;
        }
        Node *half=reverse(p);
        Node *r=head;
        Node *q=half;
        
        while(r!=p&&q!=NULL){
            if(r->data!=q->data){
                return false;
            }
            r=r->next;
            q=q->next;
        }
        
        
        return true;
    }
    Node* reverse(Node *head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node *res=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return res;
    }
    int findlen(Node *head){
        int len=0;
        if(head==NULL){
            return 0;
        }
        Node *p=head;
        while(p!=NULL){
            p=p->next;
            len++;
        }
        return len;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends