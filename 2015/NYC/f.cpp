#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int DIV=10000;
int N,M;
pair<int,int> P[50];
pair<int,int> P2[50];

int ok(ll v) {
	int i;
	FOR(i,M-1) if(P2[i].second/v==P2[i+1].first/v) return 0;
	FOR(i,M) if(P2[i].first/v!=P2[i].second/v) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second, P[i].first--;
	
	FOR(i,N) {
		FOR(x,i) FOR(y,x) if(P[i].second==P[y].second && P[i].second!=P[x].second) return _P("0\n");
		if(i!=0 && P[i].second==P[i-1].second) P2[M-1].second=P[i].first;
		else P2[M++]=make_pair(P[i].first,P[i].first);
	}
	
	if(M==1) return _P("-1\n");
	
	ll ret=0;
	for(i=1;i<=DIV;i++) if(ok(i)) ret++;
	
	vector<int> cand;
	FOR(i,M) {
		ll a=P2[i].first,b=P2[i].second;
		for(int c=1;a/c>=DIV;c++) cand.push_back(a/c);
		for(int c=1;b/c>=DIV;c++) cand.push_back(b/c);
	}
	cand.push_back(DIV);
	sort(cand.begin(),cand.end());
	cand.erase(unique(cand.begin(),cand.end()),cand.end());
	
	FOR(i,cand.size()-1) if(ok(cand[i+1])) ret+=cand[i+1]-cand[i];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
