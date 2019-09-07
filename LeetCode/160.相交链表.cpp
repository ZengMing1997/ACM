/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nowA = headA;
        ListNode *nowB = headB;
        int countA = 0 , countB = 0;
        while(nowA != NULL) {
            countA ++;
            nowA = nowA->next;
        }
        while(nowB != NULL) {
            countB ++;
            nowB = nowB->next;
        }
        int p = countA - countB;
        nowA = headA;
        nowB = headB;
        if(p < 0) {
            p = -p;
            while(p--) {
                nowB = nowB->next;
            }
        }
        else if(p > 0) {
            while(p--) {
                nowA = nowA->next;
            }
        }
        while(nowA != NULL && nowB != NULL) {
            //puts("----");
            if(nowA == nowB) {
                return nowA;
            }
            nowA = nowA->next;
            nowB = nowB->next;
        }
        return NULL;
    }
};
            //cout<<nowB->val<<" ";

