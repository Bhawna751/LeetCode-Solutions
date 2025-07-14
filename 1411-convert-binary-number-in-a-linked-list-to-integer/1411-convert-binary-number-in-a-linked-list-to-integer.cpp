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
    int getDecimalValue(ListNode* head) {
        string number;
        while(head != nullptr){
            number += to_string(head->val);
            head=head->next;
        }
        int ans =0, pow=1;
        for(int i=number.size()-1;i>=0;i--){
            ans += pow*(stoi(number.substr(i,1)));
            pow*=2;
        }
        return ans;
    }
};