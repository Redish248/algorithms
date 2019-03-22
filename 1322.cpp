#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    n--;
    string str;
    cin >> str;

    long stringSize = str.size();
    int count[100000];
    int T[100000];

    for(int i = 0; i < stringSize; i++) {
        count[str[i]]++;
    }

    int sum = 0;
    for(int i = 0; i < 100000; i++) {
        sum += count[i];
        count[i] = sum - count[i];
    }

    for(int i = 0; i < stringSize; i++) {
        T[count[str[i]]]=i;
        count[str[i]]++;
    }

    int index = T[n];
    for (int i = 0; i < stringSize; i++) {
        cout << str[index];
        index = T[index];
    }

    return 0;
}