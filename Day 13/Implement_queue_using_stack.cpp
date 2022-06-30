//0(1) amortised Time --For explanation refere to notes


#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int>s1,s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        int data=-1;
        if(!s2.empty()){
            data=s2.top();
            s2.pop();
            return data;
        }
        else if(s1.empty()==false)
        {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            data=s2.top();
            s2.pop();
        }
        return data;
    }

    int peek() {
        // Implement the peek() function here.
        int data=-1;
        if(s2.empty()==false){
            data=s2.top();
        }
        else if(s1.empty()==false){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            data=s2.top();
        }
        return data;
        
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty() && s2.empty();
    }
};



//0(N) 



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
