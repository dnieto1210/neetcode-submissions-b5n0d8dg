class MinStack {
public:
    MinStack() {
        ///na
        
    }
    
    void push(int val) {
        myStack.push(val);
        if(minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            if(val <= minStack.top())
            {
                minStack.push(val);
            }
        }
        
    }
    
    void pop() {
        int val = myStack.top();
        myStack.pop();
        if(val == minStack.top())
        {
            minStack.pop();
        }
        
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
        
    }
private:
    stack<int> myStack;
    stack<int> minStack;
};
