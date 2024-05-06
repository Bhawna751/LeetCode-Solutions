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
    ListNode* removeNodes(ListNode* head) {
        vector<int> ind;
        ListNode *temp=head,*temp1=head;
        while(temp!=nullptr){
            ind.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int n= ind.size();
        stack<int> st;
        vector<int> nextGreater;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && ind[st.top()]<=ind[i]) st.pop();
            if(st.empty()) nextGreater.push_back(-1);
            else nextGreater.push_back(st.top());
            st.push(i);
        }

        reverse(nextGreater.begin(),nextGreater.end());
        set<int>s;
        for(int i=0;i<nextGreater.size();i++){
            if(nextGreater[i]!=-1) s.insert(i);
        }
        int i=0;
        ListNode *prev = nullptr;
        while(temp){
            if(s.find(i)!=s.end()){
                if(temp==temp1){
                    temp=temp->next;
                    temp1=temp1->next;
                }
                else{
                    prev->next = temp->next;
                    temp=temp->next;
                }
            }
            else{
                prev= temp;
                temp=temp->next;
            }
            i++;
        }
        return temp1;
    }
};