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

ll N,M,L;
ll F[1<<22];
ll cnt[1<<22];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	if(N==1&&M==1) {
		cout<<2<<endl;
		return;
	}
	
	
	map<pair<int,int>,int> memo;
	F[1]=F[2]=1%N;
	memo[{1%N,1%N}]=1;
	for(i=3;i<=1<<21;i++) {
		F[i]=(F[i-1]+F[i-2])%N;
		if(memo.count({F[i-1],F[i]})) {
			L=i-2;
			break;
		}
		memo[{F[i-1],F[i]}]=i-1;
	}
	assert(L);
	
	ll ret=0;
	// F[M]
	if(F[M%L]==0) ret++;
	if(M-1>0&&F[(M-1)%L]==0) ret++;
	if(M-2>0&&(F[(M-1)%L]+F[(M-2)%L])%N==0) ret++;
	M-=2;
	
	if(M>=1) {
		cnt[0]++;
		int cur=0;
		for(i=1;i<=L;i++) {
			cur=(cur+F[i%L])%N;
			cnt[cur]+=M/L;
			if(i<=M%L) cnt[cur]++;
		}
		FOR(i,N) ret+=1LL*cnt[i]*(cnt[i]-1)/2;
	}
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
