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
ll X[101010];

int hoge(ll v) {
	ll pre=0;
	int num=0;
	int i;
	for(i=1;i<=N;i++) {
		if(X[i]-pre>=v) {
			num++;
			pre=X[i];
		}
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		X[i+1]=X[i]+x;
	}
	
	if(N%2==0) {
		ll mi=1LL<<60;
		for(i=0;i+N/2+1<=N;i++) mi=min(mi,X[i+N/2+1]-X[i]);
		cout<<mi<<endl;
	}
	else {
		ll ret=0;
		for(i=50;i>=0;i--) if(hoge(ret+(1LL<<i))>=(N+1)/2) ret+=1LL<<i;
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
