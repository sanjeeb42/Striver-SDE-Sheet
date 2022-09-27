class MyCircularQueue {
public:
    
    int circual_queue[3003];
    int s, e, size;
    
    MyCircularQueue(int k) {
        size = k;
        s = 0;
        e = 0;
    }
    
    bool enQueue(int value) {
        if ((e - s) == size) return (false);
        circual_queue[e++] = value;
        return (true);
    }
    
    bool deQueue() {
        if (e == s) return (false);
        s++;
        return (true);
    }
    
    int Front() {
        if (e == s) return (-1);
        return (circual_queue[s]);
    }
    
    int Rear() {
        if (e == s) return (-1);
        return (circual_queue[e - 1]);
    }
    
    bool isEmpty() {
        return (e == s);
    }
    
    bool isFull() {
        return ((e - s) == size);
    }
};
