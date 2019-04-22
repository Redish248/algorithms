#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    int country[101][101] = {};
    int colors[101] = {};
    queue<int> q;
    bool flag = true;

    for (int i = 1; i <= n; i++) {
        int node;
        cin >> node;
        while (node != 0) {
            country[i][node] = 1;
            country[node][i] = 1;
            cin >> node;
        }
    }

    colors[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 1; i <= n; i++ ) {
            if (colors[node] == colors[i] && (country[i][node] == 1)) {
                flag = false;
                goto out;
            }

            if (colors[i] == 0  && (country[i][node] == 1)  ) {
                if (colors[node] == 2) {
                    colors[i] = 1;
                } else {
                    colors[i] = 2;
                }
                q.push(i);
            }

        }

    }

    out:

    if (flag) {
        for (int i = 1; i <= n; i++) {
            cout << colors[i] - 1;
        }
    } else {
        cout << -1;
    }

    return 0;
}