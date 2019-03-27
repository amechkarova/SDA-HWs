#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unordered_set<int> students;
    int student;
    cin >> student;
    students.insert(student);
    int n;
    cin >> n;
    while(n > 0)
    {
        int bestFriend;
        cin >> bestFriend;
        int candidate;
        cin >> candidate;
        unordered_set<int>::iterator it = students.find(bestFriend);
        if(it != students.end())
        {
            students.insert(candidate);
        }
        n--;
    }
    cout << students.size();
    return 0;
}
