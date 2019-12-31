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

int N;
int A[32][32];
double P;

int win[32];
double dp[32][32];
double from[32],to[32];
double dpwin[32][32];

void solve() {
	int i,j,k,l,r,x,y; string s; char c;
	
	cin>>N>>x>>c>>y;
	P=x*1.0/y;
	vector<pair<int,int>> V;
	FOR(y,N) {
		FOR(x,N) cin>>A[y][x], win[y]+=A[y][x];
		V.push_back({-win[y],y});
	}
	sort(ALL(V));
	reverse(ALL(V));
	
	FOR(y,N) {
		ZERO(from);
		from[0]=1;
		FOR(x,N) {
			cin>>A[y][x];
			win[y]+=A[y][x];
			if(y==x) continue;
			ZERO(to);
			FOR(i,30) if(from[i]) {
				if(A[y][x]==1) to[i+1]+=from[i]*P,to[i]+=from[i]*(1-P);
				if(A[y][x]==0) to[i+1]+=from[i]*(1-P),to[i]+=from[i]*P;
			}
			swap(from,to);
		}
		FOR(x,N) dp[y][x]=from[x];
	}
	
	FOR(x,N) dpwin[V.front().second][x]=dp[V.front().second][x];
	FOR(i,N-1) {
		int pre=V[i].second;
		int cur=V[i+1].second;
		
		FOR(x,N) FOR(y,N) {
			if(x>y) continue;
			if(x==y && cur>pre) continue;
			dpwin[cur][y] += dpwin[pre][x] * dp[cur][y];
		}
	}
	
	double tot=0;
	FOR(i,N+1) tot+=dpwin[V.back().second][i];
	_P("%.12lf\n",tot);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
