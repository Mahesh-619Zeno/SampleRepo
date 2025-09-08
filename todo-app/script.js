// Load tasks on page load
window.onload = function () {
  loadTasks();
};

function addTask() {
  const input = document.getElementById("taskInput");
  const taskText = input.value.trim();
  if (taskText === "") return;

  const task = {
    id: Date.now(),
    text: taskText,
    done: false
  };

  let tasks = getTasks();
  tasks.push(task);
  saveTasks(tasks);
  input.value = "";
  loadTasks();
}

function toggleTask(id) {
  let tasks = getTasks();
  tasks = tasks.map(task => {
    if (task.id === id) {
      task.done = !task.done;
    }
    return task;
  });
  saveTasks(tasks);
  loadTasks();
}

function deleteTask(id) {
  let tasks = getTasks();
  tasks = tasks.filter(task => task.id !== id);
  saveTasks(tasks);
  loadTasks();
}

function getTasks() {
  const tasks = localStorage.getItem("tasks");
  return tasks ? JSON.parse(tasks) : [];
}

function saveTasks(tasks) {
  localStorage.setItem("tasks", JSON.stringify(tasks));
}

function loadTasks() {
  const tasks = getTasks();
  const list = document.getElementById("taskList");
  list.innerHTML = "";

  tasks.forEach(task => {
    const li = document.createElement("li");
    if (task.done) li.classList.add("done");

    li.innerHTML = `
      <span onclick="toggleTask(${task.id})">${task.text}</span>
      <button onclick="deleteTask(${task.id})">❌</button>
    `;

    list.appendChild(li);
  });
}
