#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main(){

    int N, M;
    map<string, string> key_action;
    while (cin >> N >> M)
    {
        string key, action;
        for(int i = 0; i < N; ++i){
            cin >> key >> action;
            key_action[key] = action;
        }

        for(int i = 0; i < M; ++i){
            cin >> key;
            cout << key_action[key] << endl;
        }
    }
    


    return 0;
}