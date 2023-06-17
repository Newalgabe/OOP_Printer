#include "printer_queue.h"
#include <iostream>
#include <cstring>

using namespace std;

PrinterQueue::PrinterQueue() : front(0), rear(0)
{}

void PrinterQueue::enqueuePrintRequest(const PrintRequest& request) 
{
    if ((rear + 1) % MAX_QUEUE_SIZE == front) 
    {
        cout << "Print queue is full. Cannot add user request from: " << request.user << endl;
        return;
    }

    strcpy_s(printQueue[rear].user, request.user);
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    cout << "Print request from user " << request.user << " added to the queue." << endl;
}

void PrinterQueue::processPrintRequests()
{
    while (front != rear)
    {
        PrintRequest request = printQueue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        cout << "Printing request from user " << request.user << endl;
    }
}

void PrinterQueue::printStatistics() 
{
    cout << "Printing history:" << endl;
    int current = front;
    while (current != rear) 
    {
        PrintRequest request = printQueue[current];
        current = (current + 1) % MAX_QUEUE_SIZE;
        cout << "User: " << request.user << endl;
    }
}
