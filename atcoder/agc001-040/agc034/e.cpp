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
string S;
vector<int> E[2020];
int SD[2020];
int lef;

void dfs(int cur,int pre,int id,int d) {
	if(S[cur]=='1') SD[id]+=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,id,d+1);
	
}

pair<int,int> can(int cur,int pre) {
	pair<int,int> P={0,0};
	
	if(S[cur]=='1') P.first=1;
	FORR(e,E[cur]) if(e!=pre) {
		auto Q=can(e,cur);
		Q.second+=Q.first;
		int mi=min(Q.second,P.second);
		lef-=mi;
		Q.second-=mi;
		P.second-=mi;
		P.first+=Q.first;
		P.second+=Q.second;
	}
	return P;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>S;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	int mi=1<<30;
	FOR(x,N) {
		ZERO(SD);
		FORR(e,E[x]) dfs(e,x,e,1);
		int sum=0;
		FOR(y,N) sum+=SD[y];
		
		if(sum%2) continue;
		int ma=*max_element(SD,SD+N);
		if(ma*2<=sum) {
			mi=min(mi,sum/2);
			continue;
		}
		y=max_element(SD,SD+N)-SD;
		lef=(ma-(sum-ma))/2;
		can(y,x);
		if(lef<=0) mi=min(mi,sum/2);
	}
	if(mi==1<<30) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
