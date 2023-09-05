class MedianFinder {
public:
    multiset<int> ms;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
    }
    
    double findMedian() {
        int size=ms.size();
        auto it1=ms.begin();
        auto it2=ms.begin();
        int mid=size/2;
        while(mid--){
            it1++;
        }
        it2=it1;
        it1--;
        if(size%2){
            return (double)(*it2);
        }
        return (double)((*it1+*it2))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */