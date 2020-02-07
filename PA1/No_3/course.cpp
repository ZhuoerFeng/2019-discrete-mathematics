#include <bits/stdc++.h>
using namespace std;

const int maxn = (1 << 20);

int n;

vector<int> nxt[maxn];
vector<int> pre[maxn];
vector<int> node;
int d[maxn];
vector<int> srt;
queue<int> q;
int pi[maxn];
int tao[maxn];
vector<int> cri;
int father[maxn];
int judge[maxn];

void mymap() {
    memset(judge, 0, sizeof(judge));
    for (int i = 0; i < cri.size(); ++i) {
        judge[cri[i]] = 1;
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin >> n;
    node.push_back(0);
    for (int i = 1; i <= n; ++i) {
        int tim;
        cin >> tim;
        node.push_back(tim);
        cin >> d[i];
        for (int j = 0; j < d[i]; ++j) {
            int temp;
            cin >> temp;
            pre[i].push_back(temp);
        }    
    }    
        
    for (int i = 1; i <= n; ++i) {
        if (d[i]) {
            for (int j = 0; j < pre[i].size(); ++j) {
                int temp = pre[i][j];
                nxt[temp].push_back(i);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) {
            q.push(i);
            // cout << "PUSH: " << i << endl;
        }
    }

    // cout << "SIZE: " << q.size() << endl;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        // cout << "POP: " << endl;
        srt.push_back(v);
        // cout << "PUSH: " << v << endl;
        for (int i = 0; i < nxt[v].size(); ++i) {
            --d[ nxt[v][i] ];
            if (!d[nxt[v][i] ]) {
                q.push(nxt[v][i]);
                // cout << "PUSH: " << nxt[v][i] << endl;
            }
        }
    }

    for (int i = 0; i < n; ++ i) {
        int temp = srt[i];
        if (!pre[temp].size())  pi[temp] = node[temp];
        else {
            int t_max = 0, record;
            for (int j = 0; j < pre[temp].size(); ++j) {
                if ( pi[pre[temp][j]] + node[temp] > t_max)  t_max = pi[pre[temp][j]] + node[temp], record = pre[temp][j];
            }
            pi[temp] = t_max;
            father[temp] = record;
        }  
    }    
    
    vector<int> endp;
    int rec_end = -1;
    int most_time_use = 0;
    for (int i = 0; i < n; ++i) {
        if ( !nxt[srt[i]].size() )  {
            endp.push_back(srt[i]);
            if (most_time_use < pi[srt[i]]) {
                most_time_use =  pi[srt[i]];
                rec_end = srt[i];
            }
        }
    }

    srt[n] = n + 1;
    
    father[srt[n]] = rec_end;
    pi[srt[n]] = most_time_use;

    int c = rec_end;
    cri.push_back(c);
    // cout << "C = " << c << endl;
    while (c) {
        c = father[c];
        cri.push_back(c);
        // cout << "PUSH: " << c << endl;
    }
    

    /*
    for (auto v : nxt[u]) {
        // ....
    }
    for (auto v : pre[u]) {
        // ....
        
    }
    */

    // for (int i = 1; i <= n; ++i) {
    //     cout << node[i] << " - " ;
    // }
    // cout << endl;

    // for (int i = 1; i <= n; ++i) {
    //     cout << d[i] << endl;
    // }

    // cout << "PRE:" << endl;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j < pre[i].size(); ++j) {
    //         cout << pre[i][j] << " - " ;
    //     }    
    //     cout << endl; 
    // }    

    // cout << "NEXT:" << endl;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j < nxt[i].size(); ++j) {
    //         cout << nxt[i][j] << " - " ;
    //     }    
    //     cout << endl; 
    // }   

    // cout << "QUEUE:" << endl;
    // while (!q.empty()) {
    //     cout << q.front() << " - ";
    //     q.pop();
    // }
    // cout << endl;
    
    // for (int i = 0; i < srt.size(); ++i) {
    //     cout << srt[i] << " - " ;
    // }
    // cout << endl;

    // for (int i = 0; i < n; ++i) {
    //     cout << node[srt[i]] << " - ";
    // }
    // cout << endl;

    // for (int i = 0; i <= n; ++i) {
    //     cout << pi[srt[i]] << " - ";
    // }
    // cout << endl;

    // for (int i = 0; i <= n; ++i) {
    //     cout << father[srt[i]] << " - ";
    // }
    // cout << endl;

    // for (int i = 0; i < cri.size(); ++i) {
    //     cout << cri[i] << " - " ;
    // }
    // cout << endl;
    mymap();
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", pi[i], judge[i]);
    }    

    return 0;
}