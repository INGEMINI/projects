package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	tasks := []string{}
	reader := bufio.NewReader(os.Stdin) // Reader for handling multi-word input

	for {
		fmt.Println("1. Add task\n2. View tasks\n3. Delete task\n4. Exit")
		fmt.Print("Enter your choice: ")
		var choice int
		fmt.Scanln(&choice)

		switch choice {
		case 1:
			fmt.Print("Enter task: ")
			task, _ := reader.ReadString('\n') // Read the full line of input
			task = strings.TrimSpace(task)     // Remove trailing newline or spaces
			tasks = append(tasks, task)
			fmt.Println("Task added successfully!")
		case 2:
			if len(tasks) == 0 {
				fmt.Println("No tasks available.")
			} else {
				fmt.Println("Tasks:")
				for i, t := range tasks {
					fmt.Printf("%d. %s\n", i+1, t)
				}
			}
		case 3:
			fmt.Print("Enter task number to delete: ")
			var num int
			fmt.Scanln(&num)

			if num > 0 && num <= len(tasks) {
				tasks = append(tasks[:num-1], tasks[num:]...)
				fmt.Println("Task deleted successfully!")
			} else {
				fmt.Println("Invalid task number!")
			}
		case 4:
			fmt.Println("Goodbye!")
			return
		default:
			fmt.Println("Invalid choice")
		}
	}
}
