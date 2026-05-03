class MinStack {
public:
    MinStack() {
        //no constructor needed 
        
    }
    
    void push(int val) {
        if(minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            int check = minStack.top();
            if(val <= check)
            {
                minStack.push(val);
            }
        }
        myStack.push(val);
    }
    
    void pop() {
        if(!myStack.empty())
        {
            int check = myStack.top();
            if(check == minStack.top())
            {
                minStack.pop();
            }
            myStack.pop();
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
        if(!minStack.empty())
        {
            return minStack.top();
        }
        return INT_MIN;
    }
private:
    stack<int> myStack;
    stack<int> minStack;
};
