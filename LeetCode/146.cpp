class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k = 0,int v = 0):key(k),value(v){}
};

class LRUCache {
private:
    int capacity;
    Node* dummyNode;
    unordered_map<int,Node*> map;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void push_front(Node* node){
        node->next = dummyNode->next;
        node->prev = dummyNode;
        dummyNode->next->prev = node;
        dummyNode->next = node;
    }
public:
    LRUCache(int capacity) :capacity(capacity) {
        dummyNode = new Node();
        dummyNode->next = dummyNode;
        dummyNode->prev = dummyNode;
    }

    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        Node* node = map[key];
        remove(node);
        push_front(node);
        return node->value;
    }

    void put(int key, int value) {
        if(map.find(key) != map.end()){
            Node* node = map[key];
            node->value = value;
            remove(node);
            push_front(node);
        }else{
            Node* node = new Node(key,value);
            if(map.size() == capacity){
                Node* tail = dummyNode->prev;
                map.erase(tail->key);
                remove(tail);
                delete tail;
            }
            map[key] = node;
            push_front(node);
        }
    }
};