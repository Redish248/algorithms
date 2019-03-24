#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

typedef struct {
    long x;
    long y;
    double alpha;
    long index;
} pumpkin;

bool check(pumpkin one, pumpkin two) {
    if (one.alpha <= two.alpha) {
        if (one.alpha == two.alpha) {
            if (one.x == two.x) {
                if (floor(one.alpha) == 90) {
                    return one.y < two.y;
                } else {
                    return one.y > two.y;
                }
            } else {
                if (one.y == two.y) {
                    if (floor(one.alpha) == 0) {
                        return one.x < two.x;
                    } else {
                        return one.x > two.x;
                    }
                } else {
                    if (one.alpha > 0 && one.alpha < 180) {
                        return one.y < two.y;
                    } else {
                        return one.y > two.y;
                    }
                }
            }
        } else {
            return  true;
        }
    } else {
        return false;
    }
}


void quick_sort(pumpkin arr[30000], long low, long high) {
    long i = low;
    long j = high;
    pumpkin x = arr[(low + high) / 2];
    pumpkin m;

    do {
        while (check(arr[i], x)) {
            ++i;
        }
        while (check(x, arr[j])) {
            --j;
        }
        if (i <= j){
            m = arr[i];
            arr[i] = arr[j];
            arr[j] = m;
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

    long n;
    cin >> n;
    pumpkin pumpkins[30000];
    long pumpX = INT32_MAX, pumpY = INT32_MAX;

    cin >> pumpX >> pumpY;

    for (int i = 0; i < n - 1; i++) {
        cin >> pumpkins[i].x >> pumpkins[i].y;
        double r = atan2((double)(pumpkins[i].y - pumpY), (pumpkins[i].x - pumpX));
        if (r < 0) {
            r = 2*PI + r;
        }
        pumpkins[i].alpha = r*360/(2*PI);
        pumpkins[i].index = i + 2;
    }

    quick_sort( pumpkins, 0, n - 2);

    cout << n << endl;
    cout << 1 << endl;

    if (floor(pumpkins[0].alpha) >= 90) {
        for (long i = 0; i < n - 1; i++) {
            if (pumpkins[i].alpha > 90) {
                cout << pumpkins[i].index << endl;
            }
        }
        for (long i = 0; i < n - 1; i++) {
            if (pumpkins[i].alpha <= 90) {
                cout << pumpkins[i].index << endl;
            }
        }
    } else {
        for (long i = 0; i < n - 1; i++) {
            if (pumpkins[i].alpha > 180) {
                cout << pumpkins[i].index << endl;
            }
        }
        for (long i = 0; i < n - 1; i++) {
            if (pumpkins[i].alpha <= 180) {
                cout << pumpkins[i].index << endl;
            }
        }
    }

    return 0;
}