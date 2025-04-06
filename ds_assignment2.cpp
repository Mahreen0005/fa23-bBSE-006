#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Patient structure
struct Patient {
    string name;
    string condition;
    int priority;
    int arr_Order;

    Patient(string n, string c, int p, int a) : name(n), condition(c), priority(p), arr_Order(a) {}
};

// Custom comparator for priority queue (Min-Heap)
struct ComparePriority {
    bool operator()(const Patient& p1, const Patient& p2) {
        if (p1.priority == p2.priority)
            return p1.arr_Order > p2.arr_Order; // Earlier arrival gets priority
        return p1.priority > p2.priority; // Lower number = higher priority
    }
};

// Function to determine priority based on emergency condition
int getPriority(string condition) {
    if (condition == "Heart Attack" || condition == "Stroke") return 1;
    if (condition == "Broken Leg" || condition == "Severe Burn" || condition == "Fractured Arm") return 2;
    if (condition == "Fever" || condition == "Food Poisoning" || condition == "Migraine") return 3;
    return 4; // unknown
}

int main() {
    priority_queue<Patient, vector<Patient>, ComparePriority> pq;
    int arrival = 1;
    int choice;

    while (true) {
        cout << "\n--- Patient Treatment System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Show Current Treatment Order\n";
        cout << "3. Exit and Show Final Treatment Order\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear newline after integer input

        if (choice == 1) {
            string name, condition;
            cout << "Enter Patient Name: ";
            getline(cin, name);
            cout << "Enter Emergency Condition: ";
            getline(cin, condition);

            int priority = getPriority(condition);
            pq.push(Patient(name, condition, priority, arrival++));
            cout << "Patient added successfully!\n";
        }
        else if (choice == 2) {
            if (pq.empty()) {
                cout << "\nNo patients in the queue.\n";
            } else {
                cout << "\n--- Current Treatment Order ---\n";
                priority_queue<Patient, vector<Patient>, ComparePriority> temp = pq;
                while (!temp.empty()) {
                    Patient p = temp.top(); temp.pop();
                    cout << p.name << " | " << p.condition << " | Priority: " << p.priority << "\n";
                }
            }
        }
        else if (choice == 3) {
            if (pq.empty()) {
                cout << "\nNo patients to treat.\n";
            } else {
                cout << "\n--- Final Treatment Order ---\n";
                while (!pq.empty()) {
                    Patient p = pq.top(); pq.pop();
                    cout << p.name << " | " << p.condition << " | Priority: " << p.priority << "\n";
                }
            }
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
