#include<iostream>
#include<time.h>

using namespace std;

int main()
{
  int num;
  cin>>num;

  int temp;

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




  unsigned long long int a=1;
  unsigned long long int b=1;
  cout<<a<<" "<<b<<endl;
  cout<<b<<" "<<a+b<<endl;

  for(int i=3;i<=num;i++)
  {
    temp=b;
    b=a+b;
    a=temp;

    cout<<i<<" "<<b<<endl;


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
