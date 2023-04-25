class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for(int i=1;i<1005;i++){
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int a=*s.begin();
        s.erase(s.begin());
        return a;
    }
    
    void addBack(int num) {
        if(s.count(num)==0){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */