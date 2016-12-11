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
int A[10];
int B[10];
int mask[1<<8];
int rev[1<<8];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>r, A[y] |= r<<x;
	
	FOR(i,1<<W) rev[i]=101010;
	FOR(i,1<<W) {
		FOR(x,W) if(i&(1<<x)) {
			if(x) mask[i] ^= 1<<(x-1);
			mask[i] ^= 1<<x;
			if(x<W-1) mask[i] ^= 1<<(x+1);
		}
		rev[mask[i]]=min(rev[mask[i]],__builtin_popcount(i));
	}
	
	int ma=101010;
	FOR(i,1<<W) {
		FOR(y,H) B[y]=A[y];
		B[0] ^= mask[i];
		B[1] ^= mask[i];
		int tot=__builtin_popcount(i);
		for(y=1;y<H;y++) {
			int tar=B[y-1];
			tot+=rev[tar];
			B[y-1] ^= tar;
			B[y] ^= tar;
			B[y+1] ^= tar;
		}
		
		if(B[H-1]==0) ma=min(ma,tot);
	}
	
	if(ma==101010) _P("Impossible\n");
	else _P("%d\n",ma);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
