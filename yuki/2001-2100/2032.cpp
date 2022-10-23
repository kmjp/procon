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
int L,R,K,C;

ll floor_sum(ll N,ll M,ll A,ll B) {
	// sum(i=0...N-1) floor((A*i+B)/M)
	
	ll ret=0;
	if(B>=M) ret+=N*(B/M), B%=M;
	if(A>=M) ret+=N*(N-1)/2*(A/M), A%=M;
	
	ll Y=(A*N+B)/M;
	if(Y==0) return ret;
	//floor(Y/M)に達するX
	ll X=Y*M-B;
	//Xの右側はY個ずつ
	ret+=(N-(X+A-1)/A)*Y;
	// 90度回転、Y=Nのラインは無視する
	ret+=floor_sum(Y,A,M,(A-X%A)%A);
	return ret;
}

ll hoge(ll v) {
	ll ret=0;
	ll N=v/K;
	ll cur=1;
	for(int d=0;d<9;d++) {
		ll LL=C*cur;
		ll RR=(C+1)*cur;
		ret+=floor_sum(N,cur*10,K,cur*10+K-LL)-floor_sum(N,cur*10,K,cur*10+K-RR);
		cur*=10;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L>>R>>K>>C;
		ll ret=hoge(R)-hoge(L-1);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
