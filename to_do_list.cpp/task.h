#pragma once
#include <string>
#include <vector>

struct Task {
    std::string name;
    std::string description;
    std::string category;
    std::vector<std::string> tags;
    std::string priority;
    std::string dueDate;
    std::string status;
    bool inProgress;
    bool recurring;
    std::vector<std::string> subtasks;
    std::vector<bool> subtaskStatus;

    Task(std::string n, std::string d, std::string c, std::string p,
         std::string dd, bool recur = false);
};