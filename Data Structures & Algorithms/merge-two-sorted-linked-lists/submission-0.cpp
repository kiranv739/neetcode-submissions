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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2==NULL) return list1;

        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        
        while(t1!=nullptr && t2!= nullptr){
            if(t1->val <= t2->val ){
                dummy->next = t1;
                t1=t1->next;
            }
            else{
                dummy->next=t2;
                t2=t2->next;
            }
            dummy = dummy->next;
        }
        while(t1!=nullptr){
            dummy->next = t1;
            t1=t1->next;
            dummy = dummy->next;
        }
        while(t2!=nullptr){
            dummy->next = t2;
            t2=t2->next;
            dummy = dummy->next;
        }

        return ans->next;
    }
};
