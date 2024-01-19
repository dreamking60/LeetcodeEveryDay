/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        int i = 0;
        ListNode first = head;
        ListNode second = head;
        while(first.next != null) {
            if(i++%2 == 0) {
                first = first.next;
                second = second.next;
            } else {
                first = first.next;
            }
        }
        return second;
    }
}

// Space Complexity: O(1)
// Time Complexity: O(n)
// 100%


// Solution 2
public boolean canConstruct(String ransomNote, String magazine) {
    if(ransomNote.length() > magazine.length()) {
        return false;
    }
    
    int[] letter = new int[26];
    for(char c : magazine.toCharArray()) {
        letter[c-'a']++;
    }
    for(char c : ransomNote.toCharArray()) {
        if(letter[c-'a'] == 0) {
            return false;
        } else {
            letter[c-'a']--;
        }
    }
    return true;
}