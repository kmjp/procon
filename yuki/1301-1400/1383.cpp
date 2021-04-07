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

ll N,K,M;

int build(ll v) {
	ll a=0;
	int i;
	for(i=29;i>=0;i--) if((a+(1<<i))*(a+(1<<i)+K)<=v) a+=1<<i;
	return a*(a+K)==v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	
	ll a=1;
	map<ll,int> R;
	for(ll A=1;A<=1000000;A++) {
		ll V=A*(A+K);
		if(N/(A+2*K)<V) break;
		for(i=2;i<=20;i++) {
			if(N/(A+i*K)<V) break;
			V=V*(A+i*K);
			R[V]++;
		}
	}
	ll ret=0;
	if(M==1) {
		for(i=29;i>=0;i--) {
			if(N/(ret+(1LL<<i)+K)<(ret+(1LL<<i))) continue;
			if((ret+(1LL<<i))*(ret+(1LL<<i)+K)<=N) ret+=1<<i;
		}
		
		FORR(m,R) {
			if(m.second>0&&build(m.first)) ret--;
			if(m.second==1&&!build(m.first)) ret++;
		}
	}
	else {
		FORR(m,R) {
			if(m.second+build(m.first)==M) ret++;
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
