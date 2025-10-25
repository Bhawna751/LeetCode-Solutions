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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode *q=head;
        vector<int> arr;
        while(q!=nullptr && q->next!=nullptr){
            arr.push_back(q->val);
            q=q->next->next;
        }
        if(q!=nullptr){
            arr.push_back(q->val);
        }
        q = head->next;
        while(q!=nullptr && q->next!=nullptr){
            arr.push_back(q->val);
            q=q->next->next;
        }
        if(q!=nullptr){
            arr.push_back(q->val);
        }
        q=head;
        int i=0;
        while(q!=nullptr){
            q->val = arr[i];
            q=q->next;
            i++;
        }
        return head;
    }
};