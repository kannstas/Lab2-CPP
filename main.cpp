
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main()
{
    int res = 0;
    int x, y, a, b;
    int attempts = 3;
    int sum = 0, total = 0;
    string rank;
    char choice;
    bool targ_rand = false, targ_hard = false;
    srand(time(NULL));
    cout << "Welcome to the shooting range!" << endl;
    cout << "Do you want to enable random centre? (y/n)" << endl;
    cin >> choice;
    switch (choice)
    {
        case ('y'):
            targ_rand = true;break;
        case('n'):
            targ_rand = false;break;
        default:
            cout << "Wrong symbol!" << endl;
    }
    cout << "Do you want to enable hard conditions? (y/n)" << endl;
    cin >> choice;
    switch (choice)
    {
        case ('y'):
            targ_hard = true;break;
        case('n'):
            targ_hard = false;break;
        default:
            cout << "Wrong symbol!" << endl;
    }
    cout << "Two types of game: classic(c) and Attempts(a) (c/a)" << endl;
    cin >> choice;
    switch (choice)
    {
        case ('c'):
        {
            for (int i = 0; i < attempts; i++)
            {
                if (targ_rand == true)
                {
                    a = rand() % 3 + 1;
                    cout << "Random target! centre shifted: " << a << endl;
                }
                else a = 0;
                if (targ_hard == true)
                {
                    b = rand() % 3 + 1;
                    cout << "Strong wind! Accuracy affected : " << b << endl;
                }
                else b = 0;
                cout << "Attempt No" << i + 1 << endl;
                cout << "Enter x coordinate" << endl;
                cin >> x;
                cout << "Enter y coordinate" << endl;
                cin >> y;
                cout << "x,y:" << x + b << " , " << y + b << endl;
                if (abs(x + b + a) <= 1 && abs(y + b + a) <= 1)
                    sum = 10;
                else if (abs(x + b + a) <= 2 && abs(y + b + a) <= 2)
                    sum = 5;
                else sum = 0;
                cout << "Score for this round: " << sum << endl;
                total += sum;
            }
            cout << "Total score: " << total << endl;
            if (total > 25)
                rank = "Sniper";
            else if (total > 10)
                rank = "Rookie";
            else rank = "Blinded";
            cout << "Amount of attempts: " << attempts << " Your rank: " << rank << endl;
            break;
        }


        case('a'):
        {
            int i = 0;
            while (total <= 50)
            {
                if (targ_rand == true)
                {
                    a = rand() % 3 + 1;
                    cout << "Random target! centre shifted: " << a << endl;
                }
                else a = 0;
                if (targ_hard == true)
                {
                    b = rand() % 3 + 1;
                    cout << "Strong wind! Accuracy affected : " << b << endl;
                }
                else b = 0;
                cout << "Attempt No" << i + 1 << endl;
                cout << "Enter x coordinate" << endl;
                cin >> x;
                cout << "Enter y coordinate" << endl;
                cin >> y;
                cout << "x,y:" << x + b << " , " << y + b << endl;
                if (abs(x + b + a) <= 1 && abs(y + b + a) <= 1)
                    sum = 10;
                else if (abs(x + b + a) <= 2 && abs(y + b + a) <= 2)
                    sum = 5;
                else sum = 0;
                cout << "Score for this round: " << sum << endl;
                total += sum;
                attempts++;
                i++;
            }
            cout << "Amount of attempts: " << attempts << endl;
            break;
        }

        default:
            cout << "Wrong symbol! No game for you!" << endl;
    }

}
