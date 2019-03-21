#include <iostream>
using namespace std;

int main() {
    int numberTests = 0;
    //количество тестов
    cin >> numberTests;
    for (int i = 0; i < numberTests; i++) {
        int n;
        //бойцы
        cin >> n;
        int k;
        //команды
        cin >> k;

        int result = 0;
        for (int j = 0; j < k-1; j ++) {
            for (int p = j+1; p < k; p++) {
                int div = n / k;
                int m,e;
                if (j < n % k) {
                    m = 1 + div;
                } else {
                    m = div;
                }
                if (p < n % k) {
                    e = 1 + div;
                } else {
                    e = div;
                }
                result += m * e;
            }
        }

        cout << result << endl;

    }
    return 0;
}