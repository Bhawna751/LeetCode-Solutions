/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse(ListNode head){
        ListNode prev=null, q=head;
        while(q!=null){
            ListNode nextNode = q.next;
            q.next=prev;
            prev=q;
            q=nextNode;
        }
        return prev;
    }
    public boolean isPalindrome(ListNode head) {
        if(head==null || head.next==null)return true;
        ListNode slow=head,fast=head;
        while(fast.next!=null && fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        ListNode newHead=reverse(slow.next);
        ListNode q=head,p=newHead;
        while(p!=null){
            if(q.val!=p.val){
                return false;
            }
            q=q.next;
            p=p.next;
        }
        return true;
    }
}