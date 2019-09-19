/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* now = head;
        ListNode* pre1 = new ListNode(-1);
        ListNode* pre2 = new ListNode(-1);
        int count = 0;
        while(now->next != NULL) {
            now = now->next;
            count++;
        }
        count ++;
        now->next = head;
        k =count - k % count + 1;
        int cur = 0;
        now = head;
        for(int i = 1 ; i < k - 1; i++) {
            now = now->next;
        }
        cout<<now->val<<endl;
        ListNode* p_head = now->next;
        now ->next = NULL;
        return p_head;
        
    }
};

