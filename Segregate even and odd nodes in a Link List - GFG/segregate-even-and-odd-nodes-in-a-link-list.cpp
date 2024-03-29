//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
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
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
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
    Node* divide(int N, Node *head){
        // code here
        Node *even = nullptr, *odd = nullptr, *oddst = nullptr, *evest = nullptr;
        while(head){
            if(head->data & 1){
                if(!odd){
                    odd = head;
                    oddst = odd;
                }
                else{
                    odd->next = head;
                    odd = odd->next;
                }
            }else{
                if(!even){
                    even = head;
                    evest = even;
                }
                else{
                    even->next = head;
                    even = even->next;
                }
            }
            head = head->next;
        }
        if(oddst)
            odd->next = NULL;
        if(evest)
            even->next = oddst;
        return evest == NULL ? oddst : evest;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends