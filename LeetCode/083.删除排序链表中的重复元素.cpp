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
        if(head == NULL) return NULL;
        ListNode *ans = new ListNode(head->val);
        ListNode *cur = ans;
        while(head != NULL)
        {
            if(cur->val == head->val) head = head->next;
            else 
            {
                cur->next = new ListNode(head->val);
                head = head->next;
                cur = cur->next;
            }
        }
        return ans;
        
    }
};

