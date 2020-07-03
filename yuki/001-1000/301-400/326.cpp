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

int N,K;
int X[500],Y[500];
int A[5050],B[5050];
int P[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) P[i]=i;
	FOR(i,K) {
		cin>>x>>y;
		swap(P[x-1],P[x]);
	}
	vector<pair<int,int> > R;
	FOR(i,N) cin>>x, A[x-1]=i;
	FOR(i,N) {
		for(x=i;x<N;x++) if(P[x]==A[i]) break;
		for(y=x-1;y>=i;y--) {
			swap(P[y],P[y+1]);
			R.push_back({y+1,y+2});
		}
	}
	_P("%d\n",R.size());
	FORR(r,R) _P("%d %d\n",r.first,r.second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
