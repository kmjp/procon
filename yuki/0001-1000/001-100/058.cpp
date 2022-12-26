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

int N,K;
int cnt[11][67],cnt2[11][67];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>K;
	
	cnt[0][0]=cnt2[0][0]=1;
	FOR(i,N) {
		FOR(j,N*6) {
			for(k=1;k<=6;k++) cnt[i+1][j+k]+=cnt[i][j];
			if(i<N-K) {
				for(k=1;k<=6;k++) cnt2[i+1][j+k]+=cnt2[i][j];
			}
			else {
				for(k=4;k<=6;k++) cnt2[i+1][j+k]+=2*cnt2[i][j];
			}
		}
	}
	
	ll win=0,tot=0;
	FOR(i,61) FOR(j,61) if(j>i) win+=cnt[N][i]*(ll)cnt2[N][j];
	FOR(i,61) FOR(j,61) tot+=cnt[N][i]*(ll)cnt2[N][j];
	
	_P("%.12lf\n",win*1.0/tot);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
