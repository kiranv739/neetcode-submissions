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
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp = head;

        while(temp!=NULL){
            Node* copy = new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->random!=NULL) temp->next->random = temp->random->next;
            else temp->next->random = NULL;
            temp = temp->next->next;
        }
        temp = head;
        Node* dummy = new Node(-1);
        Node* ans = dummy;
        while(temp!=NULL){
            dummy->next = temp->next;
            dummy = dummy->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
    
    return ans->next;
    }
};
