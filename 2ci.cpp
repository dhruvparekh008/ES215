#include <iostream>
#include <time.h>

using namespace std;



int main()
{

    int num = 512;
    unsigned long long int p[num][num], q[num][num], r[num][num];

    for(int i = 0; i<num; i++){
    	for(int j = 0; j<num; j++){
    		p[i][j] = rand();
    		q[i][j] = rand();
    	}
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++)
        {
            r[i][j]=0;
        }
    }

    struct timespec ts;
    char buff[100];

    // Start
    timespec_get(&ts, TIME_UTC);
    unsigned long long  int start = ts.tv_nsec;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            for(int k = 0; k < num; k++)
            {
                r[i][j] += p[i][k] * q[k][j];
            }
        }
    }

    // End
    timespec_get(&ts, TIME_UTC);
    unsigned long long int end = ts.tv_nsec;
    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

    cout << endl << "Solution : " << endl;
    for(int i = 0; i < num; i++){
    	for(int j = 0; j < num; j++){
        cout << " " << r[i][j];
        if(j == num-1)
            cout << endl;
    	}
    }

    cout << "Total Time: " << end - start << " nsec" << endl;

    return 0;
}
