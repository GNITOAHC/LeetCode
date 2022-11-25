class MyLinkedList {
private:
    typedef struct node {
        node () {}
        node(int a) : val(a) {
            pre = nullptr;
            next = nullptr;
        }
        int val;
        node * pre;
        node * next;
    }node;
    
    node * head;
    node * end;
    int length = 0;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if (index > length-1 || index < 0)
            return -1;
        node * cur = head;
        for (int i=0; i<index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        if (head == nullptr) {
            head = new node(val);
            end = head;
        } else {
            node * tmp = new node(val);
            tmp->next = head;
            head->pre = tmp;
            tmp->pre = nullptr;
            head = tmp;
        }
        ++length;
        return;
    }
    
    void addAtTail(int val) {
        if (length == 0) {
            head = new node(val);
            end = head;
            ++length;
            return;
        }
        node * tmp = end;
        end->next = new node(val);
        end = end->next;
        end->pre = tmp;
        ++length;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if (index == length) {
            addAtTail(val);
            return;
        }
        else if (index == 0) {
            addAtHead(val);
            return;
        }
        else if (index > length)
            return;
        else {
            node * cur = head;
            for (int i=0; i<index-1; ++i)
                cur = cur->next; // cur on the index-1
            node * tmp = new node(val);
            tmp->next = cur->next;
            tmp->pre = cur;
            cur->next->pre = tmp;
            cur->next = tmp;
        }
        ++length;
        // print();
        return;
    }
    
    void deleteAtIndex(int index) {
        // print();
        if (index > length-1 || index < 0 || length == 0)
            return;
        else if (length == 1) {
            delete head;
            --length;
            return;
        }
        else if (index == length-1) {
            end = end->pre;
            delete end->next;
            end->next = nullptr;
            --length;
            return;
        }
        else if (index == 0) {
            head = head->next;
            delete head->pre;
            head->pre = nullptr;
            --length;
            return;
        }
        else {
            // print();
            node * cur = head;
            for (int i=0; i<index; ++i)
                cur = cur->next; // cur on index
            node * tmp = cur;
            cur->next->pre = cur->pre;
            cur->pre->next = cur->next;
            delete tmp;
        }
        --length;
        return;
    }
    
    void print() {
        node * cur = head;
        cout << "length = " << length << endl;
        for (int i=0; i<length; ++i) {
            cout << i << " : " << cur->val << endl;
            cur = cur->next;
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