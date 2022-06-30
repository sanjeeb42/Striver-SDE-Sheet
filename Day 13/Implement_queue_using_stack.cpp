#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int>q1,q2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        q1.push(val);
        
       // cout<<q1.size()<<endl;
    }

    int deQueue() {
        // Implement the dequeue() function.
        int data=-1;
        while(!q1.empty()){
            q2.push(q1.top());
            q1.pop();
        }
        if(q2.empty()==false){
            data=q2.top();
            q2.pop();
        }
        
        while(!q2.empty()){
            q1.push(q2.top());
            q2.pop();
        }
        return data;
    }

    int peek() {
        // Implement the peek() function here.
        int data=-1;
        while(!q1.empty()){
            q2.push(q1.top());
            q1.pop();
        }
        if(q2.empty()==false){
            data=q2.top();
            
        }
        
        while(!q2.empty()){
            q1.push(q2.top());
            q2.pop();
        }
        return data;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return q1.size()==0;
    }
};
