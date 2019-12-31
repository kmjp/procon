#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,S;
int ret,cur,tim;
pair<int,int> P[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	FOR(i,N) {
		if(cur>=M) ret+=P[i].first-tim;
		tim=P[i].first;
		cur+=P[i].second;
	}
	if(cur>=M) ret+=S-tim;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
