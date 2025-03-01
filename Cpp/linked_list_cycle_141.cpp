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
        if(head == nullptr) {
            return false;
        }
        ListNode* first = head;
        ListNode* second = head;
        while(first->next != nullptr && second->next != nullptr && second->next->next != nullptr) {
            first = first->next;
            second = second->next->next;
            if(first == second) {
                return true;
            }
        }
        return false;
    }
};

// Solution 2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
        while(second != nullptr && second->next != nullptr) {
            first = first->next;
            second = second->next->next;
            if(first == second) {
                return true;
            }
        }
        return false;
    }
};