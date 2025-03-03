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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode fakehead;
        fakehead.next = head;

        queue<ListNode*> q;
        ListNode* cur = &fakehead;
        
        while(q.size() < n+1) {
            q.push(cur);
            cur = cur->next;
        }

        while(cur != nullptr) {
            q.push(cur);
            q.pop();
            cur = cur->next;
        }

        ListNode* pre = q.front();
        pre->next = pre->next->next;
        

        return fakehead.next;
    }

};