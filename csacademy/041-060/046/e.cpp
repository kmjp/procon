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

int N,D;
int G[1010101];
ll S[1010101];
int L[1010101];
int R[1010101];

int ok[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	vector<pair<int,int>> cand;
	
	scanf("%d%d",&N,&D);
	FOR(i,N) {
		scanf("%d",&G[i]);
		S[i+1]=S[i]+G[i];
		cand.push_back({G[i],i});
	}
	
	vector<pair<int,int>> V;
	V.push_back({1<<30,-1});
	FOR(i,N) {
		while(V.back().first<=G[i]) V.pop_back();
		L[i]=V.back().second;
		V.push_back({G[i],i});
	}
	V.clear();
	V.push_back({1<<30,N});
	for(i=N-1;i>=0;i--) {
		while(V.back().first<=G[i]) V.pop_back();
		R[i]=V.back().second;
		V.push_back({G[i],i});
	}
	
	sort(ALL(cand));
	reverse(ALL(cand));
	FORR(c,cand) {
		x=c.second;
		if(L[x]==-1 && R[x]==N) {
			ok[x]=1;
		}
		else {
			if(L[x]>=0 && S[R[x]]-S[L[x]+1]+D>=G[L[x]]) ok[x]|=ok[L[x]];
			if(R[x]<N && S[R[x]]-S[L[x]+1]+D>=G[R[x]]) ok[x]|=ok[R[x]];
		}
	}
	FOR(i,N) if(ok[i]) _P("%d ",i+1);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
