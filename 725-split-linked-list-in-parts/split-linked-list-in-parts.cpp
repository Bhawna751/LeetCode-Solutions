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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        vector<ListNode*> ans(k);
        ListNode *cur = head;
        while(cur!=nullptr){
            n++;
            cur=cur->next;
        }
        int split = n/k;
        int rem = n%k;
        cur=head;
        for(int i=0;i<k;i++){
            ListNode newSection(0);
            ListNode *tail = &newSection;
            int curSize = split;
            if(rem > 0){
                rem--; curSize++;
            }
            for(int j = 0; j<curSize;j++){
                tail->next = new ListNode (cur->val);
                tail = tail->next;
                cur=cur->next;
            }
            ans[i] = newSection.next;
        }
        return ans;
    }
};