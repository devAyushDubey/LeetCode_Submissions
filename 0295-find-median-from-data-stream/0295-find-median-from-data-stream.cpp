//Not practised!

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>>right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        left.push(num);
        if(!left.empty() && !right.empty() && left.top() > right.top())
        {
            int val = left.top();
            left.pop();
            right.push(val);
        }
        if(left.size() > right.size() + 1)
        {
            int val = left.top();
            
            left.pop();
            
            right.push(val);
        }
        
        
        
        else if(right.size() > left.size() + 1)
        {
            int val = right.top();
            
            right.pop();
            
            left.push(val);
        }
    }
    
    double findMedian() {
        
        if(left.size() == right.size())
        {
            return (double(left.top()) + double(right.top())) / 2;
        }
        
        else if(left.size() == right.size() + 1)
        {
            return double(left.top());
        }
        
        else
        {
            return double(right.top());
        }
    }
};
