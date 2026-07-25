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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp!=NULL){
        ListNode* front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* right = reverse(slow->next);
        slow->next = nullptr;
        ListNode* left = head;

        while (left && right) {
        ListNode* lnext = left->next;
        ListNode* rnext = right->next;

        left->next = right;
        right->next = lnext;

        left = lnext;
        right = rnext;
}
    }
};
