#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int N;
int W[16][16];
ll win[1<<16][16];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>W[y][x];
	
	FOR(i,N) win[1<<i][i]=1;
	int mask;
	FOR(mask,1<<N) {
		k=__builtin_popcount(mask);
		if(k<2||k&(k-1)) continue;
		for(int sm=mask;sm>=0;sm--) {
			sm&=mask;
			y=__builtin_popcount(sm);
			if(y*2!=k) continue;
			int lef=mask^sm;
			FOR(x,N) if(lef&(1<<x)) {
				FOR(y,N) if(sm&(1<<y)) {
					if(W[x][y]) {
						win[mask][x]+=win[lef][x]*win[sm][y];
					}
					else {
						win[mask][y]+=win[lef][x]*win[sm][y];
					}
				}
			}
			
		}
	}
	FOR(i,N) cout<<win[(1<<N)-1][i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
