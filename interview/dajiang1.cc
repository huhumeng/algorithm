#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Test
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){

            return a.first > b.first;
        }
};


int select_game(int num_game, int number_day, const vector<pair<int, int> > &score_day){
	
    vector<vector<int> > result(num_game + 1, vector<int>(number_day + 1, 0));
    for(int i=1; i <= num_game; ++i){
        for(int j=1; j <= number_day; ++j){
            
            // current game time is not enough
            if (score_day[i].second > j)
			{
				result[i][j] = result[i - 1][j]; // so the total value is as same as previous, aka, a new game do nothing
			}
			else
			{
				int score1 = result[i - 1][j - score_day[i].second] + score_day[i].first;
				int score2 = result[i - 1][j];
				if (score1 > score2)
				{
					result[i][j] = score1;
				}
				else
				{
					result[i][j] = score2;
				}
			}
        }
    }

	return result[num_game][number_day];
}

int main(){

    int number_case;

    cin >> number_case;

    for(int i=0; i<number_case; ++i)
    {
        int number_game, number_day;
        cin >> number_game >> number_day;
        vector<pair<int, int> > score_day;

        int score, day;
        score_day.push_back(make_pair(0, 0));
        for(int j = 0; j < number_game; ++j){
            cin >> score >> day;    
            score_day.push_back(make_pair(score, day));
        }
        

		cout << select_game(number_game, number_day, score_day) << endl;
    }

    return 0;
}

