import storage

class TaskManager:
    def __init__(self):
        self.tasks = storage.load_tasks()

    def save(self):
        storage.save_tasks(self.tasks)

    def view_tasks(self):
        if not self.tasks:
            print("No tasks available.")
            return
        for idx, task in enumerate(self.tasks):
            status = "✓" if task['completed'] else "✗"
            print(f"{idx}. [{status}] {task['title']}")

    def add_task(self, title):
        self.tasks.append({'title': title, 'completed': False})
        self.save()
        print("Task added.")

    def complete_task(self, task_id):
        if 0 <= task_id < len(self.tasks):
            self.tasks[task_id]['completed'] = True
            self.save()
            print("Task marked as complete.")
        else:
            print("Invalid task ID.")

    def delete_task(self, task_id):
        if 0 <= task_id < len(self.tasks):
            del self.tasks[task_id]
            self.save()
            print("Task deleted.")
        else:
            print("Invalid task ID.")
