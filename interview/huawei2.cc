#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <unordered_map>

#include <algorithm>

using namespace std;

int main(int argc, char **argv){

    double average_price;

    while (cin >> average_price)
    {
        double diff = 1e10;
        int rN, rM;
        for(int N = 1; N < 10000; ++N)
        {
            int M = average_price * (double)N;

            for(int i = M - 2; i <= M + 2; ++i){
                double d = abs((double)i / (double)N - average_price);

                if(d < diff){
                    if(abs(d - diff) < 1e-5){
                        continue;
                    }
                    diff = d;
                    rN = N;
                    rM = i;
                }

                
            }
        }
        
        std::cout << rM << " " << rN << endl;

    }
    


    return 0;
}