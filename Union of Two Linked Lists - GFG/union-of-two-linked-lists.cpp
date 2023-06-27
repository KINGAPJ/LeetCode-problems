//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution{
    public:
    Node* merge(Node *l1, Node *l2){
        Node* ptr = new Node(0);
        Node* curr = ptr;
        while(l1 && l2){
            if(l1->data <= l2->data){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        //for unequal length
        if(l1){
            curr->next = l1;
            l1 = l1->next;
        }
        if(l2){
            curr->next = l2;
            l2 = l2->next;
        }
        return ptr->next;
    }
    Node* mergeSort(Node* head){
        if(!head || !head->next)
            return head;
        Node *temp = nullptr, *slow = head, *fast = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL; //terminating one half
        Node* l1 = mergeSort(head);
        Node* l2 = mergeSort(slow);
        return merge(l1, l2);
    }
    Node* makeUnion(Node* head1, Node* head2){
        Node* temp = head1;
        while(temp->next)
            temp = temp->next;
        temp->next = head2;
        head1 = mergeSort(head1);
        temp = head1;
        while(temp->next){
            if(temp->next->data == temp->data){
                Node* dum = temp->next->next;
                delete(temp->next);
                temp->next = dum;
            }else{
                temp = temp->next;
            }
        }
        return head1;
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends