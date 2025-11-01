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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> hasN=0;
        for(int x: nums) hasN[x]=1;
        ListNode dummy(0, head);
        ListNode* prev=&dummy;
        for(ListNode* curr=head; curr; curr=curr->next){
            if (hasN[curr->val]) 
                prev->next=curr->next;
            else 
                prev=prev->next;
        }
        return dummy.next;
    }
};