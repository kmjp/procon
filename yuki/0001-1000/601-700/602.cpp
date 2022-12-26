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
ll D[101010];
ll X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	cin>>x>>y;
	X=abs(x)+abs(y);
	int d=X%2;
	sort(D,D+N);
	
	int mi=3;
	if(X==0) mi=0;
	
	ll P[2]={-1,-1};
	FOR(i,N) {
		if(D[i]==X) mi=min(mi,1);
		P[D[i]%2]=D[i];
		ll c=P[d^(D[i]%2)];
		if(abs(D[i]-X)<=c) mi=min(mi,2);
	}
	if(mi==3) mi=-1;
	
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
