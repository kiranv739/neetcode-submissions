/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* getNode(ListNode *temp,int k){
        int cnt = 1;
        while(temp!=NULL && cnt!=k){
            temp = temp->next;
            cnt++;
        }
        return temp;
    }

    ListNode* reverse(ListNode* temp){
        ListNode* prev = NULL;

        while(temp!=NULL){
            ListNode* nextnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextnode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* knode;
        ListNode* prevnode = NULL;
        ListNode* nextnode;

        while(temp!=NULL){
           knode = getNode(temp,k);
           if(knode == NULL){
            if(prevnode!=NULL) prevnode->next = temp;
            break;
           }
           else{
            nextnode = knode->next;
            knode->next = NULL;
            reverse(temp);
            if(temp==head){
                head = knode;
            }
            else{
                prevnode->next = knode; 
            }
           }
           prevnode = temp;
           temp = nextnode;
        }
    return head;
        
    }
};
