# Custom Operating System 2002

A **UNIX-style OS simulation** in C++ featuring a simple **scheduler**, **file system**, **text editor**, and **calculator** — all operable through a command-line interface.

---

## 🚀 Features

* **Scheduler**: Round-Robin scheduling simulation with user-defined quantum.
* **File System**: In-memory CRUD operations with metadata (creation & modification time).
* **Text Editor**: Console-based `.txt` file editor supporting file creation and viewing and editing.
* **Calculator**: Simple arithmetic calculator (Add, Subtract, Multiply, Divide).

---

## 🧱 Folder Structure

```
CustomOs2002/
├── os/             # Main entry point and OS launcher
├── scheduler/      # Scheduler module
├── filesystem/     # File system module with File and FileSystem classes
├── editor/         # Text editor module
├── calculator/     # Calculator module
└── README.md       # Project documentation
```

---

## 🛠️ Tools Used

* c++ 6.3.0 or above
* Standard c++ libraries only

---

## 💡 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/Magnus0969/CustomOs2002.git
cd custom os
```

### 2. Compile

```bash
g++ os/CustomOS.cpp calculator/Calculator.cpp editor/TextEditor.cpp filesystem/FileSystem.cpp -o CustomOS.exe
```

### 3. Run

```bash
.\CustomOS.exe
```

---

## 🧠 Learning Outcomes

* Process scheduling fundamentals
* Java file I/O operations and console input handling
* Modular design and object-oriented programming
* Simulation of basic operating system components

---

## 🔮 Future Enhancements

* [ ] Add First-Come-First-Serve (FCFS) and Shortest-Job-First (SJF) scheduling
* [ ] Persistent file system with disk storage
* [ ] Richer text editor with editing commands
* [ ] Scientific calculator features
* [ ] Add shell command simulation interface

---

## 👨‍💻 Author

**Ayush Singh**
🔗 [GitHub Profile](https://github.com/Ayus054)
