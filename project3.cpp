#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
// #include <windows.h>
#include <string>
using namespace std;
void PrintPosition(int position, char turn, bool &flag, char positionArray[], bool &validInput, bool computerValid);
void changeTurn(char &turn);
void checkWin(bool &flag, char positionArray[]);
void checkDraw(bool &flag, bool &drawGame, char positionArray[]);
void StopToWin(int &randomNumber, char positionArray[]);
void TryToWin(int &randomNumber, char positionArray[]);
void playgame(void);
struct user
{
    string name;
    string id;
    string password;
};
void showHistory(user user1)
{
    int fullHistory = 345;
start:
    string line;
    int i = 0;
    string checkID;
    bool found = false;
    ifstream history("Game4.txt");
    int num1 = 0;
    int num2 = 0;
    int user = 0;
    int computer = 0;
    int totalGame = 0;
    int totalDraw = 0;
    int print = 0;
    while (getline(history, line))
    {
        num1 = 0;
        num2 = 0;
        int pos1 = 0;
        // cout << line << endl;
        int pos = line.find(" ");
        pos1 = line.find("$");
        int pos3 = line.find("*");

        // cout<<pos1<<endl;
        // cout<<endl<<"*"<<pos3<<endl;
        string checkID = line.substr(0, pos);
        string str = line.substr(pos1 + 1, pos3);
        int subpos = str.find("*");
        str.erase(subpos);
        // cout<<subpos<<endl;
        for (int i = 0; i < str.length(); i++)
        {
            char str1 = str[i];
            num1 = static_cast<int>(str1);
            num1 -= 48;
            num2 = (num2 * 10) + num1;
        }
        // cout<<num2<<endl;
        // cout<<str<<endl;
        line.erase(pos3);
        line.erase(pos1, 1);
        if (print == 0)
        {
            line.erase(0, pos + 1);
        }

        if (checkID == user1.id || print != 0)
        {
            if (fullHistory == 1)
            {
                cout << line << endl;
            }
            if (print == 0)
            {
                totalGame += num2;
            }
            if (print == 1)
            {
                user += num2;
            }
            else if (print == 2)
            {
                computer += num2;
            }
            else if (print == 3)
            {
                totalDraw += num2;
            }
            print++;
            if (print == 4)
            {
                cout << endl;
                print = 0;
            }
            found = true;
        }
    }
    if (found && fullHistory != 1)
    {
        cout << "Total number of games played by " << user1.name << " are " << totalGame << endl;
        cout << "Total number of Games Win by the computer is " << computer << endl;
        cout << "Total number of Games Win by the " << user1.name << " is " << user << endl;
        cout << "Total number of draw games are " << totalDraw << endl;
        cout << "\n\nDo you want to see your full history \n";
        cout << "\"1\" For Yes\n";
        cout << "\"2\" For No\n";
        cin >> fullHistory;
        if (fullHistory == 1)
        {
            goto start;
        }
    }
    if (!found)
    {
        cout << "NO HISTORY FOUND\n";
    }
    // cout << i;
}

int main()
{
    cout << endl
         << endl
         << endl;

    cout << "    GGGGGGGGGG            A         M                 M E E E E E      S S S S   IIII  N         N       CCCCCCCC        ++           ++" << endl;
    cout << "   GG                   A  A        M   M           M M E            S        S   II   N N       N     CC                ++           ++" << endl;
    cout << "   GG                  A     A      M     M       M   M E            S            II   N  N      N     CC                ++           ++" << endl;
    cout << "   GG                 A       A     M       M   M     M E E E E E    S S S        II   N   N     N     CC           ++++++++++++  +++++++++++" << endl;
    cout << "   GG       GGGG     A A A A A A    M         M       M E                 S       II   N    N    N     CC           ++++++++++++  +++++++++++" << endl;
    cout << "   GG          G    A           A   M                 M E                   S     II   N     N   N     CC                ++           ++" << endl;
    cout << "    GGGGGGGGGG G   A             A  M                 M E          S        S     II   N      N  N     CC                ++           ++" << endl;
    cout << "               G  A               A M                 M E E E E E    S S S S     IIII  N         N       CCCCCCCC        ++           ++" << endl;
    cout << "               G                                                                                                            " << endl
         << endl
         << endl;
    cout << "\t\t\t\t PRESS ENTER TO CONTINUE !!\n";
    getchar();
    system("CLS");

start:
    system("CLS");
    int game;
    cout << "\n\n\n\n\t\t\t\t\t\t\t\tGMAES IN C++\n\n";
    cout << "\t\t\t\t\tEnter \"1\" for TIC TAC TOE Game \n";
    cout << "\t\t\t\t\tEnter \"2\" for HEADS TAILS Game \n";
    cout << "\t\t\t\t\tEnter \"3\" for QUICKZ Game \n";
    cout << "\t\t\t\t\tEnter \"4\" for STONE PAPER SCISSOR Game \n";

    cin >> game;
    bool gamePlay = true;
    if (game == 1)
    {
        int Playyer;
        cout << "For Single player, press \"1\"\n ";
        cout << "For Double player, press \"2\"\n ";
        cin >> Playyer;
        int end = 0;
        while (true)
        {
            cout << "How much round do want play \n";
            int round;
            cin >> round;
            int x = 0;
            int zero = 0;
            while (true)
            {
                char positionArray[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
                int position;
                bool flag = false;
                char turn = 'X';
                bool validInput = true;
                bool drawGame = false;
                bool computerValid = false;
                /* code */
                system("CLS");
                if (Playyer == 1)
                    cout << "Turn \"0\" win rounds is :       " << zero << endl;
                if (Playyer == 2)
                    cout << "Turn \"Computer\" win rounds is :      " << zero << endl;
                cout << "Turn \"x\" win rounds is :       " << x << endl;
                if (end == round)
                {
                    break;
                }
                while (true)
                {
                    cout << "\t\t\t\t\t     TIC TAC TOE \n";
                    cout << "\t\t\t\t\t    -------------";
                    cout << "\n";

                    if (!validInput)
                        cout << "\t\t\t\t\tINPUT IS INVALID OF \"" << turn << "\"" << endl;
                    cout << "\n\n";
                    cout << "\t\t\t\t\t   " << positionArray[1] << " |   " << positionArray[2] << " |     " << positionArray[3] << " " << endl;
                    cout << "\t\t\t\t\t_____|_____|_______" << endl;
                    cout << "\t\t\t\t\t   " << positionArray[4] << " |   " << positionArray[5] << " |     " << positionArray[6] << " " << endl;
                    cout << "\t\t\t\t\t_____|_____|_______" << endl;
                    cout << "\t\t\t\t\t   " << positionArray[7] << " |   " << positionArray[8] << " |     " << positionArray[9] << " " << endl;
                    cout << "\t\t\t\t\t     |     |      " << endl;
                    if (flag)
                        break;
                    cout << "TRUN FOR     " << turn << endl;
                    cout << "Enter the position of number where you want set your turn :         ";
                    cin >> position;
                    PrintPosition(position, turn, flag, positionArray, validInput, computerValid);
                    checkWin(flag, positionArray);
                    checkDraw(flag, drawGame, positionArray);
                    if (Playyer == 1)
                        if (validInput)
                            changeTurn(turn);
                    if (!flag)
                    {
                        bool computerValid = true;
                        if (Playyer == 2 && validInput)
                        {
                            while (computerValid)
                            {
                                srand(time(0));
                                int randomNumber = 1 + rand() % 9;
                                changeTurn(turn);
                                StopToWin(randomNumber, positionArray);
                                TryToWin(randomNumber, positionArray);
                                PrintPosition(randomNumber, turn, flag, positionArray, validInput, computerValid);
                                checkWin(flag, positionArray);
                                checkDraw(flag, drawGame, positionArray);
                                if (!flag)
                                    changeTurn(turn);
                                // sleep(1);
                                if (validInput || flag)
                                {
                                    computerValid = false;
                                }
                            }
                        }
                    }
                }
                if (Playyer == 1)
                {
                    if (turn == 'X')
                        turn = '0';
                    else if (turn == '0')
                        turn = 'X';
                }
                if (drawGame)
                {
                    cout << "Match is Draw\n";
                }
                else
                {
                    cout << "Winner is " << turn << endl;
                }
                if (turn == 'X' && !drawGame)
                {
                    x++;
                }
                else if (turn == '0' && !drawGame)
                {
                    zero++;
                }

                end++;
            }
            cout << "DO YOU WANT TO PLAY AGAIN?\n";
            cout << "If you want to play Enter, press \"1\"\n";
            cout << "If you not want to play Enter, press \"2\"\n";
            int play;
            cin >> play;
            if (play == 2)
            {
                break;
                goto start;
            }
        }
    }

    if (game == 2)
    {
        while (gamePlay)
        {
            string bat;
            string chaser;
            int target = 0;
            int totalscore1 = 0;
            int user;
            bool computerScore = false;
            srand(time(0));
            int randomNumber1;
            string tossArr[10] = {"tails", "heads", "heads", "tails", "tails", "heads", "tails", "heads", "heads", "tails"};
            int randomIndex = rand() % 9;
            cout << randomIndex << endl;
            string toss;
            string inningArr[10] = {"BOWL", "BAT", "BOWL", "BOWL", "BAT", "BAT", "BOWL", "BAT", "BOWL", "BAT"};
            cout << "HEAD OR TAILS: \n";
            cin >> toss;
            char firstChar = tolower(toss[0]);
            if (firstChar == 'h')
            {
                toss = "heads";
            }
            else if (firstChar == 't')
            {
                toss = "tails";
            }
            if (toss == tossArr[randomIndex])
            {
                cout << "\t\t\t\t\t\tYou won the toss \n";
                cout << "\t\t\t\t\t\tSelect \t:\n";
                cout << "\t\t\t\t\t\t\t BAT\n";
                cout << "\t\t\t\t\t\tFor bat enter 1\n";
                cout << "\t\t\t\t\t\t\t BOWL\n";
                cout << "\t\t\t\t\t\tFor bowl enter 2\n";
                int userchoice;
                cin >> userchoice;
                cout << "\t\t\t\tYOU DECIDED TO " << inningArr[userchoice] << " FIRST.\n ";
                if (inningArr[userchoice] == "BAT")
                {
                    bat = "user";
                    chaser = "computer";
                }
                else
                {
                    bat = "Computer";
                    chaser = "user";
                    computerScore = true;
                }
            }
            else
            {
                cout << "\t\t\t\t\t\tCOMPUTER  won the toss \n";
                cout << "\t\t\t\\t\t\t\t\tDECIDED TO " << inningArr[randomIndex] << " FIRST.\n";
                if (inningArr[randomIndex] == "BAT")
                {
                    bat = "computer";
                    chaser = "user";
                    computerScore = true;
                }
                else
                {
                    bat = "user";
                    chaser = "computer";
                }
            }
            cout << bat << endl;
            while (true)
            {
                do
                {
                    cout << "Enter the number :     ";
                    cin >> user;
                    randomNumber1 = 1 + rand() % 6;
                    if (user > 6)
                    {
                        cout << "Invalid input\n";
                    }
                } while (user > 6);
                if (user != randomNumber1)
                {
                    cout << randomNumber1 << endl;
                    cout << "\t\t USER \t\t = \t " << user << endl;
                    cout << "\t\t COMPUTER \t = \t " << randomNumber1 << endl;
                    if (computerScore)
                    {
                        target += randomNumber1;
                    }
                    else
                        target += user;
                }
                else
                {
                    cout << "\t\t USER \t\t = \t " << user << endl;
                    cout << "\t\t COMPUTER \t = \t " << randomNumber1 << endl;
                    cout << "   OUT  " << endl;
                    break;
                }
            }
            cout << "The scores of " << bat << " is " << target << endl;
            target += 1;
            cout << "Target is " << target << endl;

            while (true)
            {
                do
                {
                    cout << "Enter the number :     ";
                    cin >> user;
                    randomNumber1 = 1 + rand() % 6;
                    if (user > 6)
                    {
                        cout << "Invalid input\n";
                    }
                } while (user > 6);
                if (user != randomNumber1)
                {
                    cout << "\t\t USER \t\t = \t " << user << endl;
                    cout << "\t\t COMPUTER \t = \t " << randomNumber1 << endl;
                    if (computerScore)
                    {
                        totalscore1 += user;
                    }
                    else
                        totalscore1 += randomNumber1;
                }
                else
                {
                    cout << "   OUT  \n";
                    cout << "\t\t USER \t\t = \t " << user << endl;
                    cout << "\t\t COMPUTER \t = \t " << randomNumber1 << endl;
                    break;
                }
                if (target <= totalscore1)
                {
                    break;
                }
            }
            cout << bat << " :      " << target - 1 << endl;
            cout << chaser << " :     " << totalscore1 << endl;
            if (target < totalscore1)
            {
                cout << "Winner is  :     " << chaser << endl;
            }
            else if (target - 1 == totalscore1)
                cout << "Match is Draw\n";
            else
            {
                cout << "Winner is   :    " << bat << endl;
            }
            cout << "DO YOU WANT TO CONTINUE THE GAME \n\"1\".  FOR YES.\n \"2\" FOR NO.";
            int gamePlayNum;
            cin >> gamePlayNum;
            if (gamePlayNum == 2)
            {
                gamePlay = false;
                goto start;
            }
        }
    }
    if (game == 3)
    {

        cout << "\n\n\t\t\t\tQUICKZ GAME \n\n";
        playgame();
        goto start;
    }
    if (game == 4)
    {
        int userCheck;
        int userCheck1;
        bool loginFlag = false;
        bool signUpFlag = false;
        cout << "Are You New To game\n";
        cout << "\"1\" FOR YES \n";
        cout << "\"2\" FOR NO \n";
        cin >> userCheck1;
        if (userCheck1 == 2)
        {
            loginFlag = true;
        }
    strat:
    bool signUp = false;
        if (userCheck1 == 1 || signUp)
        {
            cout << "Do you want to sign up\n";
            cout << "\"1\" FOR YES \n";
            cout << "\"2\" FOR Guest mode \n";
            cin >> userCheck;
            if (userCheck == 1)
            {
                signUpFlag = true;
            }
            if (userCheck == 2)
            {
                cout << "In Guest mode there is history facility\n\tThank You!\n";
            }
        }
        int draw = 0;
        int userScore = 0;
        int computerScorce = 0;
        ofstream outFile1;
        ifstream inFile;
        user user1;
        if (loginFlag || signUpFlag)
        {
            cout << "Enter your name :   ";

            cin >> user1.name;
            cout << "Enter your ID :   ";
            cin >> user1.id;

            outFile1.open("Names.txt", ios ::app);
            inFile.open("Names.txt");

            if (!inFile)
            {
                cout << "File is not opening\n";
            }
            if (signUpFlag)
            {
                string signUpLine;
                string signUpIdCheck;
                int i = 0;
                while (getline(inFile, signUpLine))
                {
                    inFile >> signUpIdCheck;
                    if (signUpIdCheck == user1.id)
                    {
                        cout << "This ID is already under use\nEnter another id";

                        string str[9];
                        for (i = 0; i < 9; i++)
                        {

                            srand(time(0));
                            int randomNumber = 12312 + rand() % 999999998876;
                            randomNumber += i + 32;
                            str[i] = user1.name + to_string(randomNumber);
                            // Sleep(220);
                        }
                        cout << "\nSugseted ids : \n";
                        for (int i = 0; i < 5; i++)
                        {
                            cout << i + 1 << ". " << str[i] << endl;
                        }
                        cout << "Do you want to pick any id.If yes then enter the index of idwhich display on your screen\n";

                        cout << "\"-1\" For NO\n";
                        int pickId;
                        cin >> pickId;
                        for (int i = 0; i < 5; i++)
                        {
                            if (pickId == i + 1)
                            {
                                user1.id = str[i];
                            }
                        }
                        if (pickId)
                        {
                            while (user1.id == signUpIdCheck)
                            {
                                cin >> user1.id;
                                cout << "enter the id\n";
                            }
                        }
                    }
                }
            }
            if(loginFlag)
            {
                string line;
                string loginId;
                while (getline(inFile,line))
                {
                    inFile >> loginId;
                    while(loginId != user1.id)
                    {
                        cout<<"Invalid Id \n";
                        cin>>user1.id;
                        cout<<"Do you want to sign up\n";
                        cout<<"\"1\" FOR YES\n";
                        cout<<"\"2\" FOR No\n";
                        int num;
                        cin>>num;
                        if(num==2){
                        goto strat;
                        signUp = true;
                        }
                    }
                }
                
            }
            cout << "Enter the Password  " << endl;
            cin >> user1.password;
        }
        string wordID;
        string wordPassword;
        bool flag = true;
        int history1;
        string line1;
        string wordName;
        if (loginFlag)
        {
            while (getline(inFile, line1))
            {
                // inFile>>wordID>>wordPassword;
                // cout << line1 << endl;
                inFile >> wordID;
                inFile >> wordPassword;
                inFile >> wordName;
                bool doubleCheck = true;
                if (user1.id == wordID && doubleCheck && user1.password != wordPassword)
                {
                    if (wordPassword != user1.password)
                        while (!(user1.password == wordPassword))
                        {
                            cout << "Incorrect Password\n";
                            cout << "Do you want to sign up\n";
                            cout << "\"1\" FOR YES \n";
                            cout << "\"2\" FOR NO \n";
                            int signUp1;
                            cin >> signUp1;
                            if (signUp1 == 1){
                                goto start;
                                signUp = true;
                                }
                            cout << "Enter the correct password\n";
                            cin >> user1.password;
                        }

                    if (user1.password == wordPassword)
                    {
                        flag = false;
                        doubleCheck = false;
                        user1.name = wordName;
                        cout << "You Have sccessfully Loged in your accounct.\n";
                        cout << "Do you wnat check your history \n";
                        cin >> history1;
                        if (history1 == 1)
                            showHistory(user1);
                        else
                            cout << "Thank You\n";
                        break;
                    }
                }
                else if (user1.id == wordID && user1.password == wordPassword)
                {
                    flag = false;
                    doubleCheck = false;
                    cout << "You Have sccessfully Loged in your accounct.\n";
                    user1.name = wordName;
                    cout << "Do you wnat check your history \n";
                    cin >> history1;
                    if (history1 == 1)
                        showHistory(user1);
                    break;
                }
            }
        }
        if (flag)
        {
            outFile1 << user1.id << " " << user1.password << " " << user1.name << endl;
        }
        // outFile1.close();
        ofstream outFile("Game4.txt", ios ::app);
        ifstream history("Game4.txt");
        int userRounds;
        int totalRounds = 0;
        while (true)
        {
            cout << "Enter the round you want play \n";
            cin >> userRounds;

            for (int i = 0; i < userRounds; i++)
            {
                srand(time(0));
                int randomNumber = rand() % 3;
                // cout<<randomNumber;
                string StoneGameArr[3] = {"stone", "paper", "scissor"};
                string userchoice;
                cout << "Enter your choice :\n";
                cin >> userchoice;
                char secondChar = tolower(userchoice[1]);
                if (secondChar == 't')
                    userchoice = "stone";
                else if (secondChar == 'a')
                    userchoice = "paper";
                else if (secondChar == 'c')
                    userchoice = "scissor";
                else
                    cout << "Invalid Input\n";
                if (userchoice == StoneGameArr[randomNumber])
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Match is draw\n";
                    draw++;
                }
                else if (userchoice == "stone" && StoneGameArr[randomNumber] == "scissor")
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Winner is user\n";
                    userScore++;
                }
                else if (userchoice == "scissor" && StoneGameArr[randomNumber] == "stone")
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Winner is computer\n";
                    computerScorce++;
                }
                else if (userchoice == "paper" && StoneGameArr[randomNumber] == "scissor")
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Winner is computer\n";
                    computerScorce++;
                }
                else if (userchoice == "scissor" && StoneGameArr[randomNumber] == "paper")
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Winner is user\n";
                    userScore++;
                }
                else if (userchoice == "stone" && StoneGameArr[randomNumber] == "paper")
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Winner is computer\n";
                    computerScorce++;
                }
                else if (userchoice == "paper" && StoneGameArr[randomNumber] == "stone")
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Winner is user\n";
                    userScore++;
                }
            }
            // outFile <<"The of the user is "<<user1.name<<endl;

            system("CLS");
            cout << "Do you play again\n ";
            cout << "\"1\" for PLAY " << endl;
            cout << "\"2\" for QUIT " << endl;
            totalRounds += userRounds;
            int endGame;
            cin >> endGame;
            if (endGame == 2)
            {
                break;
                goto start;
            }
        }

        cout << "Scorese of Computer :       " << computerScorce << endl;
        cout << "Scorese of User :       " << userScore << endl;
        if (loginFlag || signUpFlag)
        {
            cout << "Do ypu want see your history\n";
            cin >> history1;
            outFile << user1.id << " ";
            outFile << "Number of rounds which is played $" << totalRounds << "*" << endl;
            outFile << "Number rounds " << user1.name << " wins is $" << userScore << "*" << endl;
            outFile << "Number rounds computer wins is $" << computerScorce << "*" << endl;
            outFile << "Number of games Draw is $" << draw << "*" << endl;
            if (history1 == 1)
            {
                showHistory(user1);
            }
        }
    }
}
void changeTurn(char &turn)
{
    if (turn == 'X')
        turn = '0';
    else
        turn = 'X';
}
void PrintPosition(int position, char turn, bool &flag, char positionArray[], bool &validInput, bool computerValid)
{
    switch (position)
    {
    case 1:
        if (positionArray[1] != 'X' && positionArray[1] != '0')
        {
            validInput = true;
            positionArray[1] = turn;
        }
        else
        {
            validInput = false;
        }
        break;
    case 2:
        if (positionArray[2] != 'X' && positionArray[2] != '0')
        {
            positionArray[2] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    case 3:
        if (positionArray[3] != 'X' && positionArray[3] != '0')
        {
            positionArray[3] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    case 4:
        if (positionArray[4] != 'X' && positionArray[4] != '0')
        {
            positionArray[4] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    case 5:
        if (positionArray[5] != 'X' && positionArray[5] != '0')
        {
            positionArray[5] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    case 6:
        if (positionArray[6] != 'X' && positionArray[6] != '0')
        {
            positionArray[6] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    case 7:
        if (positionArray[7] != 'X' && positionArray[7] != '0')
        {
            positionArray[7] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    case 8:
        if (positionArray[8] != 'X' && positionArray[8] != '0')
        {
            positionArray[8] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    case 9:
        if (positionArray[9] != 'X' && positionArray[9] != '0')
        {
            positionArray[9] = turn;
            validInput = true;
        }
        else
        {
            validInput = false;
        }
        break;
    default:
        cout << "Invalid input \n";
        validInput = false;
        break;
    }
}
void checkWin(bool &flag, char positionArray[])
{
    if ((positionArray[1] == positionArray[2]) && (positionArray[2] == positionArray[3]))
    {
        flag = true;
    }
    if ((positionArray[4] == positionArray[5]) && (positionArray[5] == positionArray[6]))
    {
        flag = true;
    }
    if ((positionArray[7] == positionArray[8]) && (positionArray[8] == positionArray[9]))
    {
        flag = true;
    }
    if ((positionArray[1] == positionArray[5]) && (positionArray[5] == positionArray[9]))
    {
        flag = true;
    }
    if ((positionArray[3] == positionArray[5]) && (positionArray[5] == positionArray[7]))
    {
        flag = true;
    }
    if ((positionArray[2] == positionArray[5]) && (positionArray[5] == positionArray[8]))
    {
        flag = true;
    }
    if ((positionArray[1] == positionArray[4]) && (positionArray[4] == positionArray[7]))
    {
        flag = true;
    }
    if ((positionArray[1] == positionArray[4]) && (positionArray[4] == positionArray[7]))
    {
        flag = true;
    }
    if ((positionArray[2] == positionArray[5]) && (positionArray[5] == positionArray[8]))
    {
        flag = true;
    }
    if ((positionArray[3] == positionArray[6]) && (positionArray[6] == positionArray[9]))
    {
        flag = true;
    }
}
void checkDraw(bool &flag, bool &drawGame, char positionArray[])
{
    if ((positionArray[1] == 'X' || positionArray[1] == '0') && (positionArray[2] == 'X' || positionArray[2] == '0') && (positionArray[3] == 'X' || positionArray[3] == '0') && (positionArray[3] == 'X' || positionArray[3] == '0') && (positionArray[4] == 'X' || positionArray[4] == '0') && (positionArray[5] == 'X' || positionArray[5] == '0') && (positionArray[6] == 'X' || positionArray[6] == '0') && (positionArray[7] == 'X' || positionArray[7] == '0') && (positionArray[8] == 'X' || positionArray[8] == '0') && (positionArray[9] == 'X' || positionArray[9] == '0') && (flag == false))
    {
        drawGame = true;
        flag = true;
    }
}
void StopToWin(int &randomNumber, char positionArray[])
{
    if (((positionArray[1] == 'X') && (positionArray[2] == 'X')) && (positionArray[3] != 'X' && positionArray[3] != '0'))
    {
        randomNumber = 3;
    }
    if ((positionArray[3] == 'X') && (positionArray[2] == 'X') && (positionArray[1] != 'X' && positionArray[1] != '0'))
    {
        randomNumber = 1;
    }
    if ((positionArray[1] == 'X') && (positionArray[3] == 'X') && (positionArray[2] != 'X' && positionArray[2] != '0'))
    {
        randomNumber = 2;
    }
    if ((positionArray[4] == 'X') && (positionArray[5] == 'X') && (positionArray[6] != 'X' && positionArray[6] != '0'))
    {
        randomNumber = 6;
    }
    if ((positionArray[4] == 'X') && (positionArray[6] == 'X') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
    if ((positionArray[5] == 'X') && (positionArray[6] == 'X') && (positionArray[4] != 'X' && positionArray[4] != '0'))
    {
        randomNumber = 4;
    }
    if ((positionArray[7] == 'X') && (positionArray[8] == 'X') && (positionArray[9] != 'X' && positionArray[9] != '0'))
    {
        randomNumber = 9;
    }
    if ((positionArray[7] == 'X') && (positionArray[9] == 'X') && (positionArray[8] != 'X' && positionArray[8] != '0'))
    {
        randomNumber = 8;
    }
    if ((positionArray[8] == 'X') && (positionArray[9] == 'X') && (positionArray[7] != 'X' && positionArray[7] != '0'))
    {
        randomNumber = 7;
    }
    if ((positionArray[1] == 'X') && (positionArray[7] == 'X') && (positionArray[4] != 'X' && positionArray[4] != '0'))
    {
        randomNumber = 4;
    }
    if ((positionArray[4] == 'X') && (positionArray[7] == 'X') && (positionArray[1] != 'X' && positionArray[1] != '0'))
    {
        randomNumber = 1;
    }
    if ((positionArray[1] == 'X') && (positionArray[7] == 'X') && (positionArray[4] != 'X' && positionArray[4] != '0'))
    {
        randomNumber = 4;
    }
    if ((positionArray[2] == 'X') && (positionArray[8] == 'X') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
    if ((positionArray[5] == 'X') && (positionArray[8] == 'X') && (positionArray[2] != 'X' && positionArray[2] != '0'))
    {
        randomNumber = 2;
    }
    if ((positionArray[2] == 'X') && (positionArray[5] == 'X') && (positionArray[8] != 'X' && positionArray[8] != '0'))
    {
        randomNumber = 8;
    }
    if ((positionArray[3] == 'X') && (positionArray[9] == 'X') && (positionArray[6] != 'X' && positionArray[6] != '0'))
    {
        randomNumber = 6;
    }
    if ((positionArray[6] == 'X') && (positionArray[9] == 'X') && (positionArray[3] != 'X' && positionArray[3] != '0'))
    {
        randomNumber = 3;
    }
    if ((positionArray[3] == 'X') && (positionArray[6] == 'X') && (positionArray[9] != 'X' && positionArray[9] != '0'))
    {
        randomNumber = 9;
    }
    if ((positionArray[1] == 'X') && (positionArray[5] == 'X') && (positionArray[9] != 'X' && positionArray[9] != '0'))
    {
        randomNumber = 9;
    }
    if ((positionArray[1] == 'X') && (positionArray[9] == 'X') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
    if ((positionArray[5] == 'X') && (positionArray[9] == 'X') && (positionArray[1] != 'X' && positionArray[1] != '0'))
    {
        randomNumber = 1;
    }
    if ((positionArray[3] == 'X') && (positionArray[5] == 'X') && (positionArray[7] != 'X' && positionArray[7] != '0'))
    {
        randomNumber = 7;
    }
    if ((positionArray[5] == 'X') && (positionArray[7] == 'X') && (positionArray[3] != 'X' && positionArray[3] != '0'))
    {
        randomNumber = 3;
    }
    if ((positionArray[3] == 'X') && (positionArray[7] == 'X') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
}
void TryToWin(int &randomNumber, char positionArray[])

{
    if (((positionArray[1] == '0') && (positionArray[2] == '0')) && (positionArray[3] != 'X' && positionArray[3] != '0'))
    {
        randomNumber = 3;
    }
    if ((positionArray[3] == '0') && (positionArray[2] == '0') && (positionArray[1] != 'X' && positionArray[1] != '0'))
    {
        randomNumber = 1;
    }
    if ((positionArray[1] == '0') && (positionArray[3] == '0') && (positionArray[2] != 'X' && positionArray[2] != '0'))
    {
        randomNumber = 2;
    }
    if ((positionArray[4] == '0') && (positionArray[5] == '0') && (positionArray[6] != 'X' && positionArray[6] != '0'))
    {
        randomNumber = 6;
    }
    if ((positionArray[4] == '0') && (positionArray[6] == '0') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
    if ((positionArray[5] == '0') && (positionArray[6] == '0') && (positionArray[4] != 'X' && positionArray[4] != '0'))
    {
        randomNumber = 4;
    }
    if ((positionArray[7] == '0') && (positionArray[8] == '0') && (positionArray[9] != 'X' && positionArray[9] != '0'))
    {
        randomNumber = 9;
    }
    if ((positionArray[7] == '0') && (positionArray[9] == '0') && (positionArray[8] != 'X' && positionArray[8] != '0'))
    {
        randomNumber = 8;
    }
    if ((positionArray[8] == '0') && (positionArray[9] == '0') && (positionArray[7] != 'X' && positionArray[7] != '0'))
    {
        randomNumber = 7;
    }
    if ((positionArray[1] == '0') && (positionArray[7] == '0') && (positionArray[4] != 'X' && positionArray[4] != '0'))
    {
        randomNumber = 4;
    }
    if ((positionArray[4] == '0') && (positionArray[7] == '0') && (positionArray[1] != 'X' && positionArray[1] != '0'))
    {
        randomNumber = 1;
    }
    if ((positionArray[1] == '0') && (positionArray[7] == '0') && (positionArray[4] != 'X' && positionArray[4] != '0'))
    {
        randomNumber = 4;
    }
    if ((positionArray[2] == '0') && (positionArray[8] == '0') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
    if ((positionArray[5] == '0') && (positionArray[8] == '0') && (positionArray[2] != 'X' && positionArray[2] != '0'))
    {
        randomNumber = 2;
    }
    if ((positionArray[2] == '0') && (positionArray[5] == '0') && (positionArray[8] != 'X' && positionArray[8] != '0'))
    {
        randomNumber = 8;
    }
    if ((positionArray[3] == '0') && (positionArray[9] == '0') && (positionArray[6] != 'X' && positionArray[6] != '0'))
    {
        randomNumber = 6;
    }
    if ((positionArray[6] == '0') && (positionArray[9] == '0') && (positionArray[3] != 'X' && positionArray[3] != '0'))
    {
        randomNumber = 3;
    }
    if ((positionArray[3] == '0') && (positionArray[6] == '0') && (positionArray[9] != 'X' && positionArray[9] != '0'))
    {
        randomNumber = 9;
    }
    if ((positionArray[1] == '0') && (positionArray[5] == '0') && (positionArray[9] != 'X' && positionArray[9] != '0'))
    {
        randomNumber = 9;
    }
    if ((positionArray[1] == '0') && (positionArray[9] == '0') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
    if ((positionArray[5] == '0') && (positionArray[9] == '0') && (positionArray[1] != 'X' && positionArray[1] != '0'))
    {
        randomNumber = 1;
    }
    if ((positionArray[3] == '0') && (positionArray[5] == '0') && (positionArray[7] != 'X' && positionArray[7] != '0'))
    {
        randomNumber = 7;
    }
    if ((positionArray[5] == '0') && (positionArray[7] == '0') && (positionArray[3] != 'X' && positionArray[3] != '0'))
    {
        randomNumber = 3;
    }
    if ((positionArray[3] == '0') && (positionArray[7] == '0') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 5;
    }
}

void playgame(void)
{
    cout << "\n";
    cout << "\t\t\t\t\t** Welcome**" << endl;
    cout << "\t\t\t\t\t** We will play a game" << endl;
    cout << "\t\t\t\t\t** There is no negative marking*" << endl;
    cout << "\t\t\t\t\t*You have to answer the ten questions " << endl;
    cout << "\t\t\t\t\t*Press s to start the game*" << endl;
    cout << "\t\t\t\t\t*Select a),b),c),d) from the opyions*" << endl;
    char c;
    int score = 0;
    char option;
    cin >> c;
    if (c == 's' || c == 'S')
    {
        cout << "Q1 : What is the capital of pakistan? " << endl;
        cout << "a) Lahore" << endl;
        cout << "b) Karachi" << endl;
        cout << "c) Islamabad" << endl;
        cout << "d) Peshawar" << endl;
        cin >> option;
        if (option == 'c' || option == 'C')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q2 : What is the national bird of Pakistan?" << endl;
        cout << "a) Sparrow" << endl;
        cout << "b) Crow " << endl;
        cout << "c) Chukar " << endl;
        cout << "d) Columbidae " << endl;
        cin >> option;
        if (option == 'c' || option == 'C')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q3 : What is the national animal of Pakistan?" << endl;
        cout << "a) Lion" << endl;
        cout << "b) Markhor" << endl;
        cout << "c) Goat" << endl;
        cout << "d) Kangroo" << endl;
        cin >> option;
        if (option == 'b' || option == 'B')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q4 : What is the national flower of Pakistan?" << endl;
        cout << "a) Rose" << endl;
        cout << "b) Lily" << endl;
        cout << "c) Sunflower" << endl;
        cout << "d) Jasmine" << endl;
        cin >> option;
        if (option == 'd' || option == 'D')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q5 : Who was the first primeminister of Pakistan? " << endl;
        cout << "a) Quaid-e-Azam" << endl;
        cout << "b) Allama Iqbal" << endl;
        cout << "c) Liaqat Ali Khan" << endl;
        cout << "d) Chaudry Rahmat Ali" << endl;
        cin >> option;
        if (option == 'c' || option == 'C')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q6 : Who is the ceo of Amazon?" << endl;
        cout << "a) Billgates" << endl;
        cout << "b) Imran Khan" << endl;
        cout << "c) Jef Besos" << endl;
        cout << "d) Elon Musk" << endl;
        cin >> option;
        if (option == 'd' || option == 'D')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q7 : Who suggsted the word Pakistan for seperate homeland?" << endl;
        cout << "a) Quaid e Azam" << endl;
        cout << "b) Chaudry Rahmat Ali" << endl;
        cout << "c) Allam Iqbal" << endl;
        cout << "d) Liaqat Ali Khan" << endl;
        cin >> option;
        if (option == 'b' || option == 'B')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q8 : When Bangladesh  appeared as a seprate homeland from Pakistan?" << endl;
        cout << "a) 1971" << endl;
        cout << "b) 1970" << endl;
        cout << "c) 1969" << endl;
        cout << "d) 1960" << endl;
        cin >> option;
        if (option == 'a' || option == 'A')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q9 : When Pakistan won the cricket world cup in 1992?" << endl;
        cout << "a) 2006" << endl;
        cout << "b) 2009" << endl;
        cout << "c) 2012" << endl;
        cout << "d) 2004" << endl;
        cin >> option;
        if (option == 'a' || option == 'A')
            score = score + 1;
        else
            score = score + 0;

        cout << "Q10 : Which team win the t20  cricket worldcup 2019? " << endl;
        cout << "a) Pakistan" << endl;
        cout << "b) Australia" << endl;
        cout << "c) England" << endl;
        cout << "d) South Africa" << endl;
        cin >> option;
        if (option == 'c' || option == 'C')
            score = score + 1;
        else
            score = score + 0;
    }
    else
        cout << "Invalid choice you have to enter the right option " << endl;
    cout << "Your total score is " << score << endl;
    if (score >= 8)
        cout << "You have passed the quiz " << endl;
    else
        cout << "Better luck next time" << endl;
}
