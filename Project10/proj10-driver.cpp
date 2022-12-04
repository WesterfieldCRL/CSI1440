#include <iostream>
#include <ctime>
#include "proj10-Queue1.h"
#include "proj10-Queue2.h"
#include "proj10-Queue3.h"

using namespace std;

int main()
{
    Queue1<int> q1;
    Queue2<int> q2;
    Queue3<int> q3;
    int num = 100;
    
    unsigned int start = time(NULL);

    for (int i = 0; i < num; i++)
    {
        int n = rand()%10;
        q1.enqueue(n);
        q2.enqueue(n);
    }

    cout << "testinge queue1" << endl;

    start = time(NULL);

    for (int i = 0; i < num; i++)
    {
        int n;
        q1.dequeue(n);
    }

    cout << time(NULL) - start << endl;

    cout << "testing queue2" << endl;

    start = time(NULL);

    for (int i = 0; i < num; i++)
    {
        int n;
        q2.dequeue(n);
    }

    cout << time(NULL) - start << endl;

    for (int i = 0; i < num; i++)
    {
        q3.enqueue(rand()%10);
    }

    cout << "testing queue3" << endl;

    start = time(NULL);

    

    for (int i = 0; i < num; i++)
    {
        int n;
        q3.dequeue(n);
    }

    cout << time(NULL) - start << endl;

    return 0;
}