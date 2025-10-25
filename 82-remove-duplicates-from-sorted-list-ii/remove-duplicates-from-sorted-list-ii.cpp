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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>freq;
        ListNode* q=head;
        while(q!=nullptr){
            freq[q->val]++;
            q=q->next;
        }
        ListNode* newNode=new ListNode(0);
        ListNode* cur=newNode;
        for(auto it:freq){
            if(it.second>1) continue;
            else{
                ListNode* temp = new ListNode(it.first);
                cur->next = temp;
                cur=cur->next;
            }
        }
        return newNode->next;
    }
};