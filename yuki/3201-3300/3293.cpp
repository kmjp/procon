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

int H,W;
ll K;
ll A[1010][1010],B[1010][1010];
ll R[1010],C[1010];
vector<int> RC[1010];
vector<int> CC[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		R[y]+=A[y][x];
		C[x]+=A[y][x];
	}
	FOR(y,H) FOR(x,W) {
		cin>>B[y][x];
		RC[y].push_back(B[y][x]);
		CC[x].push_back(B[y][x]);
	}
	FOR(y,H) sort(ALL(RC[y]));
	FOR(x,W) sort(ALL(CC[x]));
	ll ret=0;
	FOR(y,H) FOR(x,W) {
		ll X=A[y][x];
		ll Y=R[y]-X;
		ll Z=C[x]-X;
		int YC=RC[y][0];
		int ZC=CC[x][0];
		int XC=B[y][x];
		if(YC==XC) YC=RC[y][1];
		if(ZC==XC) ZC=CC[x][1];
		
		FOR(i,2) {
		
			if(XC<=YC&&XC<=ZC) {
				ll add=K>>XC;
				ret=max(ret,(X+add+Y)*(X+add+Z));
			}
			else if(XC>=YC+ZC) {
				// Y‚ÆZ
				vector<ll> cand={0,K>>YC};
				ll TY=(((X+Z)<<ZC)+K-((X+Y)<<YC))>>(1+YC);
				cand.push_back(TY-1);
				cand.push_back(TY);
				cand.push_back(TY+1);
				FORR(ty,cand) if(ty>=0&&((ty<<YC)<=K)) {
					ll tz=(K-(ty<<YC))>>ZC;
					ret=max(ret,(X+ty+Y)*(X+tz+Z));
				}
				
			}
			else if(XC>YC) {
				// X‚ÆY
				vector<ll> cand={0,K>>XC};
				ll TX=(((X+Z)<<YC)+K-((X+Y)*((1LL<<XC)-(1LL<<YC))))/(2*((1LL<<XC)-(1LL<<YC)));
				cand.push_back(TX-1);
				cand.push_back(TX);
				cand.push_back(TX+1);
				FORR(tx,cand) if(tx>=0&&((tx<<XC)<=K)) {
					ll ty=(K-(tx<<XC))>>YC;
					ret=max(ret,(X+tx+Y+ty)*(X+tx+Z));
				}
				
			}
			swap(Y,Z);
			swap(YC,ZC);
		}
		
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
