#include "task_manager.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Task> taskList;
    TaskManager manager;
    int choice;

    while (true) {
        std::cout << "1. Add Task\n2. View All Tasks\n3. Mark Task as Completed\n"
                  << "4. Sort Tasks by Priority\n5. Filter Tasks by Status\n"
                  << "6. Track Subtask Progress\n7. Check Overdue Tasks\n8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                manager.addTask(taskList);
                break;
            case 2:
                manager.displayAllTasks(taskList);
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task index to complete: ";
                std::cin >> taskIndex;
                manager.completeTask(taskList, taskIndex - 1); // User-friendly 1-based index
                break;
            }
            case 4:
                manager.sortTasksByPriority(taskList);
                break;
            case 5: {
                std::string status;
                std::cout << "Enter status to filter by (Completed/Incomplete): ";
                std::cin >> status;
                manager.filterTasksByStatus(taskList, status);
                break;
            }
            case 6: {
                int taskIndex;
                std::cout << "Enter task index to track subtasks: ";
                std::cin >> taskIndex;
                manager.trackSubtaskProgress(taskList[taskIndex - 1]); // 1-based index
                break;
            }
            case 7:
                manager.checkOverdueTasks(taskList);
                break;
            case 8:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
    return 0;
}