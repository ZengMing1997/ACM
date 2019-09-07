/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *hig = head->next;
        ListNode *low = head;
        while(1) {
            if(!hig || !hig->next) return false;
            if(hig == low) return true;
            low = low->next;
            hig = hig->next->next;
        }
        return false;
    }
};

