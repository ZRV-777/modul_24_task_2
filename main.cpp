#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

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
        if (friend_list[i].birthday.tm_mon == local_time->tm_mon && friend_list[i].birthday.tm_mday == local_time->tm_mday)
        {
            cout << "Today is " << friend_list[i].name << "'s birthday!" << endl;
        }
        else
        {
            cout << friend_list[i].name << "'s birthday is " << friend_list[i].birthday.tm_mon + 1 << "/" << friend_list[i].birthday.tm_mday << endl;
        }
    }
}