//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
    Node* rev(struct Node* head){
        Node *prev = nullptr, *next = nullptr;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    Node* modifyTheList(struct Node *head){
        //add code here.
        int n = 0;
        Node* trav = head;
        while(trav){
            n++;
            trav = trav->next;
        }
        trav = head;
        for(int i = 0; i < (n-1)/2; i++)
            trav = trav->next;
        trav->next = rev(trav->next);
        trav = head;
        Node* trav1 = trav;
        for(int i = 0; i < (n+1)/2; i++){
            trav1 = trav1->next;
        }
        int temp = -1;
        for(int i = 0; i < n/2; i++){
            // cout<<trav->data<<' '<<trav1->data<<'\n';
            temp = trav->data;
            trav->data = trav1->data - trav->data;
            trav1->data = temp;
            trav = trav->next;
            trav1 = trav1->next;
        }
        trav = head;
        for(int i = 0; i < (n-1)/2; i++)
            trav = trav->next;
        trav->next = rev(trav->next);
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends