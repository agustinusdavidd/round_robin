#include "roundRobin.h"

int main()
{
    infotype task; adr highPriorityTask;
    antrian high; createAntrian(high);
    bool check = false; int more = 0;
    while (!check) {
        cout << "Masukkan id task : "; cin >> task.id;
        cout << "Masukkan burst time : "; cin >> task.burstTime;
        createElement(task, highPriorityTask);
        enqueue(high, highPriorityTask);
        cout << "New Task? [0/1] : "; cin >> more;
        if (more == 0) { check = true; }
    }
    show(high);
    cout << "\n";
    executeTask(high);
    cout << "Hello world!" << endl;
    return 0;
}
