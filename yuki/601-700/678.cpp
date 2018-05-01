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

int N,L,R;
int mp[3030][3030];
int is[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(mp);
	cin>>N>>L>>R;
	FOR(i,N) {
		int LL,UU,RR,DD;
		cin>>LL>>UU>>RR>>DD;
		LL=max(L,LL);
		RR=min(R,RR);
		
		for(x=LL;x<=RR;x++) mp[DD][x]=i;
	}
	
	for(x=L;x<=R;x++) {
		for(y=2160;y>=0;y--) {
			if(mp[y][x]>=0) {
				is[mp[y][x]]=1;
				break;
			}
		}
	}
	FOR(i,N) cout<<is[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
