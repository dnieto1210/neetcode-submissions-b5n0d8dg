class MinStack {
public:
    MinStack() {
        min_val = 0;
        
    }
    
    void push(int val) {
        myStack.push(val);
        if(minStack.empty())
        {
            min_val = val;
            minStack.push(val);
        }
        else
        {
            if(val <= min_val)
            {
                minStack.push(val);
                min_val = val;
            }
        }
        
    }
    
    void pop() {
        if(!myStack.empty())
        {
            int check = myStack.top();
            myStack.pop();
            if(check == minStack.top())
            {
                minStack.pop();
            }

        }
        
    }
    
    int top() {
        if(!myStack.empty())
        {
            return myStack.top();
        }

        return INT_MIN;
        
    }
    
    int getMin() {
        return (minStack.empty()) ? INT_MIN : minStack.top();
        
    }
private:
    stack<int> myStack;
    stack<int> minStack;
    int min_val;
};
