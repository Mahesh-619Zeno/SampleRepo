from task_manager import TaskManager

def main():
    manager = TaskManager()

    while True:
        print("\n--- Task Manager ---")
        print("1. View Tasks")
        print("2. Add Task")
        print("3. Complete Task")
        print("4. Delete Task")
        print("5. Exit")

        choice = input("Choose an option: ")

        if choice == '1':
            manager.view_tasks()
        elif choice == '2':
            title = input("Enter task title: ")
            manager.add_task(title)
        elif choice == '3':
            task_id = int(input("Enter task ID to complete: "))
            manager.complete_task(task_id)
        elif choice == '4':
            task_id = int(input("Enter task ID to delete: "))
            manager.delete_task(task_id)
        elif choice == '5':
            print("Exiting...")
            break
        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
