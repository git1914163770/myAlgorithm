// https://leetcode.cn/problems/lfu-cache/solutions/2457716/tu-jie-yi-zhang-tu-miao-dong-lfupythonja-f56h/
// LFU

class Node {
public:
    int key;
    int value;
    int freq = 1;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k),value(v) {}
};

// 使用双链表是为了去除 最久未使用 的键，且需要达到O(1)的复杂度，参考LRU。若不需要就可以不使用双链表

class LFUCache {
private:
    int min_freq;
    int capacity;
    unordered_map<int, Node*> key_to_node;
    unordered_map<int, Node*> freq_to_dummy;

    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if(it == key_to_node.end()) {
            return nullptr;
        }
        Node* node = it->second;
        remove(node);
        Node* dummy = freq_to_dummy[node->freq];
        if(dummy->prev == dummy) {
            freq_to_dummy.erase(node->freq);
            delete dummy;
            if ( min_freq == node->freq){
                min_freq++;
            }
        }
        ++node->freq;
        push_front(node->freq,node);
        return node;
    }

    void remove(Node* x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    Node* new_list() {
        Node* dummy = new Node();
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }

    void push_front(int freq,Node* x){
        auto it = freq_to_dummy.find(freq);
        if(it == freq_to_dummy.end()){
            it = freq_to_dummy.emplace(freq,new_list()).first;
        }
        Node* dummy = it->second;
        x->prev = dummy;
        x->next = dummy->next;
        dummy->next->prev = x;
        dummy->next = x;
    }
public:
    LFUCache(int capacity):capacity(capacity){}
    
    int get(int key) {
        Node* node = get_node(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        Node* node = get_node(key);
        if(node){
            node->value = value;
            return;
        }
        if(key_to_node.size() == capacity) {
            Node* dummy = freq_to_dummy[min_freq];
            Node* back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node);
            delete back_node;
            if(dummy->prev == dummy){
                freq_to_dummy.erase(min_freq);
                delete dummy;
            }
        }
        node = new Node(key,value);
        key_to_node[key] = node;
        push_front(1,node);
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */