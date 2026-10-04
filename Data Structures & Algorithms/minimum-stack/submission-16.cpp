class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        myStack.push(val);
        if(minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            if(minStack.top() >= val)
            {
                minStack.push(val);
            }
        }
        
    }
    
    void pop() {
        int val = myStack.top();
        myStack.pop();
        if(minStack.top() == val)
        {
            minStack.pop();
        }
        return;
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
