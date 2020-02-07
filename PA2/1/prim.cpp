#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int n;

struct Point {
    int x;
    int y;  
    int par;
    bool select;
    int depth;
};

vector<Point> p;
int dist[10005];

int calc(Point a, Point b) {
    int temp1 = a.x - b.x;
    int temp2 = a.y - b.y;
    return temp1 * temp1 + temp2 * temp2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        Point temp; temp.x = temp1, temp.y = temp2;
        temp.select = false;
        p.push_back(temp);
    }

    p[0].par = -1; // root
    p[0].select = true;
    int new_n = 0;
    int rec_n = 0;
    int temp_in = 1;
    for (int i = 1; i < n; ++i) {
        dist[i] = calc(p[0], p[i]);
        p[i].par = 0;
    }

    int cnt = 1;
    while (cnt <= n) {

        int temp_dist = (2 << 28);
        // calc the nearest dist for each point

        // pick the nearest dist, and point i
        for (int i = 1; i < n; ++i) { 
            if (!p[i].select) {
               if (dist[i] < temp_dist) {
                   temp_dist = dist[i];
                   new_n = i;
               }
            }
        }

        // do sth
        p[new_n].select = true;
        rec_n = new_n;
        // new the dist for each !selected point
        for (int i = 1; i < n; ++i) {
            if (!p[i].select) {
                int temp = calc(p[new_n], p[i]);
                if (dist[i] > temp) {
                    p[i].par = new_n;
                    dist[i] = temp;
                }
            }
        }
        ++cnt;
    }

    /** here we got the tree
    for (int i = 0; i < n; ++i) {
        printf("Point %d is (%d, %d), its par is %d\n", i, p[i].x, p[i].y, p[i].par );
    }
    */
    // then calc the depth
    p[0].depth = 0;
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        Point temp = p[i];
        while (temp.par != -1) {
            ++cnt;
            temp = p[temp.par];
        }
        p[i].depth = cnt;
    }
    // here we got the depth
    // for (int i = 0; i < n; ++i) {
    //     printf("Point %d is (%d, %d), its par is %d, it has depth %d\n", i, p[i].x, p[i].y, p[i].par, p[i].depth);
    // }
    
    int m;
    cin >> m;
    while (0 < m --) {
        int r1, r2;
        cin >> r1 >> r2;
        --r1;
        --r2;
        int dist = 0;
        while (r1 != r2) {
            if (p[r1].depth < p[r2].depth) {
                int temp = calc(p[r2], p[ p[r2].par ]);
                dist = max(temp, dist);
                r2 = p[r2].par;
            } else if (p[r1].depth > p[r2].depth) {
                int temp = calc(p[r1], p [p[r1].par]);
                dist = max(temp, dist);
                r1 = p[r1].par;
            } else {
                int temp = calc(p[r2], p[ p[r2].par ]);
                dist = max(temp, dist);
                r2 = p[r2].par;
            }
        }
        cout << dist << endl;
    }
    return 0;
}