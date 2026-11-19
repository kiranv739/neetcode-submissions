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
    ListNode* reverse(ListNode* temp){
        ListNode* dummy = nullptr;
        while(temp != nullptr){
            ListNode* n = temp->next;
            temp->next = dummy;
            dummy = temp;
            temp = n;
        }
        return dummy;
    }

    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = nullptr;

        temp = reverse(temp);

        ListNode* temp2 = head;
        while(temp2!=nullptr && temp!=nullptr){
            ListNode* n = temp2->next;
            ListNode* r = temp->next;
            
            temp2->next = temp;
            temp->next = n;
            
            temp2 = n;
            temp = r; 
        }
    }
};
