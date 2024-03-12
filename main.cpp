#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

struct Birthday
{
    string name;
    tm birthday;
};

int main()
{
    vector<Birthday> friend_list;

    time_t current_time = time(nullptr);
    tm* local_time = localtime(&current_time);

    string name;

    cout << "Enter friend`s name: ";
    cin >> name;

    while (name != "end")
    {
        if (name != "end")
        {
            cout << "Input birth date (YYYY/MM/DD): ";
            cin >> get_time(local_time, "%Y/%m/%d");
            friend_list.push_back({name, *local_time});
        }

        cout << "Enter friend`s name: ";
        cin >> name;
    }


    for (int i = 0; i < friend_list.size(); i++)
    {
        for (int j = 0; j < friend_list.size() - 1; j++)
        {
            if (friend_list[j].birthday.tm_mon > friend_list[j + 1].birthday.tm_mon)
            {
                swap(friend_list[j], friend_list[j + 1]);
            }
            else
            {
                if (friend_list[j].birthday.tm_mon == friend_list[j + 1].birthday.tm_mon)
                {
                    if (friend_list[j].birthday.tm_mday > friend_list[j + 1].birthday.tm_mon)
                    {
                        swap(friend_list[j], friend_list[j + 1]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < friend_list.size(); i++)
    {
        if (friend_list[i].birthday.tm_mon == local_time->tm_mon && friend_list[i].birthday.tm_mday == local_time->tm_mday)
        {
            cout << "Today is " << friend_list[i].name << "'s birthday!" << endl;
        }
        else
        {
            if (friend_list[i].birthday.tm_mon > local_time->tm_mon)
            {
                cout << friend_list[i].name << "'s birthday is " << put_time(&friend_list[i].birthday, "%d/%m") << endl;
                break;
            }
        }
    }
}