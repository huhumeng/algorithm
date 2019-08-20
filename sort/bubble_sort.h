#pragma once

#pragma once

template <typename T>
class BubbleSort{

public:

    void sort(vector<T> &numbers){

        for(int i=0; i < numbers.size(); ++i){
            for(int j=0; j < numbers.size() - i - 1; ++j){
                if(numbers[j] > numbers[j + 1])
                    swap(numbers[j], numbers[j + 1]);
            }
        }


    }

    string name(){return "bubble";}


};