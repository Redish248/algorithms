#include <iostream>
using namespace std;

int main() {
    int cameras[8];
    char labels[] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H'};

    int sum = 0;
    for (int i = 0; i < 8; i++) {
        cin >> cameras[i];
        sum += cameras[i];
    }
    if ((cameras[1] + cameras[3] + cameras[4] + cameras[6]) == (cameras[0] + cameras[2] + cameras[5] + cameras[7])) {
        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                while ((cameras[i] != 0) && (cameras[i + 4])) {
                    cameras[i]--;
                    cameras[i + 4]--;
                    cout << labels[i] << labels[i + 4] << '-' << endl;
                }
            } else {
                while ((cameras[i] != 0) && (cameras[i - 4])) {
                    cameras[i]--;
                    cameras[i - 4]--;
                    cout << labels[i] << labels[i - 4] << '-' << endl;
                }
            }

            if ((i != 3) && (i != 7)) {
                while ((cameras[i] != 0) && (cameras[i + 1])) {
                    cameras[i]--;
                    cameras[i + 1]--;
                    cout << labels[i] << labels[i + 1] << '-' << endl;
                }
            }

            if (i == 7) {
                while ((cameras[i] != 0) && (cameras[i - 3])) {
                    cameras[i]--;
                    cameras[i - 3]--;
                    cout << labels[i] << labels[i - 3] << '-' << endl;
                }
            }

            if ((i == 0) || (i == 4)) {
                while ((cameras[i] != 0) && (cameras[i + 3])) {
                    cameras[i]--;
                    cameras[i + 3]--;
                    cout << labels[i] << labels[i + 3] << '-' << endl;
                }
            } else {
                while ((cameras[i] != 0) && (cameras[i - 1])) {
                    cameras[i]--;
                    cameras[i - 1]--;
                    cout << labels[i] << labels[i - 1] << '-' << endl;
                }
            }

            //диагональные

            if (i < 2) {
                while ((cameras[i] != 0) && (cameras[i + 6])) {
                    cameras[i]--;
                    cameras[i + 6]--;
                    cout << labels[4] << labels[5] << '+' << endl;
                    cout << labels[i] << labels[i + 4] << '-' << endl;
                    if (i == 0) {
                        cout << labels[i + 5] << labels[i + 6] << '-' << endl;
                    } else {
                        cout << labels[i + 3] << labels[i + 6] << '-' << endl;
                    }
                }
            }
            if ((i > 1) && (i < 4)) {
                while ((cameras[i] != 0) && (cameras[i + 2])) {
                    cameras[i]--;
                    cameras[i + 2]--;
                    cout << labels[0] << labels[1] << '+' << endl;
                    if (i == 2) {
                        cout << labels[i - 1] << labels[i] << '-' << endl;
                    } else {
                        cout << labels[i - 3] << labels[i] << '-' << endl;
                    }
                    cout << labels[i - 2] << labels[i + 2] << '-' << endl;
                }
            }
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}