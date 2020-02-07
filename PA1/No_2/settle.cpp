#include <bits/stdc++.h>
using namespace std;

const int MAX = (1 << 25 );
int edge[205][205];
int n, m;
int var[40005];
int stap[40005], endp[40005];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n; ++j) {
            edge[i][j] = MAX;
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        cin >> stap[i] >> endp[i] >> var[i];
        edge[stap[i]][endp[i]] = edge[endp[i]][stap[i]] = var[i];
    }
    // for (int i = 0; i < m; ++i)  cout << stap[i] << " - " ; cout << endl;
    // for (int i = 0; i < m; ++i)  cout << endp[i] << " - " ; cout << endl;
    // for (int i = 0; i < m; ++i)  cout << var[i] << " - " ; cout << endl;

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << edge[i][j] << " - ";
    //     }
    //     cout << endl;
    // } 
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        edge[i][i] = 0;
    }    

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << edge[i][j] << " - ";
    //     }
    //     cout << endl;
    // } 
    int dis[205];
    int rec = MAX;

    for (int i = 0; i < m; ++i) {
        for (int x = 0; x <= var[i] * 2; ++x) {
            int temp = 0;
            for (int k = 1; k <= n; ++k) {
                dis[k] = min (edge[k][stap[i]] * 2 + x, edge[k][endp[i]] * 2 + var[i] * 2 - x);
                if (temp < dis[k])  temp = dis[k];
                // if (temp > rec)  break;
                // cout << "dis[" << k << "] = " << dis[k] << "**";
            }
            // cout << "  BIG = " << dis[1] << endl;
            if (temp < rec)  temp = rec;
            x = x + temp - rec ;
        }
    }

    cout << rec / 2.0 << endl;
    return 0;
}