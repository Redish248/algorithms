#include <iostream>
#include <cmath>

using namespace std;

int n;
int matrix[513][513];
int figure_number = 1;
int blackX, blackY, x, y;

void draw(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = figure_number;
            }
        }
    }
    figure_number++;
}

void square(int x1, int y1, int x2, int y2) {
    int square_number;

    if ((x2 - x1) == 1) {
        draw(x1, y1, x2, y2);
        return;
    }

    int centerX = x1 + (x2 - x1) / 2;
    int centerY = y1 + (y2 - y1) / 2;

    if (blackX > centerX) {
        if (blackY > centerY) {
            square_number = 4;
            square(centerX + 1, centerY + 1, x2, y2);
        } else {
            square_number = 2;
            square(centerX + 1, y1, x2, centerY);
        }
    } else {
        if (blackY > centerY) {
            square_number = 3;
            square(x1, centerY+1, centerX, y2);
        } else {
            square_number = 1;
            square(x1, y1, centerX, centerY);
        }
    }


    draw(centerX, centerY, centerX + 1, centerY + 1);

    if (square_number != 1) {
        blackX = centerX;
        blackY = centerY;
        square(x1, y1, centerX, centerY);
    }

    if (square_number != 2) {
        blackX = centerX + 1;
        blackY = centerY;
        square(centerX + 1, y1, x2, centerY);
    }

    if (square_number != 3) {
        blackX = centerX;
        blackY = centerY + 1;
        square(x1, centerY + 1, centerX, y2);
    }

    if (square_number != 4) {
        blackX = centerX + 1;
        blackY = centerY + 1;
        square(centerX + 1, centerY + 1, x2, y2);
    }

}

int main() {
    cin >> n;
    cin >> x;
    cin >> y;
    blackX = x;
    blackY = y;

    n = pow(2, n);

    square(1, 1, n, n);
    matrix[x][y] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
             cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}