# 🪨 Rock Paper Scissors Game (C++)

---

## 🎓 About the Project  
This is a **console-based C++ game** inspired by the classic **Rock–Paper–Scissors** challenge.  
The player competes against the computer, which makes random choices each round.  
At the end of all rounds, the game shows the full statistics — including total wins, draws, and the final winner.

---

## 🎮 Gameplay Rules  
The rules follow the traditional logic:  
- 🪨 **Rock beats Scissors**  
- ✂️ **Scissors beats Paper**  
- 📄 **Paper beats Rock**

---

## 🧩 Features  
✅ Play multiple rounds (1–10 per game)  
🤖 Computer generates random moves  
🎨 Color-coded round results for clarity  
📊 Displays a summary at the end  
🔁 Option to play again without restarting  
🖥️ Works perfectly in any terminal or IDE console  

---

## 🧠 Code Explanation  

### **1. Enums**
Enums are used to represent the player's and computer’s choices clearly and to track winners:
```cpp
enum enChoice { Rock = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };
```

### **2. Structs**
Two main structures are used to organize data efficiently:
```cpp
struct stRoundInfo {
    short roundNumber;
    enChoice playerChoice;
    enChoice computerChoice;
    enWinner roundWinner;
    string roundWinnerName;
};

struct stGameInfo {
    short numberOfRounds;
    short player1WonTimes;
    short computerWonTimes;
    short drawTimes;
    enWinner finalWinner;
    string finalWinnerName;
};
```
- **stRoundInfo** → stores each round’s choices and winner.  
- **stGameInfo** → stores game summary statistics.

### **3. Helper Functions**
Functions that handle input, output, and logic cleanly:  
- `readPositiveNumber()` → Reads and validates number of rounds.  
- `getRandomNumber()` → Generates random computer choices.  
- `convertChoiceToString()` → Converts enum values to readable text.  
- `convertWinnerToString()` → Prints readable winner names.

### **4. Game Logic**
Handles how rounds are played and winners determined:  
- `getRoundWinner()` → Decides the winner of each round.  
- `playGame()` → Manages all rounds and updates counters.  
- `getFinalWinner()` → Determines who won overall (player, computer, or draw).

### **5. Display & Visuals**
Adds interactivity and visual feedback in the console:  
- `displayRoundInfo()` → Shows the round summary.  
- `displayGameResult()` → Shows the final game statistics.  
- `changeDisplayColor()` → Changes console colors (green/red/yellow).  
- `displayGameOverScreen()` → Prints a “Game Over” banner.

### **6. Main Function**
The main entry point of the program:
```cpp
int main() {
    srand((unsigned)time(NULL)); // Initialize random seed
    startGame();                 // Begin the main game loop
    return 0;
}
```

---

## 🧑‍💻 How to Run the Project  

### 🔹 Option 1 — Using Visual Studio  
1. Open Visual Studio.  
2. Create a new C++ Console Application project.  
3. Replace the default code with `main.cpp` content.  
4. Build and run the project (`Ctrl + F5`).  

### 🔹 Option 2 — Using Command Line  
1. Save the file as `main.cpp`.  
2. Open terminal in the same folder.  
3. Run the following commands:  
```bash
g++ main.cpp -o Game.exe
./Game.exe
```

---

## 📊 Example Output  
```
Round [1] Begins:

Your Choice: [1]: Rock, [2]: Paper, [3]: Scissors ? 1
Player 1 Choice    : Rock
Computer Choice    : Scissor
Round Winner       : [Player 1]
______________________________

--- Game Over ---
Player 1 Won Times : 2
Computer Won Times : 1
Draw Times         : 0
Final Winner       : [Player 1]
```

---

## 📂 Project Structure  
```
RockPaperScissors/
├── main.cpp
└── README.md
```

---

## 🚀 Future Improvements  
✨ Add Player vs Player mode  
📁 Store match history in a text file  
🏆 Add a scoreboard that persists between games  
🖼️ Create a GUI version using SFML or Qt  

---

## 🧑‍🎓 Author  
**Hossam Ahmed Ragab**  
🎓 4th-Year Student – Faculty of Computers and Information, El Shorouk Academy  
🧭 Following Programming Advices Roadmap by **Mohammed Abo Hadhoud**  

---

## 📜 License  
This project is open-source and free to use for educational purposes.
