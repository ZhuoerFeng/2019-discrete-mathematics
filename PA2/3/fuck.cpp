#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pre[1005];
vector<int> nxt[1005];
int count[1005];  // the index is the kexuhao
bool jianzhi[1005];

int len = 0;
int max_cnt = 0;

void dfs(int course) {
    if (nxt[course].size() == 0) {
        if (len > max_cnt) {
            max_cnt = len;
        }
        return;
    } else {
        for (int i = 0; i < nxt[course].size(); ++i ){
            ++len;
            jianzhi[course] = false;
            dfs(nxt[course][i]);
            --len;
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> count[i];
        if (count[i]) {
            int temp;
            cin >> temp;
            pre[i].push_back(temp);
            nxt[temp].push_back(i);
        }
        jianzhi[i] = true;
    }

    int cnt = 0;
    int big = 0;

    for (int i = 1; i <= n; ++i) {
        if (jianzhi[i]) {
            jianzhi[i] = false;
            dfs(i);
        }
    }1

    
}