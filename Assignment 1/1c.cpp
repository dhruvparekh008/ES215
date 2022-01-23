#include<iostream>
#include<time.h>

using namespace std;

unsigned long long int sol(int m, unsigned long long int store[], int test[])
{
  if(test[m]==1)
  {
    return store[m];
  }
  else
  {
    unsigned long long int nxt = sol(m-1, store, test) + sol(m-2, store, test);
    test[m]=1;
    store[m]=1;
    return nxt;
  }
}

int main()
{
  int num;
  cin>>num;
  unsigned long long int store[num];
  int test[100]={0};
  test[0]=1;
  test[1]=1;
  store[0]=1;
  store[1]=1;

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



  for(int j=0; j<num;j++)
  {
    cout<<j+1<<" "<< sol(j, store, test)<< endl;
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
