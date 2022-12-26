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

int N,M,K;
int A[101010];

int ok(int ID) {
	if(ID<0) return 0;
	int T=K+A[ID];
	vector<int> V;
	int i;
	FOR(i,N) if(i!=ID) V.push_back(A[i]);
	
	int ret=0;
	int L=0,R=V.size()-1;
	while(L<R) {
		while(L<R && V[R]+V[L]<=T) L++;
		if(L>=R) break;
		ret++;
		L++,R--;
	}
	return ret<M;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	cin>>K;
	FOR(i,N-1) cin>>A[i];
	N--;
	sort(A,A+N);
	int R=N-1;
	if(ok(R)==0) return _P("-1\n");
	
	for(i=20;i>=0;i--) if(ok(R-(1<<i))) R-=1<<i;
	cout<<A[R]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
