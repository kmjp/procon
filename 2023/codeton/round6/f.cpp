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

int T;
ll N,K;
__int128 L[61],R[61];
ll dfs(ll v) {
	ll num=-v+1;
	ll ov=v;
	//vˆÈ‰º‚ÌŒ…
	ll L=1;
	while(L<=v/K) L*=K;
	ll ol=L;
	while(v) {
		
		v/=K;
		L/=K;
		if(L) num+=v-L+1;
	}
	
	L=ol;
	ll R=ov-1;
	while(L<=R) {
		num+=R-L+1;
		if(L>N/K) break;
		L*=K;
		R=min(N,min(N/K+1,R+1)*K-1);
	}
	return num;
		
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		ll ret=0;
		for(i=1;i<=61;i++) {
			L[i]=R[i-1]+1;
			R[i]=min((__int128)N,L[i]*K-1);
			if(L[i]>N) break;
			
			if(dfs(L[i])>0) continue;
			if(dfs(R[i])<0) continue;
			ll TL=L[i]-1;
			ll TR=L[i]-1;
			for(x=60;x>=0;x--) {
				if(TL+(1LL<<x)<=R[i]&&dfs(TL+(1LL<<x))<0) TL+=1LL<<x;
				if(TR+(1LL<<x)<=R[i]&&dfs(TR+(1LL<<x))<=0) TR+=1LL<<x;
			}
			if(TR>TL) ret+=TR-TL;
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
