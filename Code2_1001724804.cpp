//Shubhayu Shrestha 1001724804
//Coding Assignment 2: C++ SLAM

/*  
General Objective: 
C++Slam! is our simulation of partof a real board game named Yamslam.  
We will simulate rolling5dice using a random number generator and our C++program will determine 
which dice combination is created by the dice.  Our player will get the option to reroll the dice to 
getadifferent combination.  The player will be allowed to roll 2 more times.Your program will be 
looking the following seven combinations    
*/

//Include Statements
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <cstring>

//creating defines
#define maxRolls 3
#define numberOfDice 5
#define testRolls 23
#define numberOfFaces 6

using namespace std;

//function prototype
string TestRollDice(vector<int> &diceVector);

//Roll dice function
void RollDice(vector<int> &diceVector)
{
    srand(time(NULL));
    int position;
    for (position = 0; position < numberOfDice; position++)
    {
        diceVector.push_back((rand() % numberOfFaces + 1));
    }
}

//Creating PrintRoll Function
void PrintRoll(vector<int> diceVector)
{
    //print vector using ranged based for loop
    cout << "\n\nYou rolled ";

    for (int it : diceVector)
        cout << it << " ";

    cout << "\n\n";
}

//Creating FillHowMany Function
void FillHowMany(vector<int> diceVector, vector<int> &howMany)
{
    for (int &HM : howMany)
    {
        HM = 0;  
    }
    for (int it : diceVector)
    {
        howMany[it - 1]++;
    }
}

//Creating Pick Dice Function
void PickDice(vector<int> &diceVector)
{
    int position = 0;
    int count = 0;
    char keep;

    cout << "\nPick which dice to reroll. Answer Y at the prompt to keep that die \n"
         << endl;

    do
    {
        cout << "Keep " << diceVector.at(position) << "?  ";
        cin >> keep;

        if (keep == 'N' || keep == 'n')
        {
            diceVector.erase(diceVector.begin() + position);
            diceVector.push_back(rand() % numberOfFaces + 1);
            count++;
        }
        else
        {
            position++;
            count++;
        }
    } while (count < numberOfDice);
}

int main(int argc, char *argv[])
{
    int rollCount = 0; //creating a reroll count
    char reroll;       //creating a continue char, to see if user would like to continue

    //initializing variables for C++ Slam
    int ofAKind = 0;
    int FullHouse = 0;
    int TwoPair = 0;
    int CPPSlam = 0;
    int LargeStraight = 0;
    int SmallStraight = 0;

    //creating dice vector
    vector<int> diceVector;

    //creating how many faces vector
    vector<int> howMany(numberOfFaces);

    if (argc == 2 && strcmp(argv[1], "TEST") == 0)
    {
        int resultPass = 0;
        do
        {
            //initializing variables for C++ Slam
            ofAKind = 0;
            FullHouse = 0;
            TwoPair = 0;
            CPPSlam = 0;
            LargeStraight = 0;
            SmallStraight = 0;

            string testDiceResult{};
            string outcome{};

            testDiceResult = TestRollDice(diceVector);

            PrintRoll(diceVector);

            FillHowMany(diceVector, howMany);

            int position = 0;

            //looping over how many
            for (int it : howMany)
            {
                if (howMany.at(position) == 3)
                {
                    FullHouse += 3;
                }

                if (howMany.at(position) == 2)
                {
                    FullHouse += 2;
                    TwoPair++;
                }

                if (howMany.at(position) == 5)
                {
                    CPPSlam++;
                }

                if (howMany.at(position) == 1)
                {
                    LargeStraight++;
                }
                else if (howMany.at(position) == 0 && LargeStraight > 0 && LargeStraight < 5)
                {
                    LargeStraight = 0;
                }

                if (howMany.at(position) >= 1)
                {
                    SmallStraight++;
                }
                else if (howMany.at(position) == 0 && SmallStraight > 0 && SmallStraight < 4)
                {
                    SmallStraight = 0;
                }

                if (howMany.at(position) == 4)
                {
                    ofAKind = 4;
                }

                if (howMany.at(position) == 3)
                {
                    ofAKind = 3;
                }

                position++;
            }

            //Checking for cases
            if (LargeStraight == 5)
            {
                outcome = "Large Straight";
            }
            else if (SmallStraight >= 4)
            {
                outcome = "Small Straight";
            }
            else if (FullHouse == 5)
            {
                outcome = "Full House";
            }
            else if (CPPSlam == 1)
            {
                outcome = "C++Slam!";
            }
            else if (ofAKind == 4)
            {
                outcome = "Four of a Kind";
            }
            else if (ofAKind == 3)
            {
                outcome = "Three of a Kind";
            }
            else if (TwoPair == 2)
            {
                outcome = "Two Pair";
            }
            else
            {
                outcome = "You have nothing";
            }

            cout << "\n" << outcome << endl;

            if (outcome.compare(testDiceResult) == 0)
            {
                cout << "\nTest Passed\n" << endl;
                resultPass++;
            }
            else
            {
                cout << "\nTest Failed\n" << endl;
            }
            rollCount++;

        } while (rollCount < testRolls);

        cout << "\nOut of " << testRolls << " tests, " << resultPass << " tests passed and " << (testRolls - resultPass) << " failed." << endl;
    }
    else
    {
        //calling roll dice function
        RollDice(diceVector);

        do
        {
            //initializing variables for C++ Slam
            ofAKind = 0;
            FullHouse = 0;
            TwoPair = 0;
            CPPSlam = 0;
            LargeStraight = 0;
            SmallStraight = 0;
            string outcome{};

            //calling print dice function
            PrintRoll(diceVector);

            //calling fill how many function.
            FillHowMany(diceVector, howMany);

            int position = 0;

            //looping over how many
            for (int it : howMany)
            {
                if (howMany.at(position) == 3)
                {
                    FullHouse += 3;
                }

                if (howMany.at(position) == 2)
                {
                    FullHouse += 2;
                    TwoPair++;
                }

                if (howMany.at(position) == 5)
                {
                    CPPSlam++;
                }

                if (howMany.at(position) == 1)
                {
                    LargeStraight++;
                }
                else if (howMany.at(position) == 0 && LargeStraight > 0 && LargeStraight < 5)
                {
                    LargeStraight = 0;
                }

                if (howMany.at(position) >= 1)
                {
                    SmallStraight++;
                }
                else if (howMany.at(position) == 0 && SmallStraight > 0 && SmallStraight < 4)
                {
                    SmallStraight = 0;
                }

                if (howMany.at(position) == 4)
                {
                    ofAKind = 4;
                }

                if (howMany.at(position) == 3)
                {
                    ofAKind = 3;
                }

                position++;
            }

            //Checking for cases
            if (LargeStraight == 5)
            {
                outcome = "Large Straight";
            }
            else if (SmallStraight >= 4)
            {
                outcome = "Small Straight";
            }
            else if (FullHouse == 5)
            {
                outcome = "Full House";
            }
            else if (CPPSlam == 1)
            {
                outcome = "C++Slam!";
            }
            else if (ofAKind == 4)
            {
                outcome = "Four of a Kind";
            }
            else if (ofAKind == 3)
            {
                outcome = "Three of a Kind";
            }
            else if (TwoPair == 2)
            {
                outcome = "Two Pair";
            }
            else
            {
                outcome = "You have nothing";
            }

            cout << "\n" << outcome << endl;

            if (rollCount == maxRolls)
            {
                rollCount = maxRolls + 1; //setting rollcount to max rolls + 1 so we can kick out of the loop and dont reprompt if the user wants to reroll
            }

            if (rollCount < maxRolls)
            {
                //print out what pair occured here
                cout << "\nDo you want to reroll?  ";
                cin >> reroll;

                if (reroll == 'y' || reroll == 'Y')
                {
                    PickDice(diceVector);
                    rollCount++;
                }
                else
                {
                    rollCount = maxRolls + 1; //setting rollcount to max rolls + 1 so we can kick out of the loop
                }
            }
        } while (rollCount <= maxRolls);
    }

    return 0;
}
