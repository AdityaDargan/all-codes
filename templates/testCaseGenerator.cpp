#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <fstream>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <sys/types.h>
#define faster_io                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
using namespace std;
int32_t main()
{
    srand(time(0));
    faster_io;
    // Create and open a text file
    ofstream MyFile("testcase.txt");

    int t;
    int tc = 1;
    int nm = 100000/tc;
    int lst = 3234142;
    int nmst = 2246713;

    t = rand() % tc + 1;
    // Write to the file
    
    cout<<rand();
    MyFile << to_string(t) << endl;
    while (t--)
    {
        int k = rand() % 1000 + 1;
        MyFile << to_string(k) << endl;

        int l = 10000000;
        int n = nm;

        string line2 = "";
        line2 += (to_string(l) + " ");
        line2 += to_string(n);
        MyFile << line2 << endl;

        int val = min(10000000LL,l);
        // val = l;
        int r = 10000000;
        int m = nm;

        string line3 = "";
        line3 += (to_string(r) + " ");
        line3 += to_string(m);
        MyFile << line3 << endl;

        string s = "";
        for (int i = 0; i < m; i++)
        {   
            int sum = 0;
            for(int i=0;i<10;i++){
                sum += rand();
            }
            int a = sum % 10000 + 1;
            int sign = rand() % 2;
            if (sign)
                a = -a;
            s += (to_string(a) + " ");
        }
        MyFile << s << endl;
    }
    MyFile.close();
}