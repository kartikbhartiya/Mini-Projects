# 🧠 Typing Speed Tester (C Language)

A minimal yet functional **terminal-based typing speed test** written entirely in **C**. It calculates your **Words Per Minute (WPM)** and **accuracy** based on a randomly selected motivational sentence. Built for speed, precision, and learning.

---

## 🚀 Features

- ✅ Measures **WPM (Words Per Minute)** based on standard 5-character word length
- ✅ Calculates **accuracy** compared to the original sentence
- ✅ Uses `clock()` for accurate time measurement
- ✅ Random sentence generator using `srand(time(0))`
- ✅ Input-safe with buffer overflow protection
- ✅ Pure C, no external libraries

---

## 🛠️ How It Works

1. The program displays instructions and waits for you to press a key.
2. A **random sentence** appears on screen.
3. You type it as fast and accurately as you can.
4. The program calculates:
   - **WPM** = `(chars / 5) / time_in_minutes`
   - **Accuracy** = `(matching chars / total chars in original) * 100`
5. Results are printed on-screen.

---

### 🧱 Compile
```bash
gcc main.c -o main.exe
.\main
```

---

```bash
Instructions:- After you press Enter a sentence will be shown...
Press any number and hit enter to start

Type this:
"The code you write reflects the precision of your hands. Let every keystroke echo your discipline."

WPM:- 52
Accuracy:- 93.65
Time Taken:- 18.34
```

---

## 🎯 Why I Built This

I built this project as a quick and effective way to:

- Practice C programming  
- Reinforce concepts like time handling, strings, and user input  
- Build a foundation for more complex CLI tools  

---

## 📚 Tech Stack

- **Language:** C (ANSI C)  
- **Compiler:** gcc  
- **OS:** Platform-independent (Linux/Windows)  

---

## 🤖 Author

**Kartik Bhartiya**  
[GitHub](https://github.com/kartikbhartiya) • [LeetCode](https://leetcode.com/kartikbhartiya)
