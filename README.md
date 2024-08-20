# ToDoList
ToDoList is a simple, CLI-based ToDo List built in pure C++, with a focus on simplicity.
---
## Usage
`ToDoList <command>`
## Commands
### help
Outputs the help menu for ToDoList.

### add
Add an item to the list.

### list
List all items currently in the list, along with their status.

### check
Alias for list

### delete <id>
Delete an item from the list that has the corresponding id number. 
Find the ID number using `ToDoList <check/list>`

### toggle <id>
Toggle the completion status of an item that has the corresponding id number.
Find the ID number using `ToDoList <check/list>`

### clear
Clear all items that have been completed.
The same as calling `delete` on each id with the completed flag.
