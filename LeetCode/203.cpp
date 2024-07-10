// 203. 移除链表元素
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* L = new ListNode();
        L->next = head;
        ListNode* p = L;
        while(p->next != NULL){
            if(p->next->val == val){
                ListNode* t = p->next;
                p->next = t->next;
                delete t;
            }else{
                p = p->next;
            }
        }
        head = L->next;
        delete L;
        return head;
    }
};