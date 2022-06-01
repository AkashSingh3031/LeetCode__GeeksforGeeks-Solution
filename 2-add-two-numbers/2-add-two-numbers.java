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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) 
            return null;
		else if (l1 == null) 
            return l2; 
		else if (l2 == null) 
            return l1; 

		int a = l1.val + l2.val;
		ListNode p = new ListNode(a % 10);
		p.next = addTwoNumbers(l1.next,l2.next);
        
		if (a >= 10) 
            p.next = addTwoNumbers(p.next, new ListNode(1));
        return p;
    }
}