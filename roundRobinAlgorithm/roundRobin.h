#ifndef ROUNDROBIN_H_INCLUDED
#define ROUNDROBIN_H_INCLUDED
#define quantum 15
#include <iostream>
using namespace std;

struct infotype {
    string id;
    int burstTime;
};
typedef struct element* adr;
struct element {
    infotype info;
    adr next;
};
struct antrian {
    adr head, tail;
};

void createAntrian(antrian& q);
void createElement(infotype newTask, adr& task);
void enqueue(antrian& q, adr task);
void dequeue(antrian& q, adr& task);
void show(antrian q);
void executeTask(antrian q);
#endif // ROUNDROBIN_H_INCLUDED
