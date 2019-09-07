/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        quick_sort(head,NULL);
        return head;
    }
    void quick_sort(ListNode* head,ListNode *tail) {
        if(head == tail || !head) return;
        ListNode* index = partition(head,tail);
        quick_sort(head,index);
        quick_sort(index->next,tail);
    }
    ListNode* partition(ListNode* head, ListNode* tail) {
        ListNode* p = head;
        ListNode* index = head;
        int val = head->val;
        while(p != NULL && p != tail) {
            if(p->val < val) {
                index = index -> next;
                swap(index,p);
            }
            p = p->next;
        }
        swap(index,head);
        return index;
    }
    void swap(ListNode* a,ListNode *b) {
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};

