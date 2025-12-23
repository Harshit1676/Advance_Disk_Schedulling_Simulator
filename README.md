# 🚀 Advanced Disk Scheduling Simulator  
### A C-based Operating Systems Project  
#### Author: **Harshit1676** | Roll No: **10**

---

## 📌 Overview  

Disk scheduling plays a critical role in Operating Systems by minimizing disk head movement and improving overall I/O performance.  
This project implements a complete **Disk Scheduling Simulator** in **C**, supporting the following algorithms:

- **FCFS** (First-Come First-Served)  
- **SSTF** (Shortest Seek Time First)  
- **SCAN** (Elevator Algorithm)  
- **C-SCAN** (Circular SCAN)

The simulator accepts user-defined disk requests, head position, disk size, scanning direction, and produces:

✅ Disk head movement path  
✅ Total head movement  
✅ Average seek time  
✅ System throughput  
✅ Side-by-side comparison  

---

## 📂 Project Structure

```
📁 Advance_Disk_Schedulling_Simulator
│── disk_scheduling.c
│── FCFS_pseudo.c
│── SSTF_pseudo.c
│── SCAN_pseudo.c
│── C-SCAN_pseudo.c
│── README.md
│── disk_scheduling.exe        (optional)

```

---

## 📌 Features

### 🎯 User Inputs
- Disk size  
- Number of requests  
- Request sequence  
- Initial head position  
- Direction (left / right) for SCAN & C-SCAN  

### ⚙️ Algorithms Implemented
| Algorithm | Description |
|----------|-------------|
| **FCFS** | Serves requests in the order of arrival |
| **SSTF** | Chooses the closest request to current head |
| **SCAN** | Moves head like an elevator (left → right → left) |
| **C-SCAN** | Uniform wait time: circular movement |

### 📊 Metrics Displayed
- Total Head Movement  
- Average Seek Time  
- Throughput  

---

## 🧠 How It Works

Each algorithm processes requests differently:

### FCFS  
Simple but potentially inefficient.

### SSTF  
Optimizes movement but may cause starvation.

### SCAN  
Head moves in a direction till end → reverses direction.

### C-SCAN  
Head moves one direction → jumps back to start → continues.

---

## 🛠️ Compilation & Execution

### Compile:
```
gcc disk_scheduling.c -o disk
```

### Run:
```
./disk
```

---

## 📈 Sample Input  
```
Enter disk size: 200
Enter number of requests: 8
Enter requests:
82 170 43 140 24 16 190 95
Enter initial head position: 50
Enter direction (0=left,1=right): 1
```

---

## 📤 Sample Output (Shortened)
```
FCFS Head Path: 50 -> 82 -> 170 -> 43 -> 140 -> 24 -> 16 -> 190 -> 95
Total Movement: XXX
Average Seek Time: XXX
Throughput: XXX

SSTF Head Path: ...
SCAN Head Path: ...
C-SCAN Head Path: ...
```

---

## 🧾 Future Enhancements

- Add LOOK & C-LOOK algorithms  
- Implement GUI visualization (Python/Tkinter or Web UI)  
- Export results to CSV or PDF  
- Automate best algorithm recommendation  

---

## 📚 References  

- Silberschatz, Galvin — *Operating System Concepts*  
- Stallings — *Operating Systems: Internals and Design Principles*  
- CSE316 OS Course Material (LPU)  

---

## ⭐ About the Author  
**Harshit Pandey**  
Roll No: 10  
B.Tech CSE  
GitHub: [@Harshit1676](https://github.com/Harshit1676)

---

### 🚀 *If you like this project, give it a ⭐ on GitHub!*
## Features
- FCFS, SSTF, SCAN, C-SCAN algorithms
- Head movement visualization
- Seek time and throughput calculation
