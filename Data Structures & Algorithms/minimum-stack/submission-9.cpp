class MinStack {
public:
    MinStack() {
        min = INT_MAX;
        
    }
    
    void push(int val) {
        normal.push(val);
        min = std::min(val, min);
        minStack.push(min);
    }
    
    void pop() {
        if(normal.empty())
        {
            return;
        }
        //otherwise
        normal.pop();
        minStack.pop();
        if(minStack.empty())
        {
            min = INT_MAX;
        }
        else
        {
            min = minStack.top();
        }
        
    }
    
    int top() {
        return normal.top();
        
    }
    
    int getMin() {
        return minStack.top();
        
    }
private:
    int min;
    stack<int> normal;
    stack<int> minStack;
};
