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

int F[4][4];
int T[4][4];

class Solution {
public:
    int minFlips(string s) {
        int x,y;
        FOR(x,4) FOR(y,4) F[x][y]=1<<20;
        F[0][0]=0;
        FORR(c,s) {
			FOR(x,3) FOR(y,3) T[x][y]=1<<20;
			FOR(x,3) FOR(y,3) {
				
				// 0
				{
					int nx=x,ny=y;
					if(x==0) nx++;
					if(y==2) ny++;
					if(nx<3&&ny<3) T[nx][ny]=min(T[nx][ny],F[x][y]+(c=='1'));
				}
				
				// 1
				{
					int nx=x,ny=y;
					if(x!=0) nx++;
					if(y!=2) ny++;
					if(nx<3&&ny<3) T[nx][ny]=min(T[nx][ny],F[x][y]+(c=='0'));
				}
				
			}
			swap(F,T);
		}
		int ret=1<<20;
		FOR(x,3) FOR(y,3) ret=min(ret,F[x][y]);
		return ret;
    }
};
