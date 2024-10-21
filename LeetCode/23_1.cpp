// 合并 K 个升序链表
class Solution {
public:
    // 渐进时间复杂度为 O(kn×logk)。 空间复杂度：递归会使用到 O(logk)
    ListNode* mergeTwoLists(ListNode *a,ListNode *b){
        if ((!a) || (!b)) return a ? a : b;

        ListNode dummyHead;
        ListNode*p = &dummyHead; 
        ListNode* aP = a,*bP = b;
        while(aP && bP){
            if(aP ->val < bP->val){
                p->next = aP;aP = aP->next;
            }else{
                p->next = bP;bP = bP->next;
            }
            p = p->next;
        }
        p->next = (aP != nullptr?aP:bP);
        return dummyHead.next;
    }

    // 左闭右闭区间
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists,l,mid),merge(lists,mid + 1,r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};