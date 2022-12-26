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

int H,W,K;
int B[3030][3030];
int D[3030][3030];
int U[3030][3030];
int RD[3030][3030];
int LU[3030][3030];
int X[3030][3030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) B[y][x]=1;
	FOR(i,K) {
		cin>>y>>x;
		B[y-1][x-1]=0;
	}
	int ma=0;
	set<int> Q[6060];
	
	for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) if(B[y][x]) {
		D[y][x]=1+D[y+1][x];
		RD[y][x]=1+RD[y+1][x+1];
	}
	
	FOR(y,H) FOR(x,W) if(B[y][x]) {
		U[y][x]=LU[y][x]=1;
		if(y) U[y][x]+=U[y-1][x];
		if(y&&x) LU[y][x]+=LU[y-1][x-1];
		X[y][x]=min(U[y][x],LU[y][x]);
		//if(min(D[y][x],RD[y][x])<=ma) continue;
		i=y-x+3000;
		Q[i].insert(y);
		if(X[y][x]<=ma) continue;
		auto it=Q[i].lower_bound(y-X[y][x]+1);
		while(1) {
			int ty=*it;
			int tx=x+(ty-y);
			if(ty+min(D[ty][tx],RD[ty][tx])-1>=y) {
				ma=max(ma,y-ty+1);
				break;
			}
			it=Q[i].erase(it);
		}
		
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
