/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

//  Definition for singly-linked list.
#include <bits/stdc++.h>
using namespace std;
  /*struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* p = head;
        while(p != NULL) {
            ListNode* tmpnex = p->next;
            p->next = pre;
            pre = p;
            p = tmpnex;
        }
        return pre;
    }
};

