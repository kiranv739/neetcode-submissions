class MedianFinder {
public:
    priority_queue<int> lheap;
    priority_queue<int,vector<int>,greater<int>> rheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lheap.push(num);
        
        if(!lheap.empty() && !rheap.empty() && lheap.top()>rheap.top()){
            int x = lheap.top();
            lheap.pop();
            rheap.push(x);
        }
        if(lheap.size()>rheap.size()+1){
            int x = lheap.top();
            lheap.pop();
            rheap.push(x);
        }
        else if(rheap.size()>lheap.size()+1){
            int x = rheap.top();
            rheap.pop();
            lheap.push(x);
        }
    }
    
    double findMedian() {
        if(lheap.size()>rheap.size()) return lheap.top();
        else if(lheap.size()<rheap.size()) return rheap.top();
        else if(lheap.size()==rheap.size()) 
        return (double)(lheap.top()+rheap.top())/2;
        
    return 0;
    }
};
