class CustomStack {
public:
    vector<int> st;
    int top =-1;
    CustomStack(int maxSize) {
        st.resize(maxSize);
    }
    
    void push(int x) {
        if(top < (int)(st.size()-1)) st[++top] = x;
    }
    
    int pop() {
        if(top>=0) return st[top--];
        return -1;
    }
    
    void increment(int k, int val) {
        int limit = min(k, top+1);
        for(int i=0;i<limit;i++){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */