#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <unordered_map>

#include <algorithm>
#include <cstring>

using namespace std;

int sorted(const string &s1, const string &s2){

    if(s1.size() < s2.size())
        return 0;

    for(int i=0; i<s1.size(); ++i){

        if(s1[i] != s2[0])
            continue;

        for(int j=1; j < s2.size(); ++j){
            char c;
            if(i + j < s1.size())
                c = s1[i+j];
            else
                c = s1[i+j - s1.size()];

            
        }
    }
}

int isRotated(const string &s1, const string &s2){

    if(s1.size() < s2.size())
        return 0;

    for(int i = 0; i < s1.size(); ++i){
        
        if(s1[i] != s2[0])
        {
            continue;
        }
        bool flag = true;

        
        
        for(int j = 0; j < s2.size(); ++j){
            
            char c;
            if(i + j < s1.size())
                c = s1[i+j];
            else
                c = s1[i+j - s1.size()];

            if(c != s2[j]){
                flag = false;
                break;
            }
        }

        if(flag)
            return 1;

    }

    return 0;
}

// int main(){

//     cout << getstr("hellow world", 4) << endl;
//     return 0;

// }

int main(int argc, char **argv){
    



    

    while(true){

        string line1, line2, line3, line4, line5, line6;
        getline(cin, line1);
        getline(cin, line2);
        getline(cin, line3);

        getline(cin, line4);
        getline(cin, line5);
        getline(cin, line6);

        cout << isRotated(line1, line2);
        cout << isRotated(line3, line4); 
        cout << isRotated(line5, line6) << endl;
    }

    return 0;
}