// 232. Implement Queue using Stacks

// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
// Implement the MyQueue class:
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.

class MyQueue {
public:
    int size;
    stack<int> forward;
    stack<int> reverse;
    MyQueue() {
        size=0;
    }
    
    void push(int x) {
        forward.push(x);
        size++;
    }
    
    int pop() {
        while(!forward.empty()){
            int front=forward.top();
            forward.pop();
            reverse.push(front);
        }
        int ans=reverse.top();
        reverse.pop();
        while(!reverse.empty()){
            int front=reverse.top();
            reverse.pop();
            forward.push(front);
        }
        size--;
        return ans;
    }
    
    int peek() {
        while(!forward.empty()){
            int front=forward.top();
            forward.pop();
            reverse.push(front);
        }
        int ans = reverse.top();
        while(!reverse.empty()){
            int front=reverse.top();
            reverse.pop();
            forward.push(front);
        }
        return ans;
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// Amortized
// class MyQueue {
//     stack<int> input, output;
// public:

    
//     void push(int x) {
//         input.push(x);
//     }

//     int pop() {
//         peek();
//         int ans=output.top();
//         output.pop();
//         return ans;
//     }

//     int peek() {
//         if (output.empty())
//             while (input.size())
//                 output.push(input.top()), input.pop();
//         return output.top();
//     }

//     bool empty() {
//         return input.empty() && output.empty();
//     }
// };

