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
ll K[303030],L[303030],D[303030];

ll hoge(ll v) {
	ll tot=0;
	int i;
	FOR(i,N) if(v>=L[i]) {
		if(L[i]+(K[i]-1)*D[i]<=v) {
			tot+=K[i];
		}
		else {
			tot+=1+(v-L[i])/D[i];
		}
	}
	return tot;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>K[i]>>L[i]>>D[i];
		D[i]=1LL<<D[i];
	}
	
	ll ma=-1;
	for(i=60;i>=0;i--) if(hoge(ma+(1LL<<i))%2==0) ma+=1LL<<i;
	cout<<ma+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
