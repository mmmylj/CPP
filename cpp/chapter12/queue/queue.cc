#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    item = 0;
}

Queue::~Queue()
{
    Node * temp;
    while(front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return item == 0;
}

bool Queue::isfull() const
{
    return item == qsize;
}

int Queue::queuecount() const
{
    return item;
}

//Add item to queue
int Queue::enqueue(const Item & newitem)
{
    if (isfull())
        return 0;
    Node * add = new Node;
    add->item = newitem;
    add->next = nullptr;
    item++;
    if (front = nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return 1;  
}

int Queue::dequeue(Item &newitem)
{
    if (front = nullptr)
        return 0;
    newitem = front->item;
    item--;
    Node * temp = front;
    front = front->next;
    delete temp; 
    if(item == 0)
        rear = nullptr;
    return  1;
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 +1;
    arrive = when;
}