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
vector<int> V[3];

int ok(int val) {
	int num=0;
	ll sum=0;
	FORR(v,V[0]) {
		sum+=v;
		if(sum>val*10-K) break;
		num++;
	}
	sum=0;
	FORR(v,V[1]) {
		sum+=v;
		if(sum>val*7-K) break;
		num++;
	}
	sum=0;
	FORR(v,V[2]) {
		sum+=v;
		if(sum>val*7-K) break;
		num++;
	}
	return num>=K;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>j>>k>>r;
		if(j>1) V[0].push_back(j-1);
		else if(k>1) V[1].push_back(k-1);
		else V[2].push_back(r-1);
	}
	FOR(i,3) sort(ALL(V[i]));
	
	int ret=1<<25;
	for(i=24;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
