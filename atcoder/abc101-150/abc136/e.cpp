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
int A[505];
int S;

int hoge(int v) {
	vector<ll> V;
	vector<ll> SS;
	int i;
	FOR(i,N) V.push_back(A[i]%v);
	sort(ALL(V));
	SS.push_back(0);
	FORR(v,V) SS.push_back(SS.back()+v);
	
	FOR(i,N) {
		ll A=SS[i];
		ll B=(N-i)*1LL*v-(SS[N]-SS[i]);
		
		if(max(A,B)<=K) return 1;
	}
	return 0;
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	int ret=0;
	for(x=1;x*x<=S;x++) if(S%x==0) {
		if(hoge(x)) ret=max(ret,x);
		if(hoge(S/x)) ret=max(ret,S/x);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
