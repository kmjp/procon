#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,L;
set<int> SS[1000200];
pair<int,int> P[100200],S[200];
int mask[100200][21],mask2[20];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	FOR(i,N) SS[P[i].second].insert(P[i].first);
	sort(P,P+N);
	FOR(i,N) {
		for(y=-9;y<=9;y++) {
			FOR(x,10) mask[i][10+y] |= (SS[P[i].second+y].find(P[i].first+x)!=SS[P[i].second+y].end())<<x;
		}
	}
	
	while(M--) {
		cin>>L;
		FOR(i,L) cin>>S[i].first>>S[i].second;
		sort(S,S+L);
		for(i=L-1;i>=0;i--) S[i].first-=S[0].first;
		int mix=99999999,miy=99999999;
		FOR(i,L) mix=min(mix,S[i].first),miy=min(miy,S[i].second);
		ZERO(mask2); 
		FOR(i,L) mask2[S[i].second-miy] |= 1<<(S[i].first-mix);
		
		int ret=0;
		FOR(i,N) {
			int ok=1;
			FOR(y,10) if((mask[i][10-(S[0].second-miy)+y] & mask2[y])!=mask2[y]) ok=0;
			ret+=ok;
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
