#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;

class Pt {
public:
    int x;
    int y;
    bool flag;
    int id;
    int par;
} point[MAX];

struct e{
    int b;
    int e;
    int val;

} edge[MAX][MAX];

vector<Pt> nodes;
int d[MAX];
vector<e> ans;
int n, q;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> point[i].x >> point[i].y;
        point[i].id = i;
        point[i].flag = false;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int delta_x = point[i].x - point[j].x;
            int delta_y = point[i].y - point[j].y;
            edge[i][j].val = delta_x * delta_x + delta_y * delta_y;
            edge[i][j].b = i;
            edge[i][j].e = j;
            edge[j][i].val = edge[j][i].val;
            edge[j][i].b = j;
            edge[j][i].e = i;
        }
    }

    nodes.push_back(point[1]);
    point[1].flag = true;

    for (int i = 2; i <= n; ++i) {
        d[i] = edge[i][1].val;
    }
    for (int i = 1; i <= n; ++i) {
        cout << "[" << i << "]" << point[i].x << "," << point[i].y << endl;
    }





    int temp = 1;
    point[1].flag = true;
    for (int i = 2; i <= n; ++i) {
        point[i].par = 1;
    }

    while (ans.size() < n - 1) {
        int minlen = 200000000;        
        for (int i = 1; i <= n; ++ i){
            if (d[i] < minlen && point[i].flag == false) {
                minlen = d[i];
                temp = i;
            }
        }
        point[temp].flag = true; // add into
        ans.push_back(edge[ point[temp].par][temp]);
        cout << "point no: " << temp << " " << endl << "dist: "<<  edge[point[temp].par][temp].val << endl;
        
        for (int i = 1; i <= n; ++i) {
            if (point[i].flag == false) {
                int dist = edge[i][temp].val;
                if (dist < d[i] ) {
                    point[i].par = temp;
                    d[i] = dist;
                    
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].b << " "  << ans[i].e << endl;
    }
    return 0;
}