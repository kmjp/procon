#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W,K,M;
string S[1010];
int L[2010][2010];
int R[2010][2010];
int D[2010][2010];
int LS[2010][2010];
int RS[2010][2010];
int DS[2010][2010];
const ll mo=1000000007;


ll range(int sy,int sx,int ty,int tx) {
	ll L2=LS[ty][tx]-LS[sy][tx]-LS[ty][sx]+LS[sy][sx];
	ll R2=RS[ty][tx]-RS[sy][tx]-RS[ty][sx]+RS[sy][sx];
	ll D2=DS[ty][tx]-DS[sy][tx]-DS[ty][sx]+DS[sy][sx];
	
	ll ret=0;
	// DDDD
	ret+=D2*(D2-1)*(D2-2)%mo*(D2-3)%mo;
	// DDDR
	ret+=2*R2*D2%mo*(D2-1)%mo*(D2-2)%mo;
	// DDRR
	ret+=R2*(R2-1)%mo*D2%mo*(D2-1)%mo;
	// LDDD
	ret+=2*L2*D2%mo*(D2-1)%mo*(D2-2)%mo;
	// LDDR
	ret+=4*L2*R2%mo*D2%mo*(D2-1)%mo;
	// LDRR
	ret+=2*L2*R2%mo*D2%mo*(R2-1)%mo;
	// LLDD
	ret+=L2*(L2-1)%mo*D2%mo*(D2-1)%mo;
	// LLDR
	ret+=2*L2*(L2-1)%mo*D2%mo*R2%mo;
	// LLRR
	ret+=L2*(L2-1)%mo*R2%mo*(R2-1)%mo;
	
	return ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	
	FOR(y,H-1) {
		FOR(x,W) if(S[y][x]=='0'&&S[y+1][x]=='1') {
			if(x&&S[y][x-1]=='1') L[y][x]=1;
			if(S[y][x+1]=='1') R[y][x]=1;
			
			if(L[y][x]&&R[y][x]) {
				D[y][x]=1;
				L[y][x]=R[y][x]=0;
			}
		}
	}
	
	FOR(y,2005) FOR(x,2005) {
		LS[y+1][x+1]=LS[y][x+1]+LS[y+1][x]-LS[y][x]+L[y][x];
		RS[y+1][x+1]=RS[y][x+1]+RS[y+1][x]-RS[y][x]+R[y][x];
		DS[y+1][x+1]=DS[y][x+1]+DS[y+1][x]-DS[y][x]+D[y][x];
	}
	
	ll ret=0;
	FOR(y,H) FOR(x,W) {
		ret+=range(y,x,y+K,x+K);
		ret+=mo-range(y+1,x,y+K,x+K);
		ret+=mo-range(y,x+1,y+K,x+K);
		ret+=range(y+1,x+1,y+K,x+K);
		ret%=mo;
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
