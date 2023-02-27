//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
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
*/


class Solution
{
public:
   Node* insert(Node* head,int val){
       if(head==NULL){
           head=new Node(val);
       }
       else{
           Node* t=new Node(val);
           t->next=head;
           head=t;
       }
       return head;
   }
    Node *reverse(Node *head, int k)
    {
        Node *l=NULL,*r=NULL,*fin=NULL;
        Node *temp=head;
        while(k--){
            l=insert(l,temp->data);
            temp=temp->next;
        }
        while(temp!=NULL){
            r=insert(r,temp->data);
            temp=temp->next;
        }
        fin=l;
        while(fin->next!=NULL){
            fin=fin->next;
        }
        fin->next=r;
        return l;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends