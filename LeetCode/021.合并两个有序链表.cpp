/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
 // Definition for singly-linked list.
 /* struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-0x3f3f3f3f);
        ListNode *cur = head;
        if(l1 == NULL && l2 == NULL) return NULL;
        else if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL && l2 != NULL)
            {
                cur->next = new ListNode(-1);
                cur = cur->next;
                if(l1->val > l2->val) cur->val = l2->val,l2 = l2->next;
                else cur->val = l1->val,l1 = l1->next;
            }
            else if(l1 != NULL)
            {
                cur->next = new ListNode(l1->val);
                cur = cur->next;
                l1 = l1->next;
            }
            else if(l2 != NULL)
            {
                cur->next = new ListNode(l2->val);
                cur = cur->next;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};

