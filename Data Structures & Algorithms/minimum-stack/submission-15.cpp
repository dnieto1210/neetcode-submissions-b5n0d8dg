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
            if(val <= minStack.top())
            {
                minStack.push(val);
            }
        }

        return;
    }
    
    void pop() {

        int num = myStack.top();
        myStack.pop();
        if(num == minStack.top())
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
