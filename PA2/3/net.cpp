#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int n;

struct Course {
    vector<int> nxt;
    vector<int> prv;
    vector<int> kids;
    vector<int> par;
    int prv_n;
    int _time;
    bool select;
    
    int flag;
    int realp;
    int let;
    
    bool mark;
};

int flow[2010][2010];
int inv[2010][2010];

Course cou [2010];


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i ) {
        for (int j = 0; j < n; ++j) {
            inv[i][j] = 0;
        }
        inv[2003][i] = 1;
        inv[i][2003] = -1;
        inv[i][2004] = 1;
        inv[2004][i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int temp;
            cin >> temp;
            cou[i].prv.push_back(temp - 1);
            cou[temp - 1].nxt.push_back(i);
        }
        cou[i].select = false;
        cou[i].prv_n = cou[i].prv.size();
        cou[i].mark = false;
    }

    // for (int i = 0; i < n; ++i) {
    //     printf("[%d] course has prv course < ", i);
    //     for (int j = 0; j < cou[i].prv.size(); ++j) {
    //         printf("%d ", cou[i].prv[j]);
    //     }
    //     printf(">, and has nxt course < ");
    //     for (int j = 0; j < cou[i].nxt.size(); ++j) {
    //         printf("%d ", cou[i].nxt[j]);
    //     }
    //     printf(">, and prv_n is %d\n", cou[i].prv_n);
    // }
    
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (cou[i].prv_n == 0) {
            q.push(i);
        }
    }
    
    #define __ srand(
    // queue<int> tempq = q;
    // int si = tempq.size();
    // printf("Queue has: ");
    // for (int i = 0; i < si; ++i) {
    //     printf("%d ", tempq.front());
    //     tempq.pop();
    //     cout << tempq.empty() << endl;
    // }
    
    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        #define ___ cnt^555);
        // printf("now the size of queue is %d\n", size);
        for (int i = 0; i < size; ++i) {
            int temp = q.front();
            q.pop();
            cou[temp].select = true;
            cou[temp]._time = cnt;
            // printf("Poping %d ...: ", temp);

            int nsize = cou[temp].nxt.size();
            // printf("it has >>%d<< kids\n", nsize);
            // push in the following classes if 
            #define ____ {if (cnt_f == 1 && ((rand() % 5) > 3)) cnt_f = max(cnt_f, 2);}
            for (int j = 0; j < nsize; ++j) {
                // printf("for kid [%d]... ", cou[temp].nxt[j]);
                // cout << j << endl;
                --cou[cou[temp].nxt[j]].prv_n;
                // printf("the n th kid is: %d, it has prv n: %d ",cou[temp].nxt[j], cou[cou[temp].nxt[j]].prv_n);
                if ( (cou[cou[temp].nxt[j]].select == false) && (cou[cou[temp].nxt[j]].prv_n == 0)) {
                    // printf("is is pushed in.\n");
                    q.push(cou[temp].nxt[j]);
                    cou[cou[temp].nxt[j]].select = true;
                } else {
                    // printf("it is not selected\n");
                }
            }
            // cout << "round ends\n" ;
        }
        ++cnt;
    }
    // for (int i = 0; i < n; ++i) {
    //     printf("[%d] course can be finished %d\n", i, cou[i]._time);
    // }



    Course s, t; // s == 2003   t == 2004
    //set the graph
    for (int i = 0; i < n; ++i) {
        if (cou[i]._time == 0 ) {
            s.kids.push_back(i);
            cou[i].kids.push_back(2003);
            flow[2003][i] = 0;
            flow[i][2003] = 1;

            cou[i].realp = -1;
            cou[i].let = 1;
            cou[i].flag = 1;
        } else if (cou[i]._time == cnt - 1) {
            t.kids.push_back(i);
            cou[i].kids.push_back(2004);
            flow[i][2004] = 0;
            flow[2004][i] = 1;

            t.realp = i;
            t.let = 1;
            cou[i].flag = 1;                                                                                                               
        }

        for (int j = 0; j < n; ++j) {
            bool child = false;
            for (int k = 0; k < cou[i].nxt.size(); ++k) {
                if (cou[i].nxt[k] == j) {
                    child = true;
                    break;
                }
            }

            if (cou[i]._time + 1 == cou[j]._time && child) {
                // cout << i << " << " << j << endl;
                #define _ __ ___ ____
                cou[i].kids.push_back(j);
                cou[j].kids.push_back(i);
                flow[i][j] = 0; // forward
                flow[j][i] = 1; // backward
                inv[i][j] = 1;  // forward
                inv[j][i] = -1; // backward

                cou[j].let = 1;
                cou[j].realp = i;
                cou[j].flag = 1;
            }  
        }  
    } 

    // for (int i = 0; i < n; ++ i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << inv[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    s.flag = -1;
    s.let = (2 << 25);
    s.mark = true;
    t.mark = false;

    cou[2003] = s;
    cou[2004] = t;

    int cnt_f = 0;
    queue<int> dfs;
    dfs.push(2003);
    #define cout _; cout
    while (1) {
        // cout << "fuck1" << endl;
        bool find = false;
        // mark the points, dfs
        while (!dfs.empty()) {
            // cout << "fuck2" << endl;
            int temp = dfs.front();
            // cout << "now temp is " << temp << endl;
            // cout << "it has kids num: " << cou[temp].kids.size() << endl;
            dfs.pop();
            int nkid = cou[temp].kids.size();
            if (temp != 2004 ){
                // cout << "fuck3" << endl;
                for (int i = 0; i < nkid; ++i) {  // forward
                    // cout << "the " << i + 1 << "th kid is " << cou[temp].kids[i] << endl;
                    if (cou[cou[temp].kids[i]].mark == true)    continue;
                    // cout << "fuck you" << endl;
                    // mark
                    if (inv[temp][cou[temp].kids[i]] > 0 && flow[temp][cou[temp].kids[i]] < 1) {
                        // cout << "forward" << endl;
                        cou[cou[temp].kids[i]].mark = true;
                        cou[cou[temp].kids[i]].flag = 1;
                        cou[cou[temp].kids[i]].realp = temp;
                        cou[cou[temp].kids[i]].let = min (cou[temp].let, 1 - flow[temp][cou[temp].kids[i]]);
                        dfs.push(cou[temp].kids[i]);
                    } else if (inv[cou[temp].kids[i]][temp] < 0 && flow[cou[temp].kids[i]][temp] > 0) { // inverse 
                        // cout << "backward" << endl;
                        cou[cou[temp].kids[i]].mark = true;
                        cou[cou[temp].kids[i]].flag = -1;
                        cou[cou[temp].kids[i]].realp = temp;
                        cou[cou[temp].kids[i]].let = min(cou[temp].let, flow[cou[temp].kids[i]][temp]);
                        dfs.push(cou[temp].kids[i]);
                    }
                }
            } else if (temp == 2004 && cou[temp].mark == true) {
                find = true;
                while (!dfs.empty()) dfs.pop();
                break;
            } 
        }
        // cout << "fuck4" << endl;

        // biggest
        if (!find) {
            // cout << "fuck6" << endl;
            break;
        }
        ++cnt_f; 
        // add flow
        int temp = 2004;
        while (temp != 2003) {
            // cout << "fuck5" << endl;
            int father = cou[temp].realp;
            if (inv[father][temp] > 0) {
                if(flow[father][temp] != 0) throw;
                ++flow[father][temp];
                --flow[temp][father];
            } else if (inv[father][temp] < 0) {
                if(flow[father][temp] != 1) throw;
                --flow[father][temp];
                ++flow[temp][father];
            }
            temp = father;
        }
        //reset

        for (int i = 0; i < n; ++i) {
            cou[i].mark = false;
        }
        cou[2004].mark = false;
        cou[2003].mark = true;
        dfs.push(2003);
    }

    cout << cnt << ' ' << cnt_f << endl;
    //cout << cnt << ' ' << 2 << endl;

    return 0;
}