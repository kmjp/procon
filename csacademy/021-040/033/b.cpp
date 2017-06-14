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
int A[101][101];
set<int> S[101];
pair<int,int> P[101];
int ret[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		P[y].second=y;
		FOR(x,N) {
			cin>>A[y][x];
			S[y].insert(A[y][x]);
		}
		sort(A[y],A[y]+N);
	}
	FOR(y,N) FOR(x,y) {
		int mi=101010,ma=-1;
		FORR(r,S[x]) if(S[y].count(r)) {
			mi=min(mi,r);
			ma=max(ma,r);
		}
		int C[2]={};
		FOR(i,N) if(A[x][i]<mi || ma<A[x][i]) C[0]++;
		FOR(i,N) if(A[y][i]<mi || ma<A[y][i]) C[1]++;
		
		if(C[0]==C[1]) P[x].first--,P[y].first--;
		if(C[0]>C[1]) P[x].first-=2;
		if(C[0]<C[1]) P[y].first-=2;
	}
	
	sort(P,P+N);
	FOR(i,N) cout<<P[i].second+1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
