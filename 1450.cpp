#include <iostream>
using namespace std;

typedef struct path {
    int x, y;
    long weight;
} path;

int main() {
    int n, k;
    cin >> n >> k;
    path graph[k+1];
    int begin, end;
    long dist[n+1];

    for (int i = 1; i <= k; i++) {
        long w;
        cin >> graph[i].x;
        cin >> graph[i].y;
        cin >> w;
        graph[i].weight = -w;
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INT32_MAX;
    }

    cin >> begin >> end;

    dist[begin] = 0;

    bool run = true;

    while (run) {
        run = false;
        for (int j = 1; j <= k; j++) {
            if (dist[graph[j].y] > dist[graph[j].x] + graph[j].weight) {
                dist[graph[j].y] = dist[graph[j].x] + graph[j].weight;
                run = true;
            }
        }
        if (!run) break;
    }


    if (-dist[end] > 0 && (-dist[end] <= INT32_MAX)) {
        cout << -dist[end];

    } else {
        cout << "No solution";
    }

    return 0;
}
