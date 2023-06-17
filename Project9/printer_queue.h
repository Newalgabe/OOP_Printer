struct PrintRequest 
{
    char user[50];
};

class PrinterQueue 
{
private:
    static const int MAX_QUEUE_SIZE = 100;
    PrintRequest printQueue[MAX_QUEUE_SIZE];
    int front;
    int rear;

public:
    PrinterQueue();
    void enqueuePrintRequest(const PrintRequest& request);
    void processPrintRequests();
    void printStatistics();
};