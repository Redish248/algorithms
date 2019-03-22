#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(int arr[10000][2], int low, int high) {
    int i = low;
    int j = high;
    int x = arr[(low + high) / 2][0];
    int m,k;

    do {
        while (arr[i][0] > x) {
            ++i;
        }
        while (arr[j][0] < x) {
            --j;
        }
        if (i <= j){
            m = arr[i][0];
            k = arr[i][1];
            arr[i][0] = arr[j][0];
            arr[i][1] = arr[j][1];
            arr[j][0] = m;
            arr[j][1] = k;
            i++; j--;
        }
    } while (i <= j);

    if (low < j) {
        quick_sort(arr, low, j);
    }
    if (i < high) {
        quick_sort(arr, i, high);
    }
}


int main() {
    int n;
    int sign[10000][2];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sign[i][0];
        sign[i][1] = i + 1;
    }

    quick_sort(sign, 0, n - 1);

    while (n > 0) {
        if (n == 1) {
            while (sign[0][0] > 0) {
                cout << sign[0][1] << " ";
                sign[0][0]--;
            }
            n--;
        } else {
            while ((sign[0][0] >= sign[1][0]) && (sign[n - 1][0] > 0)) {
                cout << sign[0][1] << " ";
                sign[0][0]--;
                cout << sign[n-1][1] << " ";
                sign[n-1][0]--;
            }
            if (sign[n - 1][0] == 0) {
                n--;
            }

            if (n > 1) {
                if (sign[0][0] < sign[1][0]) {
                    quick_sort(sign, 0, n - 1);
                }
            }
        }
    }

    return 0;
}