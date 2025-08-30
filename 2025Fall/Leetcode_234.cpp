// Leetcode 234: Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 */
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// 1. Reverse the second half + compare

class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(head->next == nullptr) return true;
            ListNode* slow = head;
            ListNode* fast = head->next;
            while(fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            slow = slow->next;
            slow = reverse(slow);
            fast = head;
            
            while(slow != nullptr) {
                if(slow->val != fast->val) return false;
                slow = slow->next;
                fast = fast->next;
            }
    
            return true;
        }
        
        ListNode* reverse(ListNode* p) {
            ListNode* prev = nullptr;
            ListNode* next;
            while(p != nullptr) {
                next = p->next;
                p->next = prev;
                prev = p;
                p = next;
            }
            return prev;
        }
    };