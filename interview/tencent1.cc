#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main(){

    
    int n, k;

    //while(cin >> n >> k){
        cin >> n >> k;
    unsigned char high[n];

    int min_value = 0;
    
    for(int i=0; i<k; ++i){
        cin >> high[i];
        min_value += high[i];
    }
    int temp = min_value;
    int min_index = 1;
    for(int i=k; i < n; ++i)
    {
        cin >> high[i];
        temp = temp - high[i - k] + high[i];
        if(temp <= min_value){
            min_value = temp;
            min_index = i-k+2;
        }
            
    }

    cout << min_index << endl;
    //}
    return 0;
}

