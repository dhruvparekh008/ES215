#include <iostream>
#include<time.h>
using namespace std;

int main()
{
  int num;
  cin>>num;
  unsigned long long int test[100];
  test[0]=0;
  test[1]=1;

  struct timespec ts;
    char buff[100];

    // Start Time
    timespec_get(&ts, TIME_UTC);
    unsigned int start_sec = ts.tv_sec;
    unsigned int start_nsec = ts.tv_nsec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    cout << "Current time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;
    cout << "Raw timespec.time_t: " << ts.tv_sec << endl;
    cout << "Raw timespec.tv_nsec: " << ts.tv_nsec << endl;

  cout<<"1 "<<test[0]<<endl;
  cout<<"2 "<<test[1]<<endl;

  for(int i=2;i<=num;i++)
  {
    test[i]=test[i-1];
    test[i]+=test[i-2];
    cout<<test[i]<<endl;
  }

  // End Time
   timespec_get(&ts, TIME_UTC);
   unsigned int end_sec = ts.tv_sec;
   unsigned int end_nsec = ts.tv_nsec;

   strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
   cout << "Current time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;
   cout << "Raw timespec.time_t: " << ts.tv_sec << endl;
   cout << "Raw timespec.tv_nsec: " << ts.tv_nsec << endl;


   cout << "Total Time : " << end_sec - start_sec << " sec" << end_nsec - start_nsec << " nsec" << endl;

   return 0;
}
