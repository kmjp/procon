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
vector<int> E[101];

int col=100;
ll num=0;

int V[105];

void dfs(int cur,int pre,int d) {
	int n=0;
	FORR(e,E[cur]) if(e!=pre) {
		n++;
		dfs(e,cur,d+1);
	}
	V[d]=max(V[d],n);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==2) {
		cout<<1<<" "<<2<<endl;
		return;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	
	FOR(i,N) {
		ZERO(V);
		dfs(i,i,0);
		
		int tc=0;
		ll tot=1;
		FOR(tc,101) {
			if(V[tc]==0) break;
			tot*=V[tc];
		}
		if(tc<col) col=tc, num=1LL<<62;
		if(tc==col) num=min(num,tot);
	}
	FOR(i,N) {
		FORR(e,E[i]) if(e>i) {
			ZERO(V);
			dfs(i,e,0);
			dfs(e,i,0);
			
			int tc=0;
			ll tot=2;
			FOR(tc,102) {
				if(V[tc]==0) break;
				tot*=V[tc];
			}
			
			if(tc<col) col=tc, num=1LL<<62;
			if(tc==col) num=min(num,tot);
		}
	}
	
	
	cout<<col+1<<" "<<num<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
