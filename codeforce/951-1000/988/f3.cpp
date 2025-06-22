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
ll N,M,K;
int H[101010],X[101010];

int ok(int v) {
	map<ll,int> A;
	int i;
	FOR(i,N) {
		int x=(H[i]+v-1)/v;
		if(M>=x) {
			A[X[i]-(M-x)]++;
			A[X[i]+(M-x)+1]--;
		}
	}
	int sum=0;
	FORR2(a,b,A) {
		sum+=b;
		if(sum>=K) return 1;
	}
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		FOR(i,N) cin>>H[i];
		FOR(i,N) cin>>X[i];
		ll ret=1<<30;
		if(ok(ret)==0)  {
			cout<<-1<<endl;
			continue;
		}
		for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
