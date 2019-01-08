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

int N,M;
vector<int> E[101010];
int in[101010];
int cur[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		in[y]++;
	}
	
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	int ma=0;
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		
		cur[x]++;
		ma=max(ma,cur[x]);
		FORR(e,E[x]) {
			cur[e]=max(cur[e],cur[x]);
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	cout<<ma-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
