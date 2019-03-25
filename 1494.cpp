#include <iostream>
using namespace std;

int main() {
    int n;
    bool cheater = false;
    long max = 0;
    cin >> n;
    long stack[n];
    long stack_position = 0;
    long ball;

    for (int i = 0; i < n; i++) {
       cin >> ball;
       if (ball > max) {
           if (ball - max > 1) {
               max++;
               while (max < ball) {
                   stack[stack_position] = max;
                   stack_position++;
                   max++;
               }
           }
           max = ball;
       } else {
           if (stack[stack_position - 1] == ball) {
               stack_position--;
           } else {
               cheater = true;
           }
       }
    }

    if (cheater) {
        cout << "Cheater" << endl;
    } else {
        cout << "Not a proof" << endl;
    }

    return 0;
}