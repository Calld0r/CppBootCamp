/*
================================================================================================================
Kristen is a contender for valedictorian of her high school. She wants to know how many students (if any) have
scored higher than her in the exams given during this semester.
Create a class named with the following specifications:
•An instance variable named to hold a student's exam scores.
•A void input() function that reads integers and saves them to .
•An int calculateTotalScore() function that returns the sum of the student's scores.

Reference: https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/classes-objects
================================================================================================================
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student {
private:
    double scores[5];
public:
    void input() {
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }
    }
    int calculateTotalScore() {
        int total = 0;
        for (int i = 0; i < 5; i++) { 
            total = total + scores[i];
        }
        return total;
    }
};


int main() {
    int n; // number of students
    cout << "Enter number of students: ";
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    cout << "Enter results for the " << n << " students, with Kristines score first. Use format '# # # # #' " << endl;
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    

    // Print result
    cout << "Number of students with higher score than Kristen: " << count << endl;
    
    return 0;
}