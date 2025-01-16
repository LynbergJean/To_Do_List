// task_manager.h
#pragma once
#include "task.h"
#include <vector>

class TaskManager {
public:
    void addTask(std::vector<Task>& taskList);
    void completeTask(std::vector<Task>& taskList, int taskIndex);
    void displayAllTasks(const std::vector<Task>& taskList) const;
    void displayTask(const Task& task) const;
    void sortTasksByPriority(std::vector<Task>& taskList);
    void sortTasksByDueDate(std::vector<Task>& taskList);
    void filterTasksByStatus(const std::vector<Task>& taskList, const std::string& status);
    void trackSubtaskProgress(Task& task);
    void checkOverdueTasks(const std::vector<Task>& taskList);
private:
    bool compareByPriority(const Task& a, const Task& b);
};
