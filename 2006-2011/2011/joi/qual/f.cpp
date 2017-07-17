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

int H,W;
string S;
ll ret=1;
int from[1<<20][2];
int to[1<<20][2];
int mo=100000;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	from[0][0]=1;
	
	ll ret=1;
	FOR(y,H) {
		FOR(i,1<<W) from[i][0]+=from[i][1], from[i][1]=0;
		cin>>S;
		FOR(x,W) {
			ZERO(to);
			int curm=~(1<<x);
			if(S[x]=='?') ret=ret*3%mo;
			
			for(int mask=0;mask<1<<(W-1);mask++) {
				int nmask = mask & curm;
				if(S[x]=='?' || S[x]=='J') {
					(to[nmask][1] += from[mask][0]+from[mask][1])%=mo;
				}
				if(S[x]=='?' || S[x]=='O') {
					if(x) (to[nmask|(1<<(x-1))][0]+=from[mask][1])%=mo;
					(to[nmask][0]+=from[mask][0])%=mo;
				}
				if(S[x]=='?' || S[x]=='I') {
					if((mask & (1<<x))==0) {
						(to[nmask][0] += from[mask][0]+from[mask][1])%=mo;
					}
				}
			}
			swap(from,to);
		}
	}
	
	FOR(i,1<<(W-1)) ret-=from[i][0]+from[i][1];
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
