class MinStack {
public:
    MinStack() {
        //n/a
        
    }
    
    void push(int val) {
        myStack.push(val);
        if(minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            int currMin = minStack.top();
            if(val <= currMin)
            {
                minStack.push(val);
            }
        }
        
    }
    
    void pop() {
        if(myStack.empty())
        {
            return;
        }
        else
        {
            int curr = myStack.top();
            myStack.pop();
            if(curr == minStack.top())
            {
                minStack.pop();
            }
        }
        
    }
    
    int top() {
        return (myStack.empty()) ? -1 : myStack.top();
        
    }
    
    int getMin() {
        return (minStack.empty()) ? -1 : minStack.top();
        
    }
private:
    stack<int> myStack;
    stack<int> minStack;
};
