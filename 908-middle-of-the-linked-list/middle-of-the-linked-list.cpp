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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode *temp=head;int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        int mid = cnt/2 +1;
        temp=head;
        while(temp!=nullptr){
            mid--;
            if(mid==0)break;
            temp=temp->next;
        }
        return temp;
    }
};