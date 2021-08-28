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

ll L,R;
int N;
ll C[1010101];
int did[1010101];

ll issq(ll V) {
	ll a=sqrt(V);
	for(ll b=a-2;b<=a+2;b++) if(b*b==V) return 1;
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R;
	R++;
	N=R-L;
	FOR(i,N) C[i]=L+i;
	for(i=2;i<=1000000;i++) {
		ll s=(L+(i-1))/i*i;
		for(x=s-L;x<N;x+=i) {
			int num=0;
			while(C[x]%i==0) {
				num++;
				C[x]/=i;
			}
			if(num>=2) did[x]++;
		}
	}
	int ret=0;
	FOR(i,N) {
		if(did[i] || (C[i]>1&&issq(C[i]))) ret++;
	}
	cout<<N-ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
