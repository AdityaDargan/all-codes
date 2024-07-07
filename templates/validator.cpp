#include "testlib.h"
#include <vector>
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 1e4, "t");
    inf.readEoln();

    int sum_n = 0;
    int sum_m = 0;

    for(int i=0;i<t;i++) {
        int k = inf.readInt(1,1e3,"k");
        inf.readEoln();

        int l = inf.readInt(1,1e7,"l");
        inf.readSpace();
        int n = inf.readInt(1,1e5,"n");
        inf.readEoln();

        int r = inf.readInt(1,1e7,"r");
        inf.readSpace();
        int m = inf.readInt(1,1e5,"m");
        inf.readEoln();
        
        for(int j=0;j<m;j++){
            int a = inf.readInt(-10000,10000,"a");
            if(j!=m-1) {
                inf.readSpace();
            }
        }
        if(i!=t-1){
            inf.readEoln();
        }
        sum_n += n;
        sum_m += m;
    }
    ensuref(sum_n <= 100000, "check for total n and m");
    ensuref(sum_m <= 100000, "check for total n and m");
    inf.readEof();
}