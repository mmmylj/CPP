#ifndef QUEUE_H_
#define QUEUE_H_
//this Queue will contain Customer item
class Customer
{
    private:
        long arrive;
        int processtime;
    public:
        Customer() {arrive = processtime = 0;}

        void set(long when);
        long when() const {return arrive;}
        int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue
{
private:
    struct Node
    {
        Item item;
        struct Node * next;
    };

    enum {Q_size = 10};
    Node * front; //pointer to fornt of queue
    Node * rear;    //pointer to rear of queue
    int item;   //current number of item in queue
    const int qsize;    //max number of item in queue
    //prevent public copying
    Queue(const Queue & q) : qsize(0){};
    Queue & operator=(const Queue & q) {return *this;}
    
public:
    Queue(int qs =  Q_size);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    int enqueue(const Item &item);
    int dequeue(Item &item);
};

#endif