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



int S[202][202];
int C[202][202];
vector<pair<int,int>> V[202];

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int H=matrix.size();
        int W=matrix[0].size();
        int y,x,i;
        FOR(i,202) V[i].clear();
        ZERO(S);
        ZERO(C);
        
        FOR(y,H) FOR(x,W) V[matrix[y][x]].push_back({y,x});
        
        int ret=0;
        for(i=200;i>0;i--) {
			FORR2(y,x,V[i]) {
				int sum=S[min(H,y+i+1)][min(W,x+i+1)]+S[max(0,y-i)][max(0,x-i)]-S[min(H,y+i+1)][max(0,x-i)]-S[max(0,y-i)][min(W,x+i+1)];
				if(y-i>=0&&x-i>=0) sum-=C[y-i][x-i];
				if(y-i>=0&&x+i<W) sum-=C[y-i][x+i];
				if(y+i<H&&x-i>=0) sum-=C[y+i][x-i];
				if(y+i<H&&x+i<W) sum-=C[y+i][x+i];
				if(sum==0) ret++;
				
			}
			FORR2(y,x,V[i]) C[y][x]++;
			
			FOR(y,H) FOR(x,W) {
				S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x]+C[y][x];
			}
		}
        
		return ret;
    }
};

