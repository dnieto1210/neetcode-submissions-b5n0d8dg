
class MinStack {
public:
    MinStack() :min(INT_MAX){
        
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

        minStack.pop();
        normal.pop();
        min = (minStack.empty()) ? INT_MAX : minStack.top();
    }
    
    int top() {
        return normal.top();
        
    }
    
    int getMin() {
        return minStack.top();
        
    }
    private:
        std::stack<int> normal;
        std::stack<int> minStack;
        int min;
};
