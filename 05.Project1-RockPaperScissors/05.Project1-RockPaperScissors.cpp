#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enChoice { Rock = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo {
    short roundNumber;
    enChoice playerChoice;
    enChoice computerChoice;
    enWinner roundWinner;
    string roundWinnerName = "";
};

struct stGameInfo {
    short numberOfRounds = 0;
    short player1WonTimes = 0;
    short computerWonTimes = 0;
    short drawTimes = 0;
    enWinner finalWinner;
    string finalWinnerName = "";
};

bool isNumberInRange(int number, int from, int to) {
    return number >= from && number <= to;
}

int readPositiveNumber(string msg, int from, int to) {
    int number = 0;
    do {
        cout << msg << " ";
        cin >> number;
    } while (!isNumberInRange(number, from, to));
    return number;
}

int getRandomNumber(int from, int to) {
    int randomNumber = rand() % (to - from + 1) + from;
    return randomNumber;
}

enChoice readPlayerChoice() {
    int number = 0;
    do {
        cout << "Your Choice: [1] : Rock, [2]: Paper, [3] : Scissors ? ";
        cin >> number;
    } while (!isNumberInRange(number, 1, 3));
    return (enChoice)number;
}

enChoice getComputerChoice() {
    return (enChoice)getRandomNumber(1, 3);
}

string convertChoiceToString(enChoice choice) {
    switch (choice) {
    case enChoice::Rock:
        return "Rock";
    case enChoice::Paper:
        return "Paper";
    case enChoice::Scissor:
        return "Scissor";
    default:
        return "UnKnown";
    }
}

string convertWinnerToString(enWinner winner) {
    switch (winner) {
        case enWinner::Player1:
            return "[Player 1]";
            break;
        case enWinner::Computer:
            return "[Computer]";
            break;
        case enWinner::Draw:
            return "[No Winner]";
            break;
        default:
            return "UnKnown";
    }
}

enWinner getRoundWinner(stRoundInfo roundInfo) {
    if (roundInfo.playerChoice == roundInfo.computerChoice)
        return enWinner::Draw;

    switch (roundInfo.playerChoice) {
    case enChoice::Rock:
        if (roundInfo.computerChoice == enChoice::Scissor)
            return enWinner::Player1;
        break;
    case enChoice::Paper:
        if (roundInfo.computerChoice == enChoice::Rock)
            return enWinner::Player1;
        break;
    case enChoice::Scissor:
        if (roundInfo.computerChoice == enChoice::Paper)
            return enWinner::Player1;
        break;
    }

    return enWinner::Computer;
}

void displayRoundInfo(stRoundInfo roundInfo) {
    cout << endl;
    cout << "__________ Round [" << roundInfo.roundNumber << "]__________\n" << endl;
    cout << "Player 1 Choice    : " << convertChoiceToString(roundInfo.playerChoice) << endl;
    cout << "Computer Choice    : " << convertChoiceToString(roundInfo.computerChoice) << endl;
    cout << "Round Winner       : " << roundInfo.roundWinnerName << endl;
    cout << "______________________________" << endl;
}

enWinner getFinalWinner(stGameInfo gameInfo) {
    if (gameInfo.player1WonTimes == gameInfo.computerWonTimes)
        return enWinner::Draw;
    else if (gameInfo.player1WonTimes > gameInfo.computerWonTimes)
        return enWinner::Player1;
    else
        return enWinner::Computer;
}

stGameInfo getGameInfo(int playerWonsTimes, int computerWonsTimes, int drawTimes, int numberOfRounds) {
    stGameInfo gameInfo;
    gameInfo.player1WonTimes = playerWonsTimes;
    gameInfo.computerWonTimes = computerWonsTimes;
    gameInfo.drawTimes = drawTimes;
    gameInfo.numberOfRounds = numberOfRounds;
    gameInfo.finalWinner = getFinalWinner(gameInfo);
    gameInfo.finalWinnerName = convertWinnerToString(gameInfo.finalWinner);

    return gameInfo;
}

string printTabs(short numberOfTabs) {
    string tab = "";
    for (int i = 1; i <= numberOfTabs; i++) {
        tab += "    ";
    }
    return tab;
}

void displayGameResult(stGameInfo gameInfo) {
    cout << endl;
    cout << printTabs(2) << "_______________ [Game Result ] ___________________" << endl << endl;
    cout << printTabs(2)  << "Game Rounds           : " << gameInfo.numberOfRounds << endl;
    cout << printTabs(2)  << "Player 1 Won Times    : " << gameInfo.player1WonTimes << endl;
    cout << printTabs(2)  << "Computer Won Times    : " << gameInfo.computerWonTimes << endl;
    cout << printTabs(2)  << "Draw Times            : " << gameInfo.drawTimes << endl;
    cout << printTabs(2)  << "Final Winner          : " << gameInfo.finalWinnerName << endl;
    cout << printTabs(2)  << "__________________________________________________" << endl;
}

stGameInfo playGame(int numberOfRounds) {

    stRoundInfo roundInfo;
    short player1WonTimes = 0, computerWonTimes = 0, drawTimes = 0;
    for (int i = 1; i <= numberOfRounds; i++) {

        cout << "\nRound [" << i << "] Begins : \n" << endl;
        roundInfo.roundNumber = i;
        roundInfo.playerChoice = readPlayerChoice();
        roundInfo.computerChoice = getComputerChoice();
        roundInfo.roundWinner = getRoundWinner(roundInfo);
        roundInfo.roundWinnerName = convertWinnerToString(roundInfo.roundWinner);


        displayRoundInfo(roundInfo);

        if (roundInfo.roundWinner == enWinner::Player1) {
            player1WonTimes++;
        }
        else if (roundInfo.roundWinner == enWinner::Computer) {
            computerWonTimes++;
        }
        else {
            drawTimes++;
        }

    }


    return getGameInfo(player1WonTimes, computerWonTimes, drawTimes, numberOfRounds);

}

void resetScreen() {
    system("cls");
}

void displayGameOverScreen() {
    cout << printTabs(2) << "\n";
    cout << printTabs(2) << "--------------------------------------------------\n\n";
    cout << printTabs(2) << "               +++  G a m e  O v e r  +++         \n\n";
    cout << printTabs(2) << "--------------------------------------------------\n";
}

void startGame() {

    char playAgain = 'Y';

    do {

        resetScreen();
        stGameInfo gameInfo;
        gameInfo = playGame(readPositiveNumber("How many Rounds 1 to 10 ?", 1, 10));
        displayGameOverScreen();
        displayGameResult(gameInfo);

        cout << endl;
        cout << printTabs(2) << "Do you want to play again? Y/N? ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');
}




int main()
{
    srand((unsigned)time(NULL));

    startGame();

    return 0;
}

