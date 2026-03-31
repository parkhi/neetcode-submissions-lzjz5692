class MinStack {
private:
    stack<int> data, mindata;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        if(!mindata.empty())
            mindata.push(min(mindata.top(), val));
        else
            mindata.push(val);
    }
    
    void pop() {
        data.pop();
        mindata.pop();        
    }
    
    int top() {
        return data.top();
        
    }
    
    int getMin() {
        return mindata.top();
    }
};
