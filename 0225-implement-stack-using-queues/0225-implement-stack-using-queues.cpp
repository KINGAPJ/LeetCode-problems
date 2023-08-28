class MyStack {
    queue<int> q1, q2;
    int topEle = -1;
public:
    MyStack() {}
    void push(int x) {
        q1.push(x);
        topEle = x;
    }
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            topEle = q1.front();
            q1.pop();
        }
        int ret = q1.front();
        q1.pop();
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        return ret;
    }
    int top() {
        return topEle;
    }
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */