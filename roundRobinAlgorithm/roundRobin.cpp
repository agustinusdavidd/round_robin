#include "roundRobin.h"
void createAntrian(antrian& q) {
    //membuat sebuah antrian kosong;
    q.head = NULL;
    q.tail = NULL;
}

bool isEmpty(antrian q) {
    //jika antrian(priority) kosong maka tidak akan digunakan lagi
    return q.head == NULL and q.tail == NULL;
}

void createElement(infotype newTask, adr& task) {
    task = new element;
    task->info = newTask;
    task->next = NULL;
}

void enqueue(antrian& q, adr task) {
    /*insert last untuk menginputkan tugas ke antrian menurut prioritasnya
    pada algoritma round robin*/
    if (isEmpty(q)) {
        q.head = task;
        q.tail = task;
        return;
    }
    q.tail->next = task;
    q.tail = task;
}

void dequeue(antrian& q, adr& task) {
    /*delete first digunakan untuk menghapus task yang memiliki burst time = 0*/
    if (isEmpty(q)) { cout << "Empty"; return; }
    task = q.head;
    q.head = q.head->next;
    if (q.head == NULL) {
        q.tail = NULL;
    }
    /*if(q.head->info.burstTime == 0){
        task = q.head;
        q.head = task->next;
        task->next = NULL;
    }*/
}

void show(antrian q) {
    //dibuat oleh david
    adr curr = q.head;
    while (curr != NULL) {
        cout << "id : " << curr->info.id << " burst time : " << curr->info.burstTime << endl;
        curr = curr->next;
    }
}

void executeTask(antrian q) {
    //dibuat oleh david
    int time = 0;
    adr task;
    while (q.head != NULL) {
        dequeue(q, task);
        if (task->info.burstTime > quantum) {
            task->info.burstTime -= quantum;
            time += quantum;
            enqueue(q, task);
        }
        else {
            time += task->info.burstTime;
        }
        cout << "TASK " << task->info.id << " EXECUTED" << endl;
    }
}
