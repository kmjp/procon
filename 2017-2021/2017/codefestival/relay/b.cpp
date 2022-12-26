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

ll N,Q;
ll V,W;
ll level[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	int ma=0;
	level[0]=1;
	if(N>1) {
		ll cur=1;
		while(level[ma]<=1LL<<30) {
			level[ma+1]=level[ma]+cur;
			ma++;
			cur*=N;
		}
	}
	
	while(Q--) {
		cin>>V>>W;
		if(N==1) {
			V=min(V,W);
		}
		else {
			while(V!=W) {
				if(V>W) swap(V,W);
				x=lower_bound(level,level+ma,W+1)-level-1;
				W=(W-level[x])/N+level[x-1];
			}
		}
		cout<<V<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
