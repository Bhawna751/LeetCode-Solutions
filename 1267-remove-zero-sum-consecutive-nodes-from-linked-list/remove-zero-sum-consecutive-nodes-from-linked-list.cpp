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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *temp=new ListNode(0);
        temp->next=head;
        unordered_map<int,ListNode*>mpp;
        mpp[0]=temp;
        int sum=0;
        while(head!=nullptr){
            sum+=head->val;
            if(mpp.find(sum)!=mpp.end()){
                ListNode *prev = mpp[sum];
                ListNode *start = prev;
                int dup=sum;
                while(prev!=head){
                    prev=prev->next;
                    dup+=prev->val;
                    if(prev!=head)mpp.erase(dup);
                }
                start->next=head->next;
            }
            else{
                mpp[sum]=head;
            }
            head=head->next;
        }
        return temp->next;
    }
};