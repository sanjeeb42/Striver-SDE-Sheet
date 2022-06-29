class Queue {
public:
    int first;
     int rear;
     int *arr;
   
    Queue() {
        // Implement the Constructor
     first=0;
     rear=0;
     arr=new int[50001];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(first==rear) return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        // Enqueue from Rear
        arr[rear++]=data;
    }

    int dequeue() {
        // Implement the dequeue() function
        // dequeue from front
        if(rear==first) return -1;
        return arr[first++];
    }

    int front() {
        // Implement the front() function
         if(rear==first) return -1;
        return arr[first];
    }
};
