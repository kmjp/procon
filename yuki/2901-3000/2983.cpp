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
ll K,mo;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll p2[30];
ll sc[30];

ll ret;

void dfs(int mask_filled,int mask_cand) {
	int nf=0;
	int y,x,i;
	int d[]={0,1,0,-1};
	FOR(y,H) FOR(x,W) {
		//‚à‚¤–„‚Ü‚Á‚Ä‚é
		if(mask_filled&(1<<(y*W+x))) {
			nf++;
			continue;
		}
		int ok=0;
		FOR(i,4) {
			int ty=y+d[i];
			int tx=x+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			//—×‚ª–„‚Ü‚Á‚Ä‚¢‚é‚È‚çok
			if(mask_filled&(1<<(ty*W+tx))) {
				nf++;
				ok=1;
				break;
			}
		}
		//–„‚ß‚é‚±‚Æ‚Í•s‰Â
		if(mask_cand&(1<<(y*W+x))) continue;
		if(ok) {
			mask_cand |= (1<<(y*W+x));
			dfs(mask_filled | (1<<(y*W+x)), mask_cand);
		}
	}
	
	
	ret+=p2[H*W-nf]*sc[__builtin_popcount(mask_filled)]%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>mo;
	
	p2[0]=1;
	FOR(i,25) p2[i+1]=p2[i]*2%mo;
	FOR(i,26) sc[i]=modpow(i,K);
	
	ll weight=0;
	for(i=1;i<=H*W;i++) (weight+=modpow(i))%=mo;
	(weight*=modpow(1<<(H*W)))%=mo;
	
	FOR(i,H*W) dfs(1<<i,(1<<(i+1))-1);
	
	ret=ret%mo*weight%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
