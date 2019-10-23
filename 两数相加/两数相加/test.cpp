#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		int tmpResult;
		int var1 = 0, var2 = 0;
		ListNode *resultEnd, *resultHead, *resultEndPre;
		resultHead = new ListNode(0);
		resultEnd = l1;
		resultHead->next = resultEnd;
		// �ظ�����l1,��l2���ڴ��ʡ�ڴ�������ķ�ʱ��
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 != NULL && l2 != NULL)
			{
				var1 = l1->val;
				var2 = l2->val;
				resultEnd = l1;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 == NULL)
			{
				var1 = 0;
				var2 = l2->val;
				resultEnd->next = l2;
				resultEnd = l2;
				l2 = l2->next;
			}
			else
			{
				var2 = 0;
				var1 = l1->val;
				resultEnd->next = l1;
				resultEnd = l1;
				l1 = l1->next;
			}
			tmpResult = var1 + var2 + carry;
			carry = tmpResult / 10;
			resultEnd->val = tmpResult % 10;
		}
		if (carry > 0)
		{
			resultEnd->next = new ListNode(carry);
			resultEnd = resultEnd->next;
		}
		resultEnd->next = NULL;
		return resultHead->next;
	}
};

