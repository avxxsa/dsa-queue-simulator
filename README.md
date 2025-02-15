# DSA Queue Traffic Simulator 🚦

This is my implementation of a **queue-based traffic simulation** for a four-way junction.  
The project models **traffic lights**, **vehicle queues**, and **priority-based rules** using **C programming**.

---

## 🚀 Features
✅ Simulates **real-world traffic flow** using queue data structures  
✅ Uses **file-based communication** to pass vehicle data between processes  
✅ Implements **priority-based traffic light control** for efficient vehicle movement  
✅ Processes **vehicles dynamically** based on queue conditions  

---

## 🛠 How I Compiled and Ran the Program  

### **Step 1: Install Dependencies**  
Before compiling, ensure that **SDL2 and SDL2_ttf** are installed.
Run the following in the **MSYS2 MinGW64 terminal**:
```sh
pacman -S mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_ttf
```  
### **Step 2: Compiling the Program**
```sh
gcc src/simulator.c src/queue.c -o simulator.exe -I include -I C:/msys64/mingw64/include -L C:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lpthread
```
### **Step 3: Running the Simulator**
```sh
.\simulator.exe
```
---

## 📸 Demo (Screenshots)
![Traffic SDL2 Simulation Demo](ss1.png)
![Traffic Terminal Output Demo](ss2.png)

---

## 📂 Project Structure
This is how my project files are organized:

📦 dsa-queue-simulator
├── 📂 src
│   ├── simulator.c
│   ├── traffic_generator.c
│   ├── queue.c
│   ├── traffic_light.c
│   ├── test_queue.c
│   ├── test_traffic_light.c
│
├── 📂 include
│   ├── queue.h
│   ├── traffic_light.h
│   ├── traffic_generator.h
│
├── 📂 .vscode
│   ├── c_cpp_properties.json  # VS Code config for C++
│
├── 📂 docs
│   ├── report.pdf  (Final report will be added here)
│
├── SDL2.dll                 # Required for SDL2 on Windows
├── SDL2_ttf.dll             # Required for SDL2 fonts on Windows
├── vehicles.data            # Stores generated traffic data
└── README.md

---

## 📚 References
I referred to the following resources while implementing this project:
- [Simple DirectMedia Layer 2.0 (SDL2) Documentation](https://wiki.libsdl.org/SDL2/FrontPage)
- Data Structure & Algorithms (COMP202) - Assignment PDF and Skeleton Codes (provided by the professor)

---

## 🔗 GitHub Repository  
You can find the complete source code here:  
[GitHub Repository](https://github.com/avxxsa/dsa-queue-simulator)