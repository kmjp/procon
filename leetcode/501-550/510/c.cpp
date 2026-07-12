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
    vector<string> createGrid(int r, int c, int k) {
        vector<string> V;
        int y,x;
        FOR(y,r) {
			V.push_back(string(c,'#'));
		}
		
		if(k==1) {
			FOR(y,r) V[y][c-1]='.';
			FOR(x,c) V[0][x]='.';
		}
		else if(k==2) {
			if(r==1||c==1) return {};
			FOR(y,r) V[y][c-1]='.';
			FOR(x,c) V[0][x]='.';
			V[1][c-2]='.';
		}
		else if(k==3) {
			if(r==1||c==1) return {};
			if(r<=2&&c<=2) return {};
			FOR(y,r) V[y][c-1]='.';
			FOR(x,c) V[0][x]='.';
			V[1][c-2]='.';
			if(r>=3) V[2][c-2]='.';
			else V[1][c-3]='.';
		}
		else if(k==4) {
			if(r==1||c==1) return {};
			FOR(y,r) V[y][c-1]='.';
			FOR(x,c) V[0][x]='.';
			V[1][c-2]='.';
			if(r>=4) {
				V[2][c-2]='.';
				V[3][c-2]='.';
			}
			else if(c>=4) {
				V[1][c-3]='.';
				V[1][c-4]='.';
			}
			else if(r>=3&&c>=3) {
				V={
					"..#",
					"...",
					"#..",
				};
			}
			else {
				return {};
			}
		}
		return V;
		
        
    }
};


