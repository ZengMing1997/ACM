/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (35.88%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 29.2K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 
 * 要求返回这个链表的深拷贝。 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * 解释：
 * 节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
 * 节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你必须返回给定头的拷贝作为对克隆列表的引用。
 * 
 * 
 */

// Definition for a Node.
/*class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        copyAllList(head);
        connectSiblingNodes(head);
        return Reconnect(head);
    }
    void copyAllList(Node* head) {
        Node * now = head;
        while(now != nullptr) {
            Node *tmp = new Node();
            tmp->random = nullptr;
            tmp->val = now->val;
            tmp->next = now->next;
            now->next = tmp;
            now = tmp->next;
        }
    }
    void connectSiblingNodes(Node* head) {
        Node *now = head;
        while(now != nullptr) {
            Node *tmp = now->next;
            if(now->random != nullptr) {
                tmp->random = now->random->next;
            }
            now = tmp->next;
        }
    }
    Node* Reconnect(Node *head) {
        Node *now = head;
        Node *new_head = nullptr;
        Node *node = nullptr;
        if(head != nullptr) {
            new_head = node = now->next;
            now->next = node->next;
            now = now->next;
        }
        while(now != nullptr) {
            node->next = now->next;
            node = node->next;
            now->next = node->next;
            now = now->next;
        }
        return new_head;
    }
};

