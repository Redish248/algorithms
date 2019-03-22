#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;
    long max = INT16_MIN;
    long index_max = -1;
    long min = INT16_MAX;
    long index_min = -1;
    long sign[n][2];


    for (long i = 0; i < n; i++) {
        cin >> sign[i][0];
         sign[i][1] = i + 1;
        if (sign[i][0] >= max) {
            max = sign[i][0];
            index_max = i;
        }
        if ((sign[i][0] < min)) {
            min = sign[i][0];
            index_min = i;
        }


    }

    while ((index_min != index_max) && (min != INT16_MAX)) {
        cout << index_max + 1 << " ";
        cout << index_min + 1 << " ";
        sign[index_min][0]--;
        sign[index_max][0]--;

        max = INT16_MIN;
        min = INT16_MAX;
        for (long i = 0; i < n; i++) {
            if ((sign[i][0] >= max) && (sign[i][0] != 0)) {
                max = sign[i][0];
                index_max = i;
            }

            if ((sign[i][0] < min)  && (sign[i][0] != 0)) {
                min = sign[i][0];
                index_min = i;
            }

        }
    }

    for (int i = 0; i < max; i++) {
        cout << sign[index_max][1]<< " ";
    }

    return 0;
}