class MinStack {
public:
    vector<int>stack1;
    vector<int>minival;
    MinStack() {
        
    }
    
    void push(int value) {
        stack1.push_back(value);
        if(minival.empty()){
            minival.push_back(value);
        }
        else{
            minival.push_back(min(value,minival.back()));
        }
    }
    
    void pop() {
        stack1.pop_back();
        minival.pop_back();
    }
    
    int top() {
        return stack1[stack1.size()-1];
    }
    
    int getMin() {
        return minival.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */