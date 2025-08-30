// Leetcode 160: Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1. Hash Set
#include <set>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode* next = headA;

        while(next != nullptr) {
            if(s.count(next) == 0) {
                s.insert(next);
            }
            next = next->next;
        }

        next = headB;
        while(next != nullptr) {
            if(s.count(next) == 0) {
                s.insert(next);
            } else {
                return next;
            }
            next = next->next;

        }
        
        return nullptr;

    }
};