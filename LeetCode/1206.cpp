// https://leetcode.cn/problems/design-skiplist/solutions/1699167/by-tonngw-ls2k/
class Skiplist {
public:

    static const int level = 8;

    struct Node {
        int val;
        Node* next[level] = {nullptr};

        Node(int _val) {
            this->val = _val;
        }
    }*head;

    Skiplist() {
        head = new Node(-1);
    }

    ~Skiplist(){
        delete head;
    }

    // 链表范围l < node <= r 找到小于目标值的最大节点l，就到下一层
    void find(int target ,vector<Node*>& pre){
        auto p = head;
        for(int i = level - 1;i >= 0;i--){
            while(p->next[i] && p->next[i]->val < target) p = p->next[i];
            pre[i] = p;
        }
    }
    
    // 由于第0层是最全的，所以只需要在第0层查找是否存在即可
    bool search(int target) {
        vector<Node*> pre(level);
        find(target,pre);
        
        auto p = pre[0]->next[0];
        return p && p -> val == target;
    }
    
    // 从第0层开始插入，往上每50%的概率插入
    void add(int num) {
        vector<Node*> pre(level);
        find(num,pre);
        auto p = new Node(num);
        for(int i = 0; i < level;i++){
            p->next[i] = pre[i]->next[i];
            pre[i]->next[i] = p;
            if(rand() % 2) break;
            // srand(time(NULL));
            // rand() % 100 <= 25
        }
    }
    
    bool erase(int num) {
        vector<Node*> pre(level);
        find(num,pre);
        auto p = pre[0]->next[0];
        if(!p || p->val != num) return false;

        for(int i = 0;i < level && pre[i] -> next[i] == p;i++){
            pre[i]->next[i] = p->next[i];
        }

        delete p;

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */