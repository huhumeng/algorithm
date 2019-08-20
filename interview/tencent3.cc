#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    unsigned long long n, m;
    cin >> n >> m;
    unsigned long long weight[n];
    unsigned long long value[n];

    for(int i=0; i<n; ++i){
        cin >> weight[i];
    }
    for(int i=0; i<n; ++i){
        cin >> value[i];
    }

    int count = 0;
    while (true)
    {
        bool cond = true;
        for(int i = 0; i < n; ++i){
            if(weight[i] > 0){
                weight[i]--;
            }else if (m > value[i])
            {
                m -= value[i];
            }else
            {
                cond = false;
            }   
        }
        if(cond){
            count++;
        }else
        {
            break;
        }
        
    }
    
    cout << count << endl;

    return 0;
}