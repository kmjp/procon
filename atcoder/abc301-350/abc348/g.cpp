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

int N;
pair<ll,ll> P[202020];


vector<ll> max_plus_conv(vector<ll>& A,vector<ll>& B) {
	// C[i]=max(A[x]+B[i-x]) BÇÕè„Ç…ì ÅAABãtÇæÇ∆É_ÉÅ
	int N=A.size(),M=B.size();
	vector<ll> C(N+M-1,-1LL<<60);
	
	auto get=[&](int a,int b) {
		if(a<0||a>=N+M||b<0||b>=N||a-b<0||a-b>=M) return -1LL<<60;
		return A[b]+B[a-b];
	};
	
	auto dfs=[&](auto self,int NL,int NR,int ML,int MR) {
		if(NL>=NR||ML>=MR) return;
		int NM=(NL+NR)/2;
		int TM=ML;
		ll TV=-1LL<<60;
		for(int x=ML;x<MR;x++) {
			ll v=get(NM,x);
			if(chmax(TV,v)) TM=x;
		}
		C[NM]=TV;
		self(self,NL,NM,ML,TM+1);
		self(self,NM+1,NR,TM,MR);
	};
	
	
	dfs(dfs,0,N+M-1,0,N);
	return C;
	
}

pair<vector<ll>,vector<ll>> dfs(int L,int R) {
	vector<ll> As(R-L+1,-1LL<<60),ABs(R-L+1,-1LL<<60);
	
	if(L+1==R) {
		As={0,P[L].second};
		ABs={-1LL<<60,P[L].second-P[L].first};
		return {As,ABs};
	}
	int M=(L+R)/2;
	auto a=dfs(L,M);
	auto b=dfs(M,R);
	int i;
	int x=0,y=0;
	As[0]=0;
	for(i=1;i<=R-L;i++) {
		if(x==a.first.size()-1) y++;
		else if(y==b.first.size()-1) x++;
		else if(a.first[x+1]-a.first[x]>b.first[y+1]-b.first[y]) x++;
		else y++;
		As[i]=a.first[x]+b.first[y];
	}
	
	ABs=max_plus_conv(b.second,a.first);
	FOR(i,a.second.size()) ABs[i]=max(ABs[i],a.second[i]);
	FOR(i,b.second.size()) ABs[i]=max(ABs[i],b.second[i]);
	
	return {As,ABs};
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].second>>P[i].first;
	sort(P,P+N);
	
	auto a=dfs(0,N);
	FOR(i,N) cout<<a.second[i+1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
