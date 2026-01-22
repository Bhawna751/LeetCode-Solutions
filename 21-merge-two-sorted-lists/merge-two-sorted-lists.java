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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode q=new ListNode(-1);
        ListNode p=q;
        while(list1!=null && list2!=null){
            if(list2.val >= list1.val){
                p.next = list1;
                list1 = list1.next;
            }
            else{
                p.next = list2;
                list2 = list2.next;
            }
            p=p.next;
        }
        if(list1 != null) p.next = list1;
        else p.next = list2;
        return q.next;
    }
}