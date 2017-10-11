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
string S[101];
int cnt[256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) cnt[c-'a']++;
	}
	int p1=0,p2=0,p4=0;
	if(H%2 && W%2) {
		p1=1;
		p2=((H-1)+(W-1))/2;
	}
	else if(H%2) {
		p2=W/2;
	}
	else if(W%2) {
		p2=H/2;
	}
	
	p4=(H*W-p1-p2*2)/4;
	
	while(p4) {
		FOR(i,26) if(cnt[i]>=4) {
			cnt[i]-=4;
			p4--;
			break;
		}
		if(i==26) return _P("No\n");
	}
	while(p2) {
		FOR(i,26) if(cnt[i]>=2) {
			cnt[i]-=2;
			p2--;
			break;
		}
		if(i==26) return _P("No\n");
	}
	while(p1) {
		FOR(i,26) if(cnt[i]>=1) {
			cnt[i]-=1;
			p1--;
			break;
		}
		if(i==26) return _P("No\n");
	}
	_P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
