class MinStack {
private:
    int topIndex;
    pair<int, int>* arr;
    int capacity;
public:
    MinStack():capacity(100000), topIndex(-1){
        arr = new pair<int, int>[capacity];
    }
    
    bool isEmpty(){
        return (topIndex < 0);
    }

    void push(int value) {
        if(isEmpty())
            arr[++topIndex] = {value, value};
        else{
            int currentMin = min(value, arr[topIndex].second);
            ++topIndex;
            arr[topIndex] = {value, currentMin};
        }
    }
    
    void pop() {
        if(!isEmpty())
            topIndex--;
    }
    
    int top() {
        return arr[topIndex].first;
    }
    
    int getMin() {
        return arr[topIndex].second;
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