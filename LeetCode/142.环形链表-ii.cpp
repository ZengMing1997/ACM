/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *p = interance(head);
        if(p == NULL) return NULL;
        ListNode *ptr1 = head;
        ListNode *ptr2 = p;
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
    ListNode* interance(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *hig = head;
        ListNode *low = head;
        while(hig != NULL && hig->next != NULL) {
            low = low->next;
            hig = hig->next->next;
            if(hig == low) return hig;
        }            
        return NULL;
    }
};

