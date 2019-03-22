#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

int main() {
    int n;
    long y_min = 0, min = INT16_MAX;
    cin >> n;
    long coord[n][2];
    double corner[n][2];
    for (int i=0; i < n; i++) {
        cin >> coord[i][0];
        cin >> coord[i][1];
        if ((coord[i][1] < min)) {
            y_min = i;
            min = coord[i][1];
        } else {

            if ((coord[i][1] == min) && (coord[i][0] < coord[y_min][0])) {
                y_min = i;
                min = coord[i][1];
            }
        }

    }

    for ( int i = 0; i < n; i++) {
        if (coord[i][0] == coord[y_min][0]) {
            corner[i][0] = 90;
        } else {
            if (coord[i][1] == coord[y_min][1]) {
                corner[i][0] = 0;
            } else {
                if (coord[i][0] > coord[y_min][0]) {
                    double koeff = (double)(coord[i][1] - coord[y_min][1]) / (coord[i][0] - coord[y_min][0]);
                    corner[i][0] = atan(koeff) * 180 / PI;
                } else {
                    double koeff = (double)(coord[i][1] - coord[y_min][1]) / (double)abs(coord[i][0] - coord[y_min][0]);
                    corner[i][0] = 180 - atan(koeff) * 180 / PI;
                }

            }
        }

        corner[i][1] = i;
    }

    corner[y_min][0] = 1500;

    for (int i=0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j ++) {
            if (corner[j][0] > corner[j+1][0]) {
                    double m = corner[j][0];
                    double k = corner[j][1];
                    corner[j][0] = corner[j + 1][0];
                    corner[j][1] = corner[j + 1][1];
                    corner[j + 1][0] = m;
                    corner[j + 1][1] = k;

            }
        }
    }

    cout << y_min + 1 << " " << corner[n/2 - 1][1] + 1 << endl;

    return 0;
}