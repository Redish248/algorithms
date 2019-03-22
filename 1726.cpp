#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long pathsX[n];
    long long pathsY[n];
    for (long long i=0; i<n;i++) {
        cin >> pathsX[i];
        cin >> pathsY[i];
    }

    long long result = 0;

    //sort x
    vector<long long> vectorX (pathsX, pathsX+ sizeof(pathsX)/ sizeof(pathsX[0]));
    sort(vectorX.begin(), vectorX.end(), greater<>());

    long long resultX = 0;

    for (unsigned long long i = 0; i < n; i++) {
        resultX += vectorX.at(i) * (n-2*i-1);
    }

    //sort y
    vector<long long> vectorY (pathsY, pathsY+n);
    sort(vectorY.begin(), vectorY.end(), greater<>());

    long long resultY = 0;

    for (unsigned long long i = 0; i < n; i++) {
        resultY += vectorY.at(i) * (n-2*i-1);
    }

    result = (resultX + resultY) * 2;

    long long count = n*n - n;
    result =  result / count;

    cout << result << endl;
    return 0;
}

