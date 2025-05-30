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

int T,N,K;
ll A[202020];
int g,z;
ll ok(ll v) {
	if(g==0) return v;
	
	int num=min(N,(int)v/g+1);
	return v+1-num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		g=0;
		FOR(i,N) {
			cin>>A[i];
			g=__gcd(g,(int)A[i]);
		}
		ll ret=-1;
		if(N==1) {
			if(K<=A[0]) ret=K-1;
			else ret=K;
			cout<<ret<<endl;
		}
		else {
			for(i=30;i>=0;i--) if(ok(ret+(1<<i))<K) ret+=1<<i;
			cout<<ret+1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
