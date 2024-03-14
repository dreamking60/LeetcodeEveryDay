class MyLinkedList {
    private int size = 0;
    private Node head;
    private Node tail;

    public MyLinkedList() {
        
    }
    
    public int get(int index) {
        if(index < 0 || index >= size) {
            return -1;
        } else {
            Node cur = head;
            while(index-- > 0) {
                cur = cur.next;
            }
            return cur.val;
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    
    public void addAtHead(int val) {
        Node prev = new Node(val);
        prev.next = head;
        head = prev;
        if(size == 0) {
            tail = head;
        }
        size++;
    }
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    
    public void addAtTail(int val) {
        if(size == 0) {
            addAtHead(val);
            return;
        }
        Node post = new Node(val);
        tail.next = post;
        tail = post;
        size++;
    }
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    
    public void addAtIndex(int index, int val) {
        if(index < 0 || index > size) {
            return;
        } else if(index == 0) {
            addAtHead(val);
        } else if(index == size) {
            addAtTail(val);
        } else {
            Node prev = head;
            while(index-- > 1) {
                prev = prev.next;
            }
            Node post = prev.next;
            Node cur = new Node(val);
            prev.next = cur;
            cur.next = post;
        }
        size++;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    
    public void deleteAtIndex(int index) {
        if(index < 0 || index >= size) {
            return;
        } else if(index == 0) {
            head = head.next;
        } else if(index == size - 1) {
            Node prev = head;
            while(index-- > 1) {
                prev = prev.next;
            }
            prev.next = null;
            tail = prev;
        } else {
            Node prev = head;
            while(index-- > 1) {
                prev = prev.next;
            }
            prev.next = prev.next.next;
        }
        size--;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    private class Node {
        int val;
        Node next;
        Node(int val) {
            this.val = val;
        }
    }
}