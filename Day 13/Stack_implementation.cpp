// Stack class.
class Stack {
    
public:
    int size=0;
    int *arr;
    int max_size;
       
    Stack(int capacity) 
    {
        // Write your code here.
       size=0;
       arr=new int(sizeof(int)*capacity);
       max_size=capacity;       
    }

    void push(int num) {
        // Write your code here.
        if(size>=max_size)return;
        else {
            arr[size++]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(size==0){
            return -1;
        }
        return arr[size--];
    }
    
    int top() {
        // Write your code here.
        if(size==0) return -1;
        return arr[size];
    }
    
    int isEmpty() {
        // Write your code here.
        if(size==0) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(size==max_size) return 1;
        return 0;
    }
    
};
