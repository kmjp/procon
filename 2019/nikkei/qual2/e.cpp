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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll A=0,B=0;
	FOR(i,2*N) A+=K+i;
	FOR(i,N) B+=K+2*N+i;
	if(B<A) return _P("-1\n");
	vector<vector<int>> R;
	set<int> V;
	if(N%2==0) {
		if(K>N/2) return _P("0\n");
		int TK=N/2;
		R.push_back({TK,3*TK,5*TK});
		for(i=1;i<=N/2;i++) R.push_back({TK+i,2*N+i-1,TK+i+2*N+i-1});
		for(i=1;i<=N/2-1;i++) R.push_back({N+i,3*N/2+i,5*N/2+2*i});
		FORR(r,R) {
			FORR(a,r) {
				a-=TK-K;
				V.insert(a);
			}
			assert(r[0]+r[1]<=r[2]);
		}
	}
	else {
		if(K>N/2+1) return _P("0\n");
		int TK=N/2+1;
		for(i=1;i<=N/2+1;i++) R.push_back({TK+i-1,2*N+i-1,TK+i+2*N+i-2});
		for(i=1;i<=N/2;i++) R.push_back({N+i,3*N/2+i,5*N/2+2*i});
		FORR(r,R) {
			FORR(a,r) {
				a-=TK-K;
				V.insert(a);
			}
			assert(r[0]+r[1]<=r[2]);
		}
	}
	assert(V.size()==3*N);
	assert(*V.begin()==K);
	assert(*V.rbegin()==K+3*N-1);
	
	
	FORR(v,R) {
		cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
