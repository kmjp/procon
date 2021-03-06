#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll V,A[20];
int win[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>V;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i];
		sum+=A[i];
	}
	
	if(sum<=V) return _P("Draw\n");
	int mask;
	FOR(mask,1<<N) {
		ll sum=0;
		FOR(i,N) if((mask&(1<<i))==0) sum+=A[i];
		if(sum>V) continue;
		FOR(i,N) if((mask&(1<<i))) {
			if(A[i]+sum>V) continue;
			if(win[mask^(1<<i)]==0) win[mask]=1;
		}
	}
	
	if(win[(1<<N)-1]) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
