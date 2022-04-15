/*
    Generate random numbers between 0-33, ten thousand times, then print how many duplicates of each number
    you have generated -- print in ascending order.
*/

#include <cstdlib>
#include <iostream>
#include <map>
#define MAX_SIZE 10000

using namespace std;

int main()
{
    map<int, int> numCount;
    int randNums[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int rand_num = rand() % 34;
        randNums[i] = rand_num;
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int curr_num = randNums[i];
        if (numCount.find(curr_num) == numCount.end())
        {
            numCount[curr_num] = 0;
        }
        numCount[curr_num]++;
    }

    cout << "NUM  "
         << "COUNT" << endl;

    for (auto itr = numCount.begin(); itr != numCount.end(); itr++)
    {
        cout << "#" << itr->first << " - " << itr->second << endl;
    }

    return 0;
}