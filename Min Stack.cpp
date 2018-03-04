class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mini;
    int minElement;
    MinStack() {

    }

    void push(int x) {
        if(s.empty())
        {
            minElement = x;
            s.push(x);
            mini.push(x);
        }
        else if(x <= minElement)
        {
            minElement = x;
            s.push(x);
            mini.push(x);
        }
        else
        {
            s.push(x);
        }

    }

    void pop() {

        if(!s.empty())
        {
            int del = s.top();
            s.pop();
            if(del == mini.top())
            {
                mini.pop();
                if(!mini.empty())
                {
                    minElement = mini.top();
                }
                else
                {
                    minElement = -1;
                }
            }
        }
    }

    int top() {
        int up = s.top();
        return up;
    }

    int getMin() {
        if(!mini.empty())
        {
            return mini.top();
        }
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
