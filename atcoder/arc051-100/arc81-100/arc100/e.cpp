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
ll A[1<<18];
vector<ll> V[1<<18];
ll S[1<<18][19];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) {
		cin>>x;
		V[i]={x,0};
	}
	
	FOR(i,N) {
		FOR(x,1<<N) if(x&(1<<i)) {
			V[x].push_back(V[x^(1<<i)][0]);
			V[x].push_back(V[x^(1<<i)][1]);
			sort(ALL(V[x]));
			reverse(ALL(V[x]));
			V[x].resize(2);
		}
	}
	
	ll ma=0;
	for(int k=1;k<=(1<<N)-1;k++) {
		ma=max(ma,V[k][0]+V[k][1]);
		cout<<ma<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
