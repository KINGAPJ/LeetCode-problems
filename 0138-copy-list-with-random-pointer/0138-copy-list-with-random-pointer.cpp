/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*
        given: 7->13->11->10->1
        we do: step 1:
             orig:    7     13    11    10    1   N
                      |   ^  |  ^ |   ^  |  ^ |  ^          
                      v  /   v /  v  /   v /  v /   
             copy:    7     13    11    10    1   
             
             step 2: now we assign random pointers of next of original ones
             
             step 3: now we make every alternate node next in copy
    
    */
    Node* copyRandomList(Node* head) {
        if(!head)
            return head; 
        Node *temp, *current; 
        current = head; 
        while(current){   //step 1
            temp =  current->next;  
            Node *n = new Node(current->val);  
            current->next = n;  
            n->next = temp;  
            current = temp; 
        } 
        current = head; 
        while(current){  //step 2
            if(current->random)
                current->next->random = current->random->next;  
            current = current->next->next;      
        }
        Node *copy; 
        temp = head->next; 
        current = head; 
        copy = temp; 
        while(current && copy){ //step 3
            current->next = current->next->next; 
            current = current->next; 
            if(copy->next)
                copy->next = copy->next->next; 
            copy = copy->next;    
        }
        return temp;
    }
};