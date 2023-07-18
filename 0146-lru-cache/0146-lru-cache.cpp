class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int key,int val){
                this->key=key;
                this->val=val;
            }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cnt=0;
    unordered_map<int,node*> m;
    LRUCache(int capacity) {
        cnt=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
        return;
    }
    
    void deleteNode(node* currnode){
        node* temp=currnode->prev;
        node* tempo=currnode->next;
        temp->next=tempo;
        tempo->prev=temp;
        return;
    }
    
    int get(int k) {
        if(m.find(k)!=m.end()){
            node* temp=m[k];
            int value=temp->val;
            m.erase(k);
            deleteNode(temp);
            addNode(temp);
            m[k]=head->next;
            return value;
        }
        return -1;
    }
    
    void put(int k, int value) {
        if(m.find(k)!=m.end()){
            node* temp=m[k];
            m.erase(k);
            deleteNode(temp);
        }
        if(m.size()==cnt){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(k,value));
        m[k]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */