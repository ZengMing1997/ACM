/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// * Definition for singly-linked list.
 /*struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *Ans = new ListNode(head->val);
        ListNode *cur = Ans;
        while(head != NULL)
        {
            if(cur->val != head->val)
            {
                cur->next = new ListNode(head->val);
                cur = cur->next;
            }
            head = head->next;
        }
        return Ans;
    }
};


