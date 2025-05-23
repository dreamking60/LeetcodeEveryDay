class MyLinkedList {
    public:
        int val;
        MyLinkedList* next;
    
        MyLinkedList() {
            next = nullptr;
        }
        
        int get(int index) {
            MyLinkedList* cur = next;
            while(index-- != 0) {
                if(cur != nullptr) {
                    cur = cur->next;
                } else {
                    return -1;
                }
            }
    
            if(cur != nullptr) {
                return cur->val;
            } else {
                return -1;
            }
        }
        
        void addAtHead(int val) {
            MyLinkedList* newHead = new MyLinkedList();
            newHead->val = val;
            newHead->next = next;
            next = newHead;
        }
        
        void addAtTail(int val) {
            MyLinkedList* cur = next;
    
            if(cur == nullptr) {
                addAtHead(val);
            } else {
                while(cur->next != nullptr) {
                    cur = cur->next;
                }
                cur->addAtHead(val);
            }
        }
        
        void addAtIndex(int index, int val) {
            MyLinkedList* cur = this;
            while(index-- != 0) {
                if(cur != nullptr) {
                    cur = cur->next;
                } else {
                    return;
                }
            }
    
            if(cur != nullptr) {
                cur->addAtHead(val);
            }
    
        }
        
        void deleteAtIndex(int index) {
            MyLinkedList* cur = this;
            while(index-- != 0) {
                if(cur != nullptr) {
                    cur = cur->next;
                } else {
                    return;
                }
            }
    
    
    
            if(cur != nullptr && cur->next != nullptr) {
                cur->next = cur->next->next;
            }
        }
    };
    
    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */class MyLinkedList {
public:
int val;
MyLinkedList* next;

MyLinkedList() {
    next = nullptr;
}

int get(int index) {
    MyLinkedList* cur = next;
    while(index-- != 0) {
        if(cur != nullptr) {
            cur = cur->next;
        } else {
            return -1;
        }
    }

    if(cur != nullptr) {
        return cur->val;
    } else {
        return -1;
    }
}

void addAtHead(int val) {
    MyLinkedList* newHead = new MyLinkedList();
    newHead->val = val;
    newHead->next = next;
    next = newHead;
}

void addAtTail(int val) {
    MyLinkedList* cur = next;

    if(cur == nullptr) {
        addAtHead(val);
    } else {
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->addAtHead(val);
    }
}

void addAtIndex(int index, int val) {
    MyLinkedList* cur = this;
    while(index-- != 0) {
        if(cur != nullptr) {
            cur = cur->next;
        } else {
            return;
        }
    }

    if(cur != nullptr) {
        cur->addAtHead(val);
    }

}

void deleteAtIndex(int index) {
    MyLinkedList* cur = this;
    while(index-- != 0) {
        if(cur != nullptr) {
            cur = cur->next;
        } else {
            return;
        }
    }



    if(cur != nullptr && cur->next != nullptr) {
        cur->next = cur->next->next;
    }
}
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/