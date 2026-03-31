class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!largeHeap.empty() && largeHeap.top() < num) {
            largeHeap.push(num);
        }
        else {
            smallHeap.push(num);
        }

        if(smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size()) {
            return( smallHeap.top() + largeHeap.top()) / 2.0;
        }else if(smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};
