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

int N,M;
int L[303],R[303],X[303];

ll from[305][305];
ll to[305][305];
ll mo=1000000007;
vector<pair<int,int>> V[305];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>L[i]>>R[i]>>X[i];
		V[R[i]+2].push_back({L[i]+2,X[i]});
	}
	
	from[0][1]=1;
	for(i=3;i<=N+2;i++) {
		ZERO(to);
		FOR(y,N+1) FOR(x,y) if(from[x][y]) {
			int mask=7;
			FORR(r,V[i]) {
				if(r.second==1) {
					if(r.first==i) mask&=7;
					else if(y<r.first) mask&=1;
					else mask=0;
				}
				if(r.second==2) {
					if(x>=r.first) mask=0;
					else if(y<r.first) mask&=6;
					else mask&=3;
				}
				if(r.second==3) {
					if(x>=r.first) mask&=7;
					else if(y>=r.first) mask&=4;
					else mask=0;
				}
			}
			if(mask&1) (to[x][y] += from[x][y])%=mo;
			if(mask&2) (to[x][i-1] += from[x][y])%=mo;
			if(mask&4) (to[y][i-1] += from[x][y])%=mo;
		}
		
		swap(from,to);
	}
	
	ll tot=0;
	FOR(i,N+3) FOR(j,N+3) tot+=from[i][j];
	cout<<tot%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
