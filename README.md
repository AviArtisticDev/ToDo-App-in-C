# 📝 Console-Based ToDo App in C (Windows Only)

This is a lightweight, interactive **ToDo List Application** written in **C** for the Windows terminal.  
It uses character-by-character input, real-time cursor control, and file saving to create a smooth terminal experience — like a mini command-line productivity tool!


---

## 📌 Features

- ✅ Add, delete, and mark todos as complete  
- ✍️ Live character counter while typing a todo (`[12/43]`)  
- 🚫 Prevents empty or overlong todo titles  
- 💾 Saves todos in a local binary file (`todostrail.bin`)  
- ♻️ Redraws screen and updates list after every action  
- 🧠 Keyboard input using `getch()` and cursor control  
- 🪟 Built for **Windows** using `conio.h` and `windows.h`

---

## 📸 Demo

```
Type Your ToDo
> Learn C deeply                 [15/43]

__________________________________________________________________________________
|  Id  |                    Title                    |   Created At   |  Status  |
+------+---------------------------------------------+----------------+----------+
|  1   | Learn C deeply                              | 04/08 16:01    | No       |
+------+---------------------------------------------+----------------+----------+
```

---

## 🧪 How to Run

> 📌 Requires: Windows + GCC compiler (MinGW or similar)

1. Open a terminal or command prompt.
2. Compile:

```bash
gcc todoTrail.c -o todoTrail.exe
```

3. Run:

```bash
./todoTrail.exe
```

---

## ⚙️ Technical Details

- ✅ Maximum 20 todos allowed (`#define MAX_TODOS 20`)
- ✍️ Maximum title length: 43 characters
- 📁 Data stored in a binary file: `todostrail.bin`
- 🖥️ Console cleared and redrawn using `system("cls")`
- ⌨️ Real-time keyboard input using `getch()` from `conio.h`
- 🧭 Cursor positioning with `SetConsoleCursorPosition()` from `windows.h`

---

## 🚧 Limitations

- ❌ Not cross-platform (Windows only)
- 📄 Data is stored in binary format (not human-readable)
- 🔁 No search or sorting (yet)
- 🧠 Advanced key handling (like arrow keys) not yet supported

---

## 💡 Future Improvements

- [ ] Cross-platform support (Linux/macOS) using `ncurses` or similar
- [ ] Export todos in `.txt` or `.json` format
- [ ] Search/filter todos
- [ ] Due dates, categories, reminders
- [ ] Simple GUI using Win32 API or web interface

---

## 🙋 Author

**👤 Avinash**  

💡 Curious about real system programming and building practical tools with C.

---

## 🛠 Built With

- C (Standard + Windows-specific)
- GCC (MinGW on Windows)
- Notepad++ / VS Code / any C editor
- Terminal / Command Prompt

---

## 📜 License

This project is completely free to use for learning, personal, or academic use.  
No restrictions. Feel free to fork, modify, or share.

---

## 📬 Contact / Contributions

Want to contribute or collaborate?  
Open a pull request, raise an issue, or connect on GitHub!
