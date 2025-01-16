#include "task.h"

Task::Task(std::string n, std::string d, std::string c, std::string p,
           std::string dd, bool recur)
    : name(n)
    , description(d)
    , category(c)
    , priority(p)
    , dueDate(dd)
    , status("Incomplete")
    , inProgress(false)
    , recurring(recur) 
{}