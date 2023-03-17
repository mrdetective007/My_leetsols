class Node{
public:
    vector<Node*> vec;
    bool terminate;
    Node(){
        for(int i=0;i<26;i++){
            vec.push_back(nullptr);
        }
        terminate=false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* p=root;
        for(auto x:word){
            if(!p->vec[x-'a']){
                p->vec[x-'a']=new Node();
            }
            p=p->vec[x-'a'];
        }
        p->terminate=true;
    }
    
    bool search(string word) {
        Node* p=root;
        for(auto x:word){
            if(!p->vec[x-'a']){
                return false;
            }
            p=p->vec[x-'a'];
        }
        return p&&p->terminate;
    }
    
    bool startsWith(string prefix) {
        Node* p=root;
        for(auto x:prefix){
            if(!p->vec[x-'a']){
                return false;
            }
            p=p->vec[x-'a'];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */