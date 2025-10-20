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
        map<Node*,Node*>mpp;

        while(q!=nullptr){
            Node *newhead=new Node(q->val);
            mpp[q]=newhead;
            q=q->next;
        }
        q=head;
        while(q!=nullptr){
            Node* copy = mpp[q];
            copy->next=mpp[q->next];
            copy->random=mpp[q->random];
            q=q->next;
        }
        return mpp[head];
    }
};