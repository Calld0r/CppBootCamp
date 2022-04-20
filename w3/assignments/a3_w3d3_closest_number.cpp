/*
    We want to generate 1024 random integers, then given a new random number; find two integers which are the
    closest to the given number (smaller, and bigger) with less than twelve lookups.
*/

#include <iostream>
#include <set>

#define MAX_SIZE 1024

using namespace std;

int main()
{
    set<int> randNums;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int rand_num = rand() % 34;
        randNums.emplace(rand_num);
    }

    auto num = randNums.find(rand() % 34);
    cout << "Bigger:          " << (*num + 1) << endl;
    cout << "Random Number:   " << (*num) << endl;
    cout << "Smaller:         " << (*num - 1) << endl;

    return 0;
}