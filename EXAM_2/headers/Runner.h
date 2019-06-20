#ifndef RUNNER_H
#define RUNNER_H
#include <string>


class Runner
{
    // not working
    enum RunGroup{White, Yellow, Green, Orange, Blue, Lilac, Red};
    
    private:
        // declaring string vars for runners first and last name
        // TT will be used for time (hour minute second)
        string firstname, lastname, TT;
        // delcaring pace for runners as int
        int pace;
        // declaring the colors for groups
        RunGroup RunG;

    public:
        // no argument constructor
        Runner();
        // constructor with arguments
        Runner(string, string, int);
        // getting first name of runner
        string Get_FirstName();
        // getting last name of runner
        string Get_LastName();
        // getting the pace of the runner
        int Get_Pace();
        // getting color group of runner based on pace
        // not working, going to delcaring and initinalize
        // them in main
        RunGroup Get_RunG();
        // conversion for seconds to a hour
        string SecondsToHours(int);
        // conversion for seconds to a minute
        string SecondsToMinutes(int);
        // conversion for seconds to seconds
        string SecondsToSeconds(int); 

};

#endif