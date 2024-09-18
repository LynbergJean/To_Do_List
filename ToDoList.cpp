#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Task struct definition
struct Task {
    string name;
    string description;
    string category;
    vector<string> tags;
    string priority;
    string dueDate;
    string status;
    bool inProgress;
    bool recurring;
    vector<string> subtasks;
    vector<bool> subtaskStatus;

    Task(string n, string d, string c, string p, string dd, bool recur = false)
        : name(n), description(d), category(c), priority(p), dueDate(dd), status("Incomplete"), inProgress(false), recurring(recur) {}
};

// Function to display a task
void displayTask(const Task& task) {
    cout << "Task: " << task.name << "\n";
    cout << "Description: " << task.description << "\n";
    cout << "Category: " << task.category << "\n";
    cout << "Priority: " << task.priority << "\n";
    cout << "Due Date: " << task.dueDate << "\n";
    cout << "Status: " << task.status << "\n";
    cout << "In Progress: " << (task.inProgress ? "Yes" : "No") << "\n";
    cout << "Recurring: " << (task.recurring ? "Yes" : "No") << "\n";

    // Display subtasks if available
    if (!task.subtasks.empty()) {
        cout << "Subtasks:\n";
        for (size_t i = 0; i < task.subtasks.size(); ++i) {
            cout << "  - " << task.subtasks[i] << " ("
                << (task.subtaskStatus[i] ? "Completed" : "Incomplete") << ")\n";
        }
    }
    cout << "-------------------------------------\n";
}

// Add new task
void addTask(vector<Task>& taskList) {
    string name, description, category, priority, dueDate;
    char recurChoice;
    cout << "Enter Task Name: ";
    getline(cin, name);
    cout << "Enter Task Description: ";
    getline(cin, description);
    cout << "Enter Task Category: ";
    getline(cin, category);
    cout << "Enter Task Priority (Low, Medium, High): ";
    getline(cin, priority);
    cout << "Enter Due Date (DD/MM/YYYY): ";
    getline(cin, dueDate);
    cout << "Is this a recurring task? (y/n): ";
    cin >> recurChoice;
    cin.ignore(); // Ignore newline after input

    bool recur = (recurChoice == 'y' || recurChoice == 'Y');
    Task newTask(name, description, category, priority, dueDate, recur);

    // Add subtasks if needed
    char subChoice;
    cout << "Does this task have subtasks? (y/n): ";
    cin >> subChoice;
    cin.ignore();
    if (subChoice == 'y' || subChoice == 'Y') {
        int numSubtasks;
        cout << "Enter number of subtasks: ";
        cin >> numSubtasks;
        cin.ignore();
        for (int i = 0; i < numSubtasks; ++i) {
            string subtask;
            cout << "Enter subtask " << i + 1 << ": ";
            getline(cin, subtask);
            newTask.subtasks.push_back(subtask);
            newTask.subtaskStatus.push_back(false); // Initially incomplete
        }
    }

    taskList.push_back(newTask);
    cout << "Task added!\n";
}

// Mark a task as completed
void completeTask(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].status = "Completed";
        cout << "Task marked as completed!\n";
    }
    else {
        cout << "Invalid task index!\n";
    }
}

// Display all tasks
void displayAllTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks available.\n";
    }
    else {
        for (const auto& task : taskList) {
            displayTask(task);
        }
    }
}

// Sort tasks by priority
bool compareByPriority(const Task& a, const Task& b) {
    if (a.priority == "High") return true;
    if (b.priority == "High") return false;
    if (a.priority == "Medium") return true;
    return false;
}

void sortTasksByPriority(vector<Task>& taskList) {
    sort(taskList.begin(), taskList.end(), compareByPriority);
    cout << "Tasks sorted by priority!\n";
}

// Sort tasks by due date (not implemented, placeholder)
void sortTasksByDueDate(vector<Task>& taskList) {
    // Placeholder function - implement due date comparison logic
    cout << "Tasks sorted by due date!\n";
}

// Filter tasks by status
void filterTasksByStatus(const vector<Task>& taskList, const string& status) {
    cout << "Filtered tasks by status (" << status << "):\n";
    for (const auto& task : taskList) {
        if (task.status == status) {
            displayTask(task);
        }
    }
}

// Track progress of subtasks
void trackSubtaskProgress(Task& task) {
    if (task.subtasks.empty()) {
        cout << "This task has no subtasks.\n";
        return;
    }

    for (size_t i = 0; i < task.subtasks.size(); ++i) {
        char choice;
        cout << "Is the subtask '" << task.subtasks[i] << "' completed? (y/n): ";
        cin >> choice;
        task.subtaskStatus[i] = (choice == 'y' || choice == 'Y');
    }

    // If all subtasks are complete, mark the main task as complete
    bool allComplete = all_of(task.subtaskStatus.begin(), task.subtaskStatus.end(), [](bool status) { return status; });
    if (allComplete) {
        task.status = "Completed";
        cout << "All subtasks completed! Main task marked as completed.\n";
    }
}

// Example function to check overdue tasks (not fully implemented)
void checkOverdueTasks(const vector<Task>& taskList) {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now); // Using localtime_s for safety
    cout << "Checking for overdue tasks (current date: "
        << 1900 + ltm.tm_year << "/" << 1 + ltm.tm_mon << "/" << ltm.tm_mday << ")...\n";

    // Logic for checking dates should go here
    // Placeholder, assume tasks are overdue if they match a certain condition
    for (const auto& task : taskList) {
        // Example logic to mark a task overdue
        if (task.dueDate < "2024/09/20") {  // Sample condition, assuming date format is YYYY/MM/DD
            cout << "Overdue Task: " << task.name << " (Due: " << task.dueDate << ")\n";
        }
    }
}

int main() {
    vector<Task> taskList;
    int choice;

    while (true) {
        cout << "1. Add Task\n2. View All Tasks\n3. Mark Task as Completed\n4. Sort Tasks by Priority\n"
            << "5. Filter Tasks by Status\n6. Track Subtask Progress\n7. Check Overdue Tasks\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline after choice input

        switch (choice) {
        case 1:
            addTask(taskList);
            break;
        case 2:
            displayAllTasks(taskList);
            break;
        case 3: {
            int taskIndex;
            cout << "Enter task index to complete: ";
            cin >> taskIndex;
            completeTask(taskList, taskIndex - 1); // User-friendly 1-based index
            break;
        }
        case 4:
            sortTasksByPriority(taskList);
            break;
        case 5: {
            string status;
            cout << "Enter status to filter by (Completed/Incomplete): ";
            cin >> status;
            filterTasksByStatus(taskList, status);
            break;
        }
        case 6: {
            int taskIndex;
            cout << "Enter task index to track subtasks: ";
            cin >> taskIndex;
            trackSubtaskProgress(taskList[taskIndex - 1]); // 1-based index
            break;
        }
        case 7:
            checkOverdueTasks(taskList);
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
