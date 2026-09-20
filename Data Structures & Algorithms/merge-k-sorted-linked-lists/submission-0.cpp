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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode *>,
        vector<pair<int,ListNode *>>,
        greater<pair<int,ListNode *>>
        > pq;

        ListNode* ans = new ListNode();
        ListNode* dummy = ans;

        for(auto x : lists){
            if(x!=nullptr) 
            pq.push({x->val,x});
        }

        while(!pq.empty()){
            auto [num,node] = pq.top();
            pq.pop();

            if(node->next!=nullptr) pq.push({node->next->val,node->next});
            dummy->next = node;
            dummy = dummy->next;
        }
    return ans->next;
    }
};
