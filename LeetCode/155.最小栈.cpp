/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        vector<int>S(10000);
        int index = -1;
        int MIN = 0x3f3f3f3f;
    }
    
    void push(int x) {
        index = index + 1;
        S[index] = x;
        MIN = min(MIN,x);
    }
    
    void pop() {
        if(top() == MIN) {
            for(int i = 0 ; i < index ; i++) {
                MIN = min(MIN,S[i]);
            }
        }
        index--;
    }
    
    int top() {
        return S[index];
    }
    
    int getMin() {
        return MIN;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

