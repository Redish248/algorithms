#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    int s = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        s +=k;
        if (s > max) {
            max = s;
        }
        if (s < 0) {
            s = 0;
        }
    }

    cout << max << endl;
    return 0;
}