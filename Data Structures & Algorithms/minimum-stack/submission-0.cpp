class MinStack {
public:

    stack<int> mainStack;
    stack<int> getMinVal;

    MinStack() {
        
    }
    
    void push(int val) 
    {
        mainStack.push(val);
        if(getMinVal.empty())
        {
            getMinVal.push(val);
        }
        else if(getMinVal.top() >= val)
        {
            getMinVal.push(val);
        }
    }
    
    void pop() 
    {
        if(mainStack.top() == getMinVal.top())
        {
            mainStack.pop();
            getMinVal.pop();
        }
        else
        {
            mainStack.pop();
        }
    }
    
    int top() 
    {
        return mainStack.top();
    }
    
    int getMin() 
    {
        return getMinVal.top();
    }
};
