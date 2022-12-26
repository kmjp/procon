#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[2020];
const ll mo=1000000007;
ll p2[2020*2020];
int U[2020][2020];
int D[2020][2020];
int L[2020][2020];
int R[2020][2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,2020*2010) p2[i+1]=p2[i]*2%mo;
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	int sum=0;
	FOR(y,H) {
		FOR(x,W) if(S[y][x]=='.') {
			sum++;
			if(x&&S[y][x-1]=='.') L[y][x]=L[y][x-1]+1;
		}
		for(x=W-1;x>=0;x--) if(S[y][x]=='.') {
			if(x+1<W&&S[y][x+1]=='.') R[y][x]=R[y][x+1]+1;
		}
	}
	FOR(x,W) {
		FOR(y,H) if(S[y][x]=='.') {
			if(y&&S[y-1][x]=='.') U[y][x]=U[y-1][x]+1;
		}
		for(y=H-1;y>=0;y--) if(S[y][x]=='.') {
			if(y+1<H&&S[y+1][x]=='.') D[y][x]=D[y+1][x]+1;
		}
	}
	
	ll ret=0;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		int tot=1+L[y][x]+R[y][x]+U[y][x]+D[y][x];
		(ret+=p2[sum-tot]*(p2[tot]-1)%mo)%=mo;
		
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
