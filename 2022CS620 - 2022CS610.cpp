#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
    // This random value inilazine this variable
    int fullHistory = 345;
    // this start used to show the full history
start:
    string line;
    int i = 0;
    string checkID;
    bool found = false;
    // this open game history file read mode
    ifstream history("Game4.txt");
    int num1 = 0;
    int num2 = 0;
    int user = 0;
    int computer = 0;
    int totalGame = 0;
    int totalDraw = 0;
    int print = 0;
    // this check the id and plus the number of games and win and lose and draw to show thw total data
    while (getline(history, line))
    {
        num1 = 0;
        num2 = 0;
        int pos1 = 0;
        // cout << line << endl;
        // this used to find the id the id in the file
        int pos = line.find(" ");
        //  these two variables and used target the numbers in the line
        pos1 = line.find("$");
        int pos3 = line.find("*");

        // cout<<pos1<<endl;
        // cout<<endl<<"*"<<pos3<<endl;
        // This make the id from the file
        string checkID = line.substr(0, pos);
        // this will separate the number from the line
        string str = line.substr(pos1 + 1, pos3);
        int subpos = str.find("*");
        // This will easre the * from the number
        str.erase(subpos);
        // cout<<subpos<<endl;
        // This will convert the number string into integer
        for (int i = 0; i < str.length(); i++)
        {
            char str1 = str[i];
            num1 = static_cast<int>(str1);
            
            num1 -= 48;
            num2 = (num2 * 10) + num1;
        }
        // cout<<num2<<endl;
        // cout<<str<<endl;
        //  this will the @ * and id from the line string
        line.erase(pos3);
        line.erase(pos1, 1);
        if (print == 0)
        {
            line.erase(0, pos + 1);
        }

        if (checkID == user1.id || print != 0)
        {
            // this will used to print all the separate history of the user
            if (fullHistory == 1)
            {
                cout << line << endl;
            }
            // As data is store in the specific manner so in the first the it have number of rounds which is total game to calculate total games played by the user
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
    // getchar() isused the game on enter
    getchar();
start:
    system("CLS");
    int game;
    // List ofthe games
    cout << "\n\n\n\n\t\t\t\t\t\t\t\tGMAES IN C++\n\n";
    cout << "\t\t\t\t\tEnter \"1\" for TIC TAC TOE Game \n";
    cout << "\t\t\t\t\tEnter \"2\" for HEADS TAILS Game \n";
    cout << "\t\t\t\t\tEnter \"3\" for QUICKZ Game \n";
    cout << "\t\t\t\t\tEnter \"4\" for STONE PAPER SCISSOR Game \n";

    cin >> game;
    bool gamePlay = true;
    //  Tic Tac Toe game :
    if (game == 1)
    {
        int Playyer;
        cout << "For Double player, press \"1\"\n ";
        cout << "For Single player, press \"2\"\n ";
        cin >> Playyer;
        // These variables used store the number of wins if two playyers :
        int x = 0;
        int zero = 0;
        while (true)
        {
            int end = 0;
            cout << "How much round do want play \n";
            int round;
            cin >> round;
            while (true)
            {
                char positionArray[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
                int position;
                bool flag = false;
                char turn = 'X';
                bool validInput = true;
                bool drawGame = false;
                bool computerValid = false;

                // for selection of the game version :
                if (Playyer == 1)
                    cout << "Turn \"0\" win rounds is :       " << zero << endl;
                if (Playyer == 2)
                    cout << "Turn \"Computer\" win rounds is :      " << zero << endl;
                cout << "Turn \"x\" win rounds is :       " << x << endl;
                // To end the round loop :
                if (end == round)
                {
                    break;
                }
                while (true)
                {
                    system("CLS");
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
                    //  It print the turns :
                    PrintPosition(position, turn, flag, positionArray, validInput, computerValid);
                    // it for to check the win :
                    checkWin(flag, positionArray);
                    // it for the check the game is draw or not
                    checkDraw(flag, drawGame, positionArray);
                    // This  condition used if user play the double Playyer game this if statment is used to chane the value of turn variable it is not used in the
                    if (Playyer == 1)
                        if (validInput)
                            changeTurn(turn);
                    // this !flag is used to orint the real winner other wise it game the winner it is used in the single playyer version
                    if (!flag)
                    {
                        bool computerValid = true;
                        if (Playyer == 2 && validInput)
                        {
                            // This loop helps us when the computer entered in valid random number means it generate random number which already occupied
                            while (computerValid)
                            {
                                srand(time(0));
                                int randomNumber = 1 + rand() % 9;
                                changeTurn(turn);
                                // This function have conditions that it stop the user to win
                                StopToWin(randomNumber, positionArray);
                                // This function have conditions that it try the to win
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
                // This if statment is used because when loop breaks change turn function is excuted and it change the winner this condition is used to print the real winner
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
                // This is used to update the number of wins
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
                goto start;
            }
        }
    }
    // Head and Tail Game :
    if (game == 2)
    {
        // This loop is the game loop which help the user to play they can play
        while (gamePlay)
        {
            // these two varable are used to define the batting side and the bowling side :
            string bat;
            string chaser;
            int target = 0;
            int totalscore1 = 0;
            int user;
            bool computerScore = false;
            srand(time(0));
            int randomNumber1;
            // to perfrom the more random :
            string tossArr[10] = {"tails", "heads", "heads", "tails", "tails", "heads", "tails", "heads", "heads", "tails"};
            int randomIndex = rand() % 9;
            cout << randomIndex << endl;
            string toss;
            string inningArr[10] = {"BOWL", "BAT", "BOWL", "BOWL", "BAT", "BAT", "BOWL", "BAT", "BOWL", "BAT"};
            cout << "HEAD OR TAILS: \n";
            cin >> toss;
            // It converts the user entered number in to the lower case :
            char firstChar = tolower(toss[0]);
            while(true)
            {
                if(firstChar == 'h' || firstChar == 't')
                break;
                cout<<"Invalid input\n";
                cin>>toss;
            }
            // these condition user convinenice if user enter the wrong spelling in hurry it uses the first letter now have to enter the first char then computer will understand its choice
            if (firstChar == 'h')
            {
                toss = "heads";
            }
            else if (firstChar == 't')
            {
                toss = "tails";
            }
            //  these if cinditions are most in this game because determine batting and bowling side these are the base if the game

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
                //
                if (inningArr[userchoice] == "BAT")
                {
                    bat = "user";
                    chaser = "computer";
                }
                else
                {
                    bat = "Computer";
                    chaser = "user";
                    // This computerScore variable used to in the game to + the computer scores
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
                    // This computerScore variable used to in the game to + the computer scores
                    computerScore = true;
                }
                else
                {
                    bat = "user";
                    chaser = "computer";
                }
            }

            cout << bat << endl;
            // this loop play the batting
            while (true)
            {
                // this loop assure the user number will be less the or equal to 6
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
                    //  this condition is the base of the game which + he score according to batting or bowling side
                    // as above mention that computerScore is only ture when first batting side is computer in this condition as this is the batting side  while loop so this condition will add the score of computer
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
            // This loop will play the bowling
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
                    //  this condition is the base of the game which + he score according to batting or bowling side
                    // as above mention that computerScore is only ture when first batting side is computer in this condition as this the chaser while loop so this condition will add thje score of user
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
            // These are some conditions which determine the winner
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
            // This condition is used to controll the game loop
            if (gamePlayNum == 2)
            {
                goto start;
                gamePlay = false;
            }
        }
    }
    if (game == 3)
    {

        cout << "\n\n\t\t\t\tQUICKZ GAME \n\n";
        // This will excute the all the game :
        playgame();
        goto start;
    }
    if (game == 4)
    {
        int draw = 0;
        int userScore = 0;
        int computerScorce = 0;
        user user1;
        cout << "Enter your name :   ";
        // this is login system which take name id and password of the user
        cin >> user1.name;
        cout << "Enter your ID :   ";
        cin >> user1.id;
        cout << "Enter the Password  " << endl;
        cin >> user1.password;
        // This will open the files of the names which store names and id and password :
        ofstream outFile1("Names.txt", ios ::app);
        ifstream inFile("Names.txt");
        if (!inFile)
        {
            cout << "File is not opening\n";
        }
        string wordID;
        string wordPassword;
        bool flag = true;
        int history1;
        string line1;
        string wordName;
        //  This while loop is will read the id and password from the file of names
        while (getline(inFile, line1))
        {
            // inFile>>wordID>>wordPassword;
            // cout << line1 << endl;
            inFile >> wordID;
            inFile >> wordPassword;
            inFile >> wordName;
            bool doubleCheck = true;
            // this if condition is used to force the user enter the correct password according to the id
            if (user1.id == wordID && doubleCheck && user1.password != wordPassword)
            {
                if (wordPassword != user1.password)
                    while (!(user1.password == wordPassword))
                    {
                        cout << "Incorrect Password\n";
                        cin >> user1.password;
                    }
                // this condition is used when it enters the correct password it false the flag show that do write the dataof this user in to the file
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
            // this condition is used when it enters the correct password it false the flag show that do write the data of this user in to the file
            else if (user1.id == wordID && user1.password == wordPassword)
            {
                flag = false;
                doubleCheck = false;
                cout << "You Have sccessfully Loged in your accounct.\n";
                user1.name = wordName;
                cout << "Do you wnat check your history \n";
                cin >> history1;
                // this is used show the previous history of the user
                if (history1 == 1)
                    showHistory(user1);
                break;
            }
        }
        // this flag is used to write the data of new user
        if (flag)
        {
            outFile1 << user1.id << " " << user1.password << " " << user1.name << endl;
        }
        // outFile1.close();
        // This open the file to store the history of the user :
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
                // It i used for convinenice of the user if user have spell mistake then computer will be understand the user choice
                char secondChar = tolower(userchoice[1]);
                if (secondChar == 't')
                    userchoice = "stone";
                else if (secondChar == 'a')
                    userchoice = "paper";
                else if (secondChar == 'c')
                    userchoice = "scissor";
                else
                {
                    cout << "Invalid Input\n";
                    i--;
                }
                // This condition is for the draw game
                if (userchoice == StoneGameArr[randomNumber])
                {
                    cout << user1.name << " :       " << userchoice << endl;
                    cout << "computer :        " << StoneGameArr[randomNumber] << endl;
                    cout << "Match is draw\n";
                    draw++;
                }
                // These all conditions are work to perform the stone paper scissor according to rules
                // and these condition it ++ the number of wins of the user and computer
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
            // This condition is used to control the game loop
            cout << "Do you play again\n ";
            cout << "\"1\" for PLAY " << endl;
            cout << "\"2\" for QUIT " << endl;
            totalRounds += userRounds;
            int endGame;
            cin >> endGame;
            if (endGame == 2)
            {
                break;
            }
        }

        cout << "Scorese of Computer :       " << computerScorce << endl;
        cout << "Scorese of User :       " << userScore << endl;
        cout << "Do ypu want see your history\n";
        cin >> history1;
        // This will write the data into specific manner
        outFile << user1.id << " ";
        outFile << "Number of rounds which is played $" << totalRounds << "*" << endl;
        outFile << "Number rounds " << user1.name << " wins is $" << userScore << "*" << endl;
        outFile << "Number rounds computer wins is $" << computerScorce << "*" << endl;
        outFile << "Number of games Draw is $" << draw << "*" << endl;
        if (history1 == 1)
        {
            showHistory(user1);
        }
        goto start;
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
    // This have the user entered position so it first check that user entered position already occupied or not if yes then make the validInput and  false which helps in main to essure that user turn will be save  in function there is also some unused variable because of login is change like computerValid
    // If the position is not occupied then it have the positionArray which print the turn according to the user assign number
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
    // this function use the some condition that check the win it have condition that if same turns in same line then it ture the flag which breaks the loop in the main
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
    // this check that if all the positions is occupied and also flag is false which mean the game is running the is ture the falg which break the loop in main and also it true the drawgame which help to print the game result
    if ((positionArray[1] == 'X' || positionArray[1] == '0') && (positionArray[2] == 'X' || positionArray[2] == '0') && (positionArray[3] == 'X' || positionArray[3] == '0') && (positionArray[3] == 'X' || positionArray[3] == '0') && (positionArray[4] == 'X' || positionArray[4] == '0') && (positionArray[5] == 'X' || positionArray[5] == '0') && (positionArray[6] == 'X' || positionArray[6] == '0') && (positionArray[7] == 'X' || positionArray[7] == '0') && (positionArray[8] == 'X' || positionArray[8] == '0') && (positionArray[9] == 'X' || positionArray[9] == '0') && (flag == false))
    {
        drawGame = true;
        flag = true;
    }
}
void StopToWin(int &randomNumber, char positionArray[])
{
    // THis function have random number which is computer position this function changes the position of the computer
    // This function have the condition that if there 2 x is print in the line then print the 0 in this line which stop the user to win
    // it also wether x or 0 is already placed at desired position
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
    if ((positionArray[1] == 'X') && (positionArray[4] == 'X') && (positionArray[5] != 'X' && positionArray[5] != '0'))
    {
        randomNumber = 7;
    }
}
void TryToWin(int &randomNumber, char positionArray[])

{
    // This also changes the position of the computer in this conditions are used to try to win the computer with some conditions. Conditions is that if there is 2 0 in line and thrid place of the line also empty then print the 0 to positon
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
    // option is used get answer of the question from the user
    char option;
// this get s from user to play the game
start:
    cin >> c;

    if (c == 's' || c == 'S')
    {
        cout << "Q1 : What is the capital of pakistan? " << endl;
        cout << "a) Lahore" << endl;
        cout << "b) Karachi" << endl;
        cout << "c) Islamabad" << endl;
        cout << "d) Peshawar" << endl;
        cin >> option;
        // This loop i
        // This loop is used to take correct input from the user s used to take the correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }

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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
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
        // This loop is used to take correct input from the user
        while (true)
        {
            if (option == 'a' || option == 'A' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'd' || option == 'D')
                break;
            cout << "Invalid input\n";
            cin >> option;
        }
        if (option == 'c' || option == 'C')
            score = score + 1;
        else
            score = score + 0;
    }
    else
    {
        cout << "Invalid choice you have to enter the right option " << endl;
        goto start;
    }
    cout << "Your total score is " << score << endl;
    // This condition will show the pass or fail  result according to the score ;
    if (score >= 8)
        cout << "You have passed the quiz " << endl;
    else
        cout << "Better luck next time" << endl;
}
