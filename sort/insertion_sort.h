#pragma once

template <typename T>
class InsertionSort{

public:

    void sort(vector<T> &numbers){

        for(int i=1; i < numbers.size(); ++i){
            int j = i;
            while (j-- > 0)
            {
                if(numbers[j-1] > numbers[j]){
                    swap(numbers[j - 1], numbers[j]);
                }else
                {
                    break;
                }
                
            }
            

        }


    }

    string name(){return "insertion";}


};