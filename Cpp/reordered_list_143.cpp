/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* cur = head;
        ListNode* tmp;
        while(cur != nullptr) {
            nodes.push(cur);
            cur = cur->next;
        }

        cur = head;
        while(!nodes.empty() && cur != nodes.top() && cur->next != nodes.top()) {
            tmp = cur->next;
            cur->next = nodes.top();
            nodes.pop();
            cur->next->next = tmp;
            cur = tmp;
        }

        if(cur == nodes.top()) {
            cur->next = nullptr;
        } else {
            cur->next->next = nullptr;
        }
    }
};