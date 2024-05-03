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
        vector<int> arr;
        ListNode *temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp)arr.push_back(temp->val);
        temp = head->next;
        while(temp!=nullptr && temp->next!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp)arr.push_back(temp->val);
        int i=0;
        temp=head;
        while(temp!=nullptr){
            temp->val = arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};