#include "Runner.h"
#include <iostream>
#include <string>

using namespace std;


Runner::Runner() {
    firstname = "       ";
    lastname = "        ";
    pace = 0;
}

Runner::Runner(string firstname, string lastname, int pace) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->pace = pace;

}

string Runner::Get_Firstname()
{
    return firstname;
}

string Runner::Get_LastName()
{
    return lastname;
}

int Runner::Get_Pace()
{
    return pace;
}
// net group func

string Runner::SecondsToHrs(int time) 
{
    string TT = to_string(time / 3600);
    if (time / 3600 >= 10) 
    {
            return TT;
    }
    else 
    {
        return "0" + TT;
}

string Runner::SecondsToMinutes(int time)
{
    string TT = to_string((time % 3600) / 60);
    if ((time % 3600) / 60 >= 10) 
    {
        return TT;
    }
    else 
    {
        return "0" + TT;
    }
}

string Runner::SecondsToSeconds(int time) 
{
    string TT = to_string((time % 3600) % 60);
    if ((time % 3600) % 60 >= 10) 
    {
        return TT;
    }
    else 
    {
        return "0" + TT;
    }
}