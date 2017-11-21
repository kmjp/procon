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
vector<ll> V[60];
ll P;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P;
		x=0;
		while((1LL<<x)<=P) x++;
		V[x-1].push_back(P);
	}
	vector<ll> pre;
	ll ret=0;
	for(i=59;i>=1;i--) {
		vector<ll> nex;
		sort(ALL(V[i]));
		x=y=0;
		while(x<pre.size() || y<V[i].size()) {
			if(x==pre.size()) {
				ret++;
				nex.push_back(V[i][y++]>>1);
			}
			else if(y==V[i].size()) {
				ret++;
				nex.push_back(pre[x++]>>1);
			}
			else {
				if(pre[x]==V[i][y]) {
					ret++;
					nex.push_back(pre[x++]>>1);
					y++;
				}
				else if(pre[x]<V[i][y]) {
					ret++;
					nex.push_back(pre[x++]>>1);
				}
				else {
					ret++;
					nex.push_back(V[i][y++]>>1);
				}
			}
		}
		nex.erase(unique(ALL(nex)),nex.end());
		pre=nex;
		
		V[i].clear();
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
