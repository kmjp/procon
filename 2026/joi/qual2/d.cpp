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
int Q;
ll A[303030];
ll S[303030];
ll C,D;

ll hoge(ll k) {
	ll dk=D*k;
	int x=lower_bound(A,A+N,dk)-A;
	ll sum=(S[N]-S[x])-(1LL*(N-x)*(dk))+C*k;
	return sum;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
	}
	sort(A,A+N);
	FOR(i,N) S[i+1]=S[i]+A[i];
	while(Q--) {
		cin>>C>>D;
		ll L=0,R=(1<<30)/D+1;
		ll ret=hoge(0);
		while(R-L>=10) {
			ll M1=(L*2+R)/3;
			ll M2=(L+R*2)/3;
			ll V1=hoge(M1);
			ll V2=hoge(M2);
			if(V1<=V2) R=M2;
			if(V2<=V1) L=M1;
			ret=min(ret,V1);
			ret=min(ret,V2);
		}
		for(i=L;i<=R;i++) ret=min(ret,hoge(i));
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
