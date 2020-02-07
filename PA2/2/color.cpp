#include <bits/stdc++.h>
using namespace std;

//与陈博涵同学交流了本题的暴力解法的可能，了解到由于数据规模较小可以使用暴力搜索的方法求解本题

int max_color;
int n, m;

int color[15];

struct Graph {
    int mat[15][15];
} g;

bool judge(int n) {
    // cout << "n = " << n << endl;
    bool tag = true;
    for (int i = 1; i < n - 1; ++i) {
        // cout << "gmat[" << i << "][" << n - 1<< "] = " << g.mat[i][n - 1] << endl;
        // cout << "color[" << i << "] = " << color[i] << "  color[" << n - 1 << "] = " <<  color[n - 1] << endl;
        if ( g.mat[i][n - 1] == 1 && (color[i] == color[n - 1]) ) {
            // cout << "FUCK" << endl;
            tag = false;
            break;
        }
    }
    return tag;
}

void testout() {
    for (int i = 1; i <= 9; ++i) {
        cout << color[i] << ", ";
    }
    cout << endl;
}


bool dfs(int x) {
    // cout << "ROUND x = " << x << endl;
    // testout();
    if ( !judge(x) ) return false;
    if (x > n) return true;
    for (int c = 1; c <= max_color; ++c ) {
        color[x] = c;
        if (dfs(x + 1)) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= 14; ++i) {
        for (int j = 0; j <= 14; ++j) {
            g.mat[i][j] = 0;
        }
        color[i] = 0;
    }

    /**
    if (m == n * (n - 1) / 2) {
        cout << n << endl;
        return 0;
    } else if (m == n * (n - 1) / 2 - 1) {
        cout << n - 1 << endl;
        return 0;
    } else if (m == 0) {
        cout << "0\n";
        return 0;
    }
    */
    for (int i = 0; i < m; ++i ){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        g.mat[temp1][temp2] = g.mat[temp2][temp1] = 1;
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << g.mat[i][j] << " "; 
    //     }
    //     cout << endl;
    // }

    for (max_color = 1; max_color <= 10; max_color++) {
        if (dfs(1)) {
            cout << max_color << endl;
            // cout << "fuck" << endl;
            break;
        }
    }


    return 0;
}