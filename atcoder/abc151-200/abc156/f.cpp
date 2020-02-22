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


int K,Q;
int D[5050],E[5050];
ll N,X,M,S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>Q;
	FOR(i,K) cin>>D[i];
	while(Q--) {
		cin>>N>>X>>M;
		ll S=0;
		ll num0=0;
		FOR(i,K) {
			E[i]=D[i]%M;
			S+=E[i];
			if(E[i]==0) num0++;
		}
		ll Y=X+(N-1)/K*S;
		num0*=(N-1)/K;
		FOR(i,(N-1)%K) {
			Y+=E[i];
			if(E[i]==0) num0++;
		}
		ll rev=(Y/M-X/M);
		cout<<N-1-rev-num0<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
