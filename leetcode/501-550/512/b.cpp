#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> V;
        int N1=series1.size(),N2=series2.size();
        int L=0,R=0;
        while(L<N1||R<N2) {
			int nex=1<<30;
			int num=0;
			if(L<N1) {
				nex=min(nex,series1[L][0]);
				num+=series1[L][1];
			}
			if(R<N2) {
				nex=min(nex,series2[R][0]);
				num+=series2[R][1];
			}
			V.push_back({nex,num});
			if(L<N1&&series1[L][0]==nex) L++;
			if(R<N2&&series2[R][0]==nex) R++;
		}
		return V;
    }
};


