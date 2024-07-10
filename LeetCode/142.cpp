// 142. 环形链表 II
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* p = head;
                while(p != fast){
                    fast = fast->next;
                    p = p->next;
                }
                return p;
            }
        }
        return NULL;
    }
};