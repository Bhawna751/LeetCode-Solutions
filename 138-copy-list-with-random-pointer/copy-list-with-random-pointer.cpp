/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* q=head;
        
        while(q!=nullptr){
            Node* temp=q->next;
            q->next =new Node(q->val);
            q->next->next = temp;
            q=temp;
        }
        q=head;
        while(q!=nullptr){
            if(q->random!=nullptr){
                q->next->random = q->random->next; 
            }
            q=q->next->next;
        }
        Node* ans = new Node(0);
        Node* p = ans;
        while(head){
            p->next = head->next;
            p=p->next;
            head->next= head->next->next;
            head=head->next;
        }
        return ans->next;
    }
};