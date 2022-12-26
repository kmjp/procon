#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[505];
int dp[501][501][501];
int U[10101],D[10101],L[10101],R[10101];
ll ret[10101];

int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	cin>>Q;
	FOR(i,Q) {
		cin>>U[i]>>L[i]>>D[i]>>R[i];
		U[i]--,D[i]--,L[i]--,R[i]--;
	}
	FOR(y,H) {
		FOR(x,W) {
			int nc=0, ncw=0, ncww=0;
			int nw=0, nww=0, nwwc=0;
			for(int z=x;z<W;z++) {
				if(S[y][z]=='c') {
					nc++;
					nwwc+=nww;
				}
				else {
					ncww+=ncw, ncw+=nc;
					nww+=nw, nw++;
				}
				dp[y][x][z]=ncww+nwwc;
			}
		}
	}
	FOR(i,Q) {
		for(y=U[i];y<=D[i];y++) ret[i]+=dp[y][L[i]][R[i]];
	}

	FOR(x,W) {
		FOR(y,H) {
			int nc=0, ncw=0, ncww=0;
			int nw=0, nww=0, nwwc=0;
			for(int z=y;z<H;z++) {
				if(S[z][x]=='c') {
					nc++;
					nwwc+=nww;
				}
				else {
					ncww+=ncw, ncw+=nc;
					nww+=nw, nw++;
				}
				dp[x][y][z]=ncww+nwwc;
			}
		}
	}
	
	FOR(i,Q) {
		for(x=L[i];x<=R[i];x++) ret[i]+=dp[x][U[i]][D[i]];
		cout<<ret[i]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
