#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Process {
    int pid;
    string name;
    int burstTime;
    Process(int id, const string& n, int bt) : pid(id), name(n), burstTime(bt) {}
};

class Scheduler {
private:
    vector<Process> processes;
    int nextPid = 1;

public:
    void addProcess(const string& name, int burstTime) {
        processes.emplace_back(nextPid++, name, burstTime);
        cout << "Process added: " << name << " (PID: " << nextPid - 1 << ")\n";
    }

    void listProcesses() const {
        cout << "Processes:\n";
        for (const auto& p : processes) {
            cout << "PID: " << p.pid << ", Name: " << p.name << ", Burst Time: " << p.burstTime << endl;
        }
    }

    // ...existing code...

void run() {
    if (processes.empty()) {
        cout << "No processes to run.\n";
        return;
    }
    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;
    vector<int> remainingBurst(processes.size());
    for (size_t i = 0; i < processes.size(); ++i) {
        remainingBurst[i] = processes[i].burstTime;
    }
    int time = 0;
    bool done;
    cout << "Running processes (Round Robin):\n";
    do {
        done = true;
        for (size_t i = 0; i < processes.size(); ++i) {
            if (remainingBurst[i] > 0) {
                done = false;
                int runTime = min(quantum, remainingBurst[i]);
                cout << "Time " << time << ": Running PID " << processes[i].pid
                     << " (" << processes[i].name << ") for " << runTime << " units.\n";
                remainingBurst[i] -= runTime;
                time += runTime;
                if (remainingBurst[i] == 0) {
                    cout << "PID " << processes[i].pid << " (" << processes[i].name << ") finished.\n";
                }
            }
        }
    } while (!done);
}
};

// Example usage
/*int main() {
    Scheduler scheduler;
    scheduler.addProcess("ProcessA", 5);
    scheduler.addProcess("ProcessB", 3);
    scheduler.listProcesses();
    scheduler.run();
    return 0;
}*/