#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* public class ListNode {
*     int val;
*     ListNode next;
*     ListNode(int x) { val = x; }
* }
*/
class Solution {

	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

		if (l1 == null)
			return l2;
		if (l2 == null)
			return l1;
		if (l1.val <= l2.val) {
			ListNode l3 = new ListNode(l1.val);
			l3.next = mergeTwoLists(l1.next, l2);
		}
		else {
			ListNode l3 = new ListNode(l2.val);
			l3.next = mergeTwoLists(l1, l2.next);
		}
		return l3;
	}
}
