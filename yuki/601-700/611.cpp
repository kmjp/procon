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
char S[1010][1010];
int A[1010];
ll mo=201712111;

int mi[2020];
int from[1<<18];
int to[1<<18];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	if(S[0][0]=='?') S[0][0]='1';
	if(S[H-1][W-1]=='?') S[H-1][W-1]='1';
	
	if(H<W) {
		FOR(y,max(H,W)) FOR(x,y) swap(S[y][x],S[x][y]);
		swap(H,W);
	}
	
	FOR(y,H) {
		FOR(x,W) {
			if(S[y][x]=='?') A[y*W+x]=1;
			else A[y*W+x]=S[y][x]-'0';
		}
	}
	
	FOR(x,2020) mi[x]=1<<30;
	mi[0]=A[0];
	FOR(y,H) FOR(x,W) {
		int id=y*W+x;
		if(y) mi[id]=min(mi[id],mi[id-W]+A[id]);
		if(x) mi[id]=min(mi[id],mi[id-1]+A[id]);
	}
	
	from[1]=1;
	int bmask=(1<<W)-1,mask;
	FOR(i,H*W-1) {
		ZERO(to);
		FOR(mask,1<<W) {
			int down=(mask>>(W-1)) && (mi[i-W+1]+A[i+1]==mi[i+1]);
			int right=(mask&1) && (i%W!=W-1) && (mi[i]+A[i+1]==mi[i+1]);
			
			if(down|right) {
				(to[(mask*2+1)&bmask] += from[mask])%=mo;
				(to[(mask*2)&bmask]+=from[mask]*((S[(i+1)/W][(i+1)%W]=='?'?8:0)))%=mo;
			}
			else {
				(to[(mask*2)&bmask]+=from[mask]*(1+(S[(i+1)/W][(i+1)%W]=='?'?8:0)))%=mo;
			}
			
		}
		swap(from,to);
	}
	
	ll ret=0;
	for(mask=1;mask<1<<W;mask+=2) ret+=from[mask];
	cout<<mi[H*W-1]<<endl;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
