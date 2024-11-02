/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// https://leetcode.cn/problems/sort-list/solutions/13728/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* h = head;
        int length = 0;

        // 计算链表长度
        while (h) {
            h = h->next;
            length++;
        }

        ListNode* res = new ListNode(0); // 哨兵节点
        res->next = head;
        int intv = 1;

        // 合并链表
        while (intv < length) {
            ListNode* pre = res;
            ListNode* h = res->next;

            while (h) {
                ListNode* h1 = h; // 第一部分的头
                int i = intv;

                // 找到 h1 的结束位置
                while (i && h) {
                    h = h->next;
                    i--;
                }
                if (i) break; // 如果没有足够的元素，结束合并

                ListNode* h2 = h; // 第二部分的头
                i = 0;

                // 找到 h2 的结束位置
                while (i<intv && h) {
                    h = h->next;
                    i++;
                }

                int c1 = intv, c2 = min(intv,i); // c2 可能小于 intv
                // 合并 h1 和 h2
                while (c1 && c2) {
                    if (h1->val < h2->val) {
                        pre->next = h1;
                        h1 = h1->next;
                        c1--;
                    } else {
                        pre->next = h2;
                        h2 = h2->next;
                        c2--;
                    }
                    pre = pre->next;
                }
                pre->next = (c1 > 0) ? h1 : h2; // 连接剩余部分

                // 更新 pre 的位置
                while (c1 > 0 || c2 > 0) {
                    pre = pre->next;
                    c1--;
                    c2--;
                }
                pre->next = h; // 连接下一部分
            }
            intv *= 2; // 增加间隔
        }

        return res->next; // 返回排好序的链表
    }
};
