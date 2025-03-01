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
#include <stack>
using namespace std;
// First solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }

        if(head->next == nullptr) {
            return head;
        }
        
        stack<ListNode*> s;
        while(head->next != nullptr) {
            s.push(head);
            head = head->next;
        }

        ListNode* cur = head;
        ListNode* res = cur;
        while(!s.empty()) {
            cur->next = s.top();
            cur = cur->next;
            s.pop();
        }
        cur->next = nullptr;
        return res;
    }
};

// Second solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next;

        while(head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};

// Third solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return res;       
    }
};