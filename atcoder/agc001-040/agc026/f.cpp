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
int A[303030];
ll B[303030];
ll S[2];
int ok(ll v) {
	int i;
	FOR(i,N) B[i]=A[i];
	for(int cur=N-1;cur>0;cur-=2) if(B[cur]<v || B[cur-1]<B[cur]) B[cur-2]+=B[cur]-B[cur-1];
	return B[0]>=v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i%2]+=A[i];
	}
	if(N%2==0) {
		cout<<max(S[0],S[1])<<" "<<min(S[0],S[1])<<endl;
		return;
	}
	
	ll Z=-1LL<<40;
	for(i=40;i>=0;i--) if(ok(Z+(1LL<<i))) Z+=1LL<<i;
	
	cout<<(S[1]+Z)<<" "<<(S[0]-Z)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
