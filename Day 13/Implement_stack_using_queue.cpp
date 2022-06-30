#include<bits/stdc++.h>

class Stack {
	// Define the data members.
    queue<int>q1,q2;
   public:
    Stack() {
        // Implement the Constructor.
        
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.size()==0;
    }

    void push(int data) {
        // Implement the push() function.
        q2.push(data);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
 
    int pop() {
        // Implement the pop() function.
    int data = -1;
    if (!q1.empty())
    {
        data = q1.front();
        q1.pop();
    }
    return data;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty()) return -1;
        return q1.front();
    }
};

//Using single queue

#include<bits/stdc++.h>
class Stack {
	// Define the data members.
    queue<int>q1;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.size()==0;
    }

    void push(int element) {
        // Implement the push() function.
        
        // Push karte time top pe push kardo 
        // and jp bhi size hua ..usse ek kam element ko pop karo from front
        // Push krdo size-1 element ko top me
        
        q1.push(element);
        int size=q1.size();
        for(int i=0;i<size-1;i++){
           int data=q1.front();
            q1.pop();
            q1.push(data);
        }
    }

    int pop() {
        // Implement the pop() function.
        int data=-1;
        if(!isEmpty()){
            data=q1.front();
            q1.pop();
        }
        
        return data;
    }

    int top() {
        // Implement the top() function.
        int data=-1;
        if(!isEmpty()){
            data=q1.front();
        }
        
        return data;
    }
};
