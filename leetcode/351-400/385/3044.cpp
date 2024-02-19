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

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
		cprime();
		int y,x;
		int H=mat.size(),W=mat[0].size();
		map<int,int> M;
		FOR(y,H) FOR(x,W) {
			int dy[8]={-1,-1,-1,0,0,1,1,1};
			int dx[8]={-1,0,1,-1,1,-1,0,1};
			int i,v=0;
			FOR(i,8) {
				int cy=y,cx=x;
				int v=0;
				while(cy>=0&&cy<H&&cx>=0&&cx<W) {
					v=v*10+mat[cy][cx];
					if(divp[v]==0&&v>=10) M[v]++;
					cy+=dy[i];
					cx+=dx[i];
				}
				
			}
		}
		int ma=-1;
		FORR(a,M) if(a.second>=M[ma]) ma=a.first;
		
		return ma;
        
    }
};
