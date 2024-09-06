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
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode newHead(0);
        newHead.next = head;
        ListNode *cur = &newHead;
        while(cur->next != nullptr){
            if(st.count(cur->next->val)){
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else{
                cur = cur->next;
            }
        }
        return newHead.next;
    }
};