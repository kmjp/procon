#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int SC[202020];
int num[202020][31];

set<int> S[202020];
int C[202020];
int N,X,Q;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Q;
	FOR(i,N) {
		C[i]=i;
		S[i].insert(i);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			int a=C[x];
			int b=C[X];
			int p=x,q=X;
			if(S[a].size()<S[b].size()) swap(a,b),swap(p,q);
			int t=SC[p]^SC[q]^y;
			FORR(c,S[b]) {
				C[c]=a;
				SC[c]^=t;
				FOR(j,30) if(SC[c]&(1<<j)) num[a][j]++;
				S[a].insert(c);
			}
			S[b].clear();
		}
		else if(i==2) {
			cin>>x>>y;
			if(C[x]!=C[y]) {
				cout<<-1<<endl;
			}
			else {
				i=SC[x]^SC[y];
				cout<<i<<endl;
				X=(X+i)%N;
			}
		}
		else if(i==3) {
			cin>>x;
			ll ret=0;
			x=C[x];
			y=S[x].size();
			FOR(i,30) {
				ll a=1LL*num[x][i]*(y-num[x][i])%mo;
				(ret+=a<<i)%=mo;
			}
			cout<<ret<<endl;
			
		}
		else if(i==4) {
			cin>>x;
			X=(X+x)%N;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
