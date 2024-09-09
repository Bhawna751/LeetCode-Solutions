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
    ListNode* sortList(ListNode* head) {
        ListNode *temp=head;
        vector<int> values;
        while(temp!=NULL){
            values.push_back(temp->val);
            temp=temp->next;
        }
        sort(values.begin(),values.end());
        temp=head;
        for(int i=0;i<values.size();i++){
            temp->val = values[i];
            temp=temp->next;
        }
        return head;
    }
};