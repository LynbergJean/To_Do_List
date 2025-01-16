# ToDoList

Task Management Program

Overview: 
  -This program is a console-based task management application written in C++. 
    It allows users to add tasks, manage their progress, sort tasks by priority or due date, 
    and filter tasks by status. Subtasks and recurring tasks are also supported.



The main features include:
  1. Adding new tasks with details like description, priority, category, due date, etc.

  2. Tracking the completion of tasks and subtasks.

  3.Sorting tasks by priority.

  4.Filtering tasks by their status.

  5.Checking overdue tasks.



Features:
  -Add Task: Create a new task with customizable details.

  -View All Tasks: Display all tasks with their details.

  -Mark Task as Completed: Update the status of a task to "Completed."

  -Sort Tasks by Priority: Organize tasks based on priority (High > Medium > Low).

  -Filter Tasks by Status: Filter tasks by "Completed" or "Incomplete."

  -Track Subtask Progress: Mark individual subtasks as completed.

  -Check Overdue Tasks: Identify tasks that are overdue.


Instructions to Run

Compile the program using a C++ compiler:
- g++ -o task_manager main.cpp add_task.cpp display_tasks.cpp complete_task.cpp sort_tasks.cpp filter_tasks.cpp track_subtask_progress.cpp check_overdue_tasks.cpp
Run the program
- ./task_manager


File Structure

To decouple the code for modularity, the program has been divided into the following files:

1. main.cpp

  This file contains the main loop and the menu logic to interact with the task manager.

2. Task.h

  Defines the Task structure and related attributes.

3. add_task.cpp

  Implements the function to add a new task to the task list.

4. display_tasks.cpp

  Contains the implementation to display all tasks and their details.

5. complete_task.cpp

  Handles marking a task as completed.

6. sort_tasks.cpp

  Provides functionality to sort tasks by priority or due date.

7. filter_tasks.cpp

  Implements filtering tasks based on their status.

8. track_subtask_progress.cpp

  Tracks and updates the progress of subtasks.

9. check_overdue_tasks.cpp

  Checks and identifies overdue tasks based on the current date.



MakeShift File
# Makefile for Task Management Program

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

OBJS = main.o add_task.o display_tasks.o complete_task.o sort_tasks.o filter_tasks.o track_subtask_progress.o check_overdue_tasks.o

TARGET = task_manager

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)



Future Improvements

Implement Sorting by Due Date: Add logic to compare and sort tasks based on their due dates.

Improved Overdue Task Detection: Enhance the logic to parse and compare dates accurately.

Persistent Storage: Store tasks in a file or database for saving and retrieving tasks across sessions.

User Interface: Build a graphical interface or a web-based application for better usability.

