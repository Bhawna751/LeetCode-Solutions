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
    #define pi pair<int,ListNode*>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int  k =lists.size();
        if(k==0)return NULL;
        priority_queue<pi,vector<pi>,greater<pi>> minh;
        for(int i=0;i<k;i++){
            ListNode*curr=lists[i];
            if(curr!=NULL){
                minh.push({curr->val,curr});
            }
        }
        if(minh.size()==0)return NULL;
        ListNode* head = new ListNode();
        ListNode* q=head;
        while(minh.empty()==false){
            pair<int,ListNode*> temp = minh.top();
            minh.pop();
            if(temp.second->next!=NULL){
                minh.push({temp.second->next->val,temp.second->next});
            }
            q->next=temp.second;
            q=q->next;
        }
        q->next=NULL;
        head = head->next;
        return head;
    }
};