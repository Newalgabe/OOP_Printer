#include <iostream>
#include <cstring>
#include "printer_queue.h"
using namespace std;

int main() 
{
    PrinterQueue printer;

    PrintRequest request1;
    strcpy_s(request1.user, "User1");
    printer.enqueuePrintRequest(request1);

    PrintRequest request2;
    strcpy_s(request2.user, "User2");
    printer.enqueuePrintRequest(request2);

    printer.processPrintRequests();

    printer.printStatistics();

    return 0;
}
