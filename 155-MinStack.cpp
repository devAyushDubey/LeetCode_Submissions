class MinStack {
public:
    vector<int> vec;
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
    }
    
    void pop() {
        auto it = vec.end()-1;
        vec.erase(it);
    }
    
    int top() {
        auto it = vec.end()-1;
        return *it;
    }
    
    int getMin() {
        return *min_element(vec.begin(),vec.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */