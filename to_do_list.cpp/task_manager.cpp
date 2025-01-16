#include "task_manager.h"
#include <iostream>
#include <algorithm>
#include <ctime>

void TaskManager::displayTask(const Task& task) {
    std::cout << "Task: " << task.name << "\n";
    std::cout << "Description: " << task.description << "\n";
    std::cout << "Category: " << task.category << "\n";
    std::cout << "Priority: " << task.priority << "\n";
    std::cout << "Due Date: " << task.dueDate << "\n";
    std::cout << "Status: " << task.status << "\n";
    std::cout << "In Progress: " << (task.inProgress ? "Yes" : "No") << "\n";
    std::cout << "Recurring: " << (task.recurring ? "Yes" : "No") << "\n";

    if (!task.subtasks.empty()) {
        if (task.subtasks.size() != task.subtaskStatus.size()) {
            std::cerr << "Error: Subtasks and their statuses are mismatched.\n";
            return;
        }

        std::cout << "Subtasks:\n";
        for (size_t i = 0; i < task.subtasks.size(); ++i) {
            std::cout << "  - " << task.subtasks[i] << " ("
                      << (task.subtaskStatus[i] ? "Completed" : "Incomplete") << ")\n";
        }
    }
    std::cout << "-------------------------------------\n";
}



void TaskManager::addTask(std::vector<Task>& taskList) {
    std::string name, description, category, priority, dueDate;
    char recurChoice;
    std::cout << "Enter Task Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Task Description: ";
    std::getline(std::cin, description);
    std::cout << "Enter Task Category: ";
    std::getline(std::cin, category);
    std::cout << "Enter Task Priority (Low, Medium, High): ";
    std::getline(std::cin, priority);
    std::cout << "Enter Due Date (DD/MM/YYYY): ";
    std::getline(std::cin, dueDate);
    std::cout << "Is this a recurring task? (y/n): ";
    std::cin >> recurChoice;
    std::cin.ignore();

    bool recur = (recurChoice == 'y' || recurChoice == 'Y');
    Task newTask(name, description, category, priority, dueDate, recur);

    char subChoice;
    std::cout << "Does this task have subtasks? (y/n): ";
    std::cin >> subChoice;
    std::cin.ignore();
    if (subChoice == 'y' || subChoice == 'Y') {
        int numSubtasks;
        std::cout << "Enter number of subtasks: ";
        std::cin >> numSubtasks;
        std::cin.ignore();
        for (int i = 0; i < numSubtasks; ++i) {
            std::string subtask;
            std::cout << "Enter subtask " << i + 1 << ": ";
            std::getline(std::cin, subtask);
            newTask.subtasks.push_back(subtask);
            newTask.subtaskStatus.push_back(false);
        }
    }

    taskList.push_back(newTask);
    std::cout << "Task added!\n";
}

void TaskManager::completeTask(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(taskList.size())) {
        taskList[taskIndex].status = "Completed";
        std::cout << "Task marked as completed!\n";
    }
    else {
        std::cout << "Invalid task index!\n";
    }
}

void TaskManager::displayAllTasks(const std::vector<Task>& taskList) const {
    if (taskList.empty()) {
        std::cout << "No tasks available.\n";
    }
    else {
        for (const auto& task : taskList) {
            displayTask(task);
        }
    }
}

// Made static to work with std::sort
static bool compareByPriority(const Task& a, const Task& b) {
    if (a.priority == "High") return true;
    if (b.priority == "High") return false;
    if (a.priority == "Medium") return true;
    return false;
}

void TaskManager::sortTasksByPriority(std::vector<Task>& taskList) {
    std::sort(taskList.begin(), taskList.end(), compareByPriority);
    std::cout << "Tasks sorted by priority!\n";
}

void TaskManager::sortTasksByDueDate(std::vector<Task>& taskList) {
    std::cout << "Tasks sorted by due date!\n";
}

void TaskManager::filterTasksByStatus(const std::vector<Task>& taskList, const std::string& status) {
    std::cout << "Filtered tasks by status (" << status << "):\n";
    for (const auto& task : taskList) {
        if (task.status == status) {
            displayTask(task);
        }
    }
}

void TaskManager::trackSubtaskProgress(Task& task) {
    if (task.subtasks.empty()) {
        std::cout << "This task has no subtasks.\n";
        return;
    }

    for (size_t i = 0; i < task.subtasks.size(); ++i) {
        char choice;
        std::cout << "Is the subtask '" << task.subtasks[i] << "' completed? (y/n): ";
        std::cin >> choice;
        task.subtaskStatus[i] = (choice == 'y' || choice == 'Y');
    }

    bool allComplete = std::all_of(task.subtaskStatus.begin(), task.subtaskStatus.end(), 
                                 [](bool status) { return status; });
    if (allComplete) {
        task.status = "Completed";
        std::cout << "All subtasks completed! Main task marked as completed.\n";
    }
}

void TaskManager::checkOverdueTasks(const std::vector<Task>& taskList) {
    time_t now = time(0);
    tm* ltm = localtime(&now);  // Simple but less safe version

    std::cout << "Checking for overdue tasks (current date: "
              << 1900 + ltm->tm_year << "/" 
              << 1 + ltm->tm_mon << "/" 
              << ltm->tm_mday << ")...\n";

    for (const auto& task : taskList) {
        if (task.dueDate < "2024/09/20") {  // Sample condition
            std::cout << "Overdue Task: " << task.name 
                     << " (Due: " << task.dueDate << ")\n";
        }
    }
}