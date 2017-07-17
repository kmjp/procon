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
int sc[101];
vector<int> V[303];
int ret[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N*(N-1)/2) {
		cin>>x>>y>>j>>k;
		if(j>k) sc[x-1]+=3;
		if(j<k) sc[y-1]+=3;
		if(j==k) sc[x-1]++,sc[y-1]++;
	}
	FOR(i,N) V[sc[i]].push_back(i);
	int cur=1;
	for(i=300;i>=0;i--) {
		FORR(e,V[i]) ret[e]=cur;
		cur+=V[i].size();
	}
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
