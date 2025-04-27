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

using VT = string;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

int C[201010];
int D[201010];

class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
		int H=grid.size(),W=grid[0].size();
        string A,B;
        int y,x,i;
        FOR(y,H) FOR(x,W) A+=grid[y][x];
        FOR(x,W) FOR(y,H) B+=grid[y][x];
        FOR(i,H*W) C[i]=D[i]=0;
        
        A=pattern+"$"+A;
        B=pattern+"$"+B;
        auto ZA=Zalgo(A);
        auto ZB=Zalgo(B);
        FOR(i,H*W) {
			if(ZA[pattern.size()+1+i]>=pattern.size()) C[i]++,C[i+pattern.size()]--;
			if(ZB[pattern.size()+1+i]>=pattern.size()) D[i]++,D[i+pattern.size()]--;
			if(i) {
				C[i]+=C[i-1];
				D[i]+=D[i-1];
			}
		}
		int ret=0;
		FOR(y,H) FOR(x,W) if(C[y*W+x]&&D[x*H+y]) ret++;
		return ret;
        
        
        
    }
};
