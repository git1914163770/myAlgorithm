// 707. 设计链表
class MyLinkedList {
public:

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){}
    };
    
    int size;
    ListNode* dummyHead;

    MyLinkedList() {
        size = 0;
        dummyHead = new ListNode(0);
    }
    
    int get(int index) {
        if(index < 0 || index > (size - 1)){
            return -1;
        }
        int count = 0;
        ListNode* p = dummyHead->next;
        while(index--){
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = dummyHead->next;
        dummyHead->next = p;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* p = dummyHead;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }
        ListNode* node = new ListNode(val);
        ListNode* p = dummyHead;
        while(index--){
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > (size - 1)){
            return;
        }
        ListNode* p = dummyHead;
        while(index--){
            p = p->next;
        }
        ListNode* t = p->next;
        p->next = p->next->next;
        delete t;
        size--;
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