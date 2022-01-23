#include <iostream>
#include <time.h>

using namespace std;



long long int sol(int n)
{
    if(n<=1)
    {
        return 1;
    }
    else
    {
        return sol(n-1) + sol(n-2);
    }
}

int main()
{
    int num;
    cin>>num;

    struct timespec tspace;
    char temp[100];


    timespec_get(&tspace, TIME_UTC);
    unsigned int start_sec = tspace.tv_sec;
    unsigned int start_nsec = tspace.tv_nsec;

    strftime(temp, sizeof temp, "%D %T", gmtime(&tspace.tv_sec));
    cout << "Current time: "<< temp << "." << tspace.tv_nsec << " UTC" << '\n';
    cout << "Raw timespec.time_t: " << tspace.tv_sec << '\n';
    cout << "Raw timespec.tv_nsec: " << tspace.tv_nsec << '\n';

    for(int j = 0; j<num; j++)
        {
            cout << j+1 << " " << sol(j) << '\n';
        }

    timespec_get(&tspace, TIME_UTC);
    unsigned int end_sec = tspace.tv_sec;
    unsigned int end_nsec = tspace.tv_nsec;

    strftime(temp, sizeof temp, "%D %T", gmtime(&tspace.tv_sec));
    cout << "Current time: "<< temp << "." << tspace.tv_nsec << " UTC" << '\n';
    cout << "Raw timespec.time_t: " << tspace.tv_sec << '\n';
    cout << "Raw timespec.tv_nsec: " << tspace.tv_nsec << '\n';


    cout << "Total Time Taken: " << end_sec - start_sec << " s" << end_nsec - start_nsec << " ns" << '\n';

    return 0;
}
