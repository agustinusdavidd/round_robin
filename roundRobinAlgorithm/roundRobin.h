#ifndef ROUNDROBIN_H_INCLUDED
#define ROUNDROBIN_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    string id;
    int burstTime;
};
typedef struct element *adr;
struct element{
    infotype info;
    adr next;
};
struct antrian{
    adr head, tail;
};


#endif // ROUNDROBIN_H_INCLUDED
