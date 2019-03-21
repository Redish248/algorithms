#include <iostream>
using namespace std;

int n;
int numbers[21];
int res = INT32_MAX;

void max(int i, int counter1, int counter2) {
    if ((abs(counter1 - counter2) < res) && (i == n)){
        res = abs(counter1 - counter2);
        return;
    }

    if (i < n) {
        max(i+1, counter1 + numbers[i], counter2);
        max(i+1, counter1, counter2 + numbers[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    max(0,0,0);

    cout << res << endl;
    return 0;
}
