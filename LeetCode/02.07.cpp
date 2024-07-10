// 面试题 02.07. 链表相交
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        // 当不相交时返回NULL
        while(p1 != p2){
            if(p1 != NULL){
                p1 = p1->next;
            }else{
                p1 = headB;
            }
            if(p2 != NULL){
                p2 = p2->next;
            }else{
                p2 = headA;
            }
        }
        return p1;
    }
};