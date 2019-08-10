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

int N,M,P;
ll from[2500],to[2500];

vector<pair<int,int>> E[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
	}
	
	FOR(i,N) from[i]=-(1LL<<60);
	from[0]=0;
	ll ma=-1LL<<60;
	FOR(i,10000) {
		FOR(j,N) to[j]=from[j];
		FOR(x,N) if(from[x]>-(1LL<<60)) FORR(e,E[x]) {
			to[e.first]=max(to[e.first],from[x]+e.second-P);
			if(i>=5100&&to[e.first]>from[e.first]) to[e.first]=1LL<<60;
		}
		
		ma=max(ma,to[N-1]);
		swap(from,to);
	}
	ma=max(ma,0LL);
	if(ma>=1LL<<59) ma=-1;
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
