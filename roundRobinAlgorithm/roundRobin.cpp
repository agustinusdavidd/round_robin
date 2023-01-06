#include "roundRobin.h"
void createAntrian(antrian &q){
    //membuat sebuah antrian kosong;
    q.head = NULL;
    q.tail = NULL;
}

bool isEmpty(antrian q){
    return q.head == NULL and q.tail == NULL;
}

void createElement(infotype newTask, adr &task){
    newTask = new element;
    newTask->info = task;
    newTask->next = NULL;
}

void enqueue(antrian &q, adr task){
    /*insert last untuk menginputkan tugas ke antrian menurut prioritasnya
    pada algoritma round robin*/
    if(isEmpty(q)){
        q.head = task;
        q.tail = task;
        return;
    }
    q.tail->next = task;
    q.tail = task;
}

void dequeue(antrian &q, adr &task){
    /*delete first digunakan untuk menghapus task yang memiliki burst time = 0*/
    if(isEmpty){cout << "Empty"; return;}
    if(q.head->info.burstTime == 0){
        task = q.head;
        q.head = task->next;
        task->next = NULL;
    }
}
