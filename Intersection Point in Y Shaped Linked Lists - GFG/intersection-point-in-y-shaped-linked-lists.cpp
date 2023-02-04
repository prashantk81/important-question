//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        Node* ptr1=head1;
        int count1=0;
        while(ptr1)
        {
            count1++;
            ptr1=ptr1->next;
        }
        Node* ptr2=head2;
        int count2=0;
        while(ptr2)
        {
            count2++;
            ptr2=ptr2->next;
        }
        ptr1=head1;
        ptr2=head2;
        // cout<<count1<<" "<<count2<<endl;
        if(count1>count2)
        {
            int newcount=count1-count2;
            while(newcount)
            {
                ptr1=ptr1->next;
                newcount--;
            }
        }
        else
        {
            int newcount=count2-count1;
            while(newcount)
            {
                ptr2=ptr2->next;
                newcount--;
            } 
        }
        // cout<<ptr1->data<<" "<<ptr2->data<<endl;
        while(ptr1 && ptr2 && ptr1!=ptr2)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        if(ptr1->data==ptr2->data)
        {
            return ptr1->data;
        }
        return -1;
        
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends