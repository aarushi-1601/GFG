//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
  int length(Node *head) {
    Node *cur = head;
    int size = 0;
    while (cur) {
      size += 1;
      cur = cur->next;
    }
    return size;
  }

  Node *reverse(Node *head) {
    Node *current = head;
    Node *prev = nullptr;
    while (current) {
      Node *nextNode = current->next;
      current->next = prev;
      prev = current;
      current = nextNode;
    }
    return prev;
  }

public:
  Node *subLinkedList(Node *head1, Node *head2) {
    while (head1 && head1->data == 0) {
      head1 = head1->next;
    }
    while (head2 && head2->data == 0) {
      head2 = head2->next;
    }

    if (!head1 && !head2) {
      return new Node(0);
    }

    int n1 = length(head1);
    int n2 = length(head2);

    if (n2 > n1) {
      return subLinkedList(head2, head1);
    }

    if (n1 == n2) {
      Node *temp1 = head1;
      Node *temp2 = head2;

      while (temp1->data == temp2->data) {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (!temp1) {
          return new Node(0);
        }
      }

      if (temp2->data > temp1->data) {
        return subLinkedList(head2, head1);
      }
    }

    Node *h1 = reverse(head1);
    Node *h2 = reverse(head2);

    Node *result = nullptr;
    Node *current = nullptr;
    int borrow = 0;

    while (h1 || h2 || borrow) {
      int c1 = h1 ? h1->data : 0;
      int c2 = h2 ? h2->data : 0;

      c1 -= borrow;

      if (c1 < c2) {
        c1 += 10;
        borrow = 1;
      } else {
        borrow = 0;
      }

      int diff = c1 - c2;

      Node *newNode = new Node(diff);
      if (!result) {
        result = newNode;
        current = result;
      } else {
        current->next = newNode;
        current = newNode;
      }

      if (h1) h1 = h1->next;
      if (h2) h2 = h2->next;
    }

    Node *res = reverse(result);
    while (res && res->data == 0) {
      res = res->next;
    }
    return res;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends