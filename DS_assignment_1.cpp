#include <iostream>
#include <string>
using namespace std;

// Task structure for singly linked list
struct Task {
    int id; // Unique Task ID
    string description; // Task Description
    int priority; // Task Priority
    Task* next; // Pointer to next task in the list

    // Constructor to initialize a task
    Task(int taskId, string taskDesc, int taskPriority)
        : id(taskId), description(taskDesc), priority(taskPriority), next(nullptr) {}
};

class TaskManager {
private:
    Task* head; // Head pointer for the linked list

public:
    TaskManager() : head(nullptr) {} // Constructor initializes head to nullptr

    // Function to add a task based on priority (higher priority tasks come first)
    void addTask(int id, string description, int priority) {
        Task* newTask = new Task(id, description, priority);
        // If list is empty or new task has highest priority, insert at head
        if (!head || priority > head->priority) {
            newTask->next = head;
            head = newTask;
        } else {
            // Traverse the list to find correct position
            Task* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            // Insert new task at appropriate position
            newTask->next = temp->next;
            temp->next = newTask;
        }
        cout << "Task added successfully.\n";
    }

    // Function to remove the highest priority task (task at the start of the list)
    void removeHighestPriorityTask() {
        if (!head) {
            cout << "No tasks available to remove.\n";
            return;
        }
        Task* temp = head; // Store reference to head
        head = head->next; // Move head to next node
        cout << "Removed Task ID: " << temp->id << " with priority " << temp->priority << "\n";
        delete temp; // Free memory
    }

    // Function to remove a task by its ID
    void removeTaskById(int id) {
        if (!head) {
            cout << "No tasks available to remove.\n";
            return;
        }
        // If the task to remove is the head
        if (head->id == id) {
            Task* temp = head;
            head = head->next;
            delete temp;
            cout << "Task removed successfully.\n";
            return;
        }
        Task* temp = head;
        // Traverse to find the task to remove
        while (temp->next && temp->next->id != id) {
            temp = temp->next;
        }
        // If task not found
        if (!temp->next) {
            cout << "Task not found.\n";
            return;
        }
        // Remove task and adjust pointers
        Task* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Task removed successfully.\n";
    }

    // Function to display all tasks in the list
    void displayTasks() {
        if (!head) {
            cout << "No tasks available.\n";
            return;
        }
        Task* temp = head;
        cout << "Task List:\n";
        // Traverse the list and print each task
        while (temp) {
            cout << "ID: " << temp->id << ", Description: " << temp->description
                 << ", Priority: " << temp->priority << "\n";
            temp = temp->next;
        }
    }

    // Destructor to free allocated memory
    ~TaskManager() {
        while (head) {
            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TaskManager manager; // Create a TaskManager object
    int choice, id, priority;
    string description;

    do {
        // Console menu for task management
        cout << "\nTask Management System\n";
        cout << "1. Add Task\n2. View All Tasks\n3. Remove Highest Priority Task\n4. Remove Task by ID\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                // Adding a new task
                cout << "Enter Task ID: ";
                cin >> id;
                cin.ignore(); // Ignore newline character
                cout << "Enter Task Description: ";
                getline(cin, description);
                cout << "Enter Priority Level: ";
                cin >> priority;
                manager.addTask(id, description, priority);
                break;
            case 2:
                // Viewing all tasks
                manager.displayTasks();
                break;
            case 3:
                // Removing the highest priority task
                manager.removeHighestPriorityTask();
                break;
            case 4:
                // Removing a task by ID
                cout << "Enter Task ID to remove: ";
                cin >> id;
                manager.removeTaskById(id);
                break;
            case 5:
                // Exiting program
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
