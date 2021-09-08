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
ll K;

ll num(ll v) {
	ll sum=1;
	for(int i=2;i<=60;i++) {
		int num=1;
		int x=i;
		for(int j=2;j<=i;j++) if(x%j==0) {
			num*=-1;
			if(x%(j*j)==0) num=0;
			while(x%j==0) x/=j;
		}
		if(num==0) continue;
		ll a=pow(v,1.0/i)+2;
		while(1) {
			__int128 b=1;
			int j;
			FOR(j,i) b*=(a-1);
			if(b>=v) a--;
			else break;
		}
		a--;
		
		if(num==-1) {
			sum+=a-1;
		}
		else {
			sum-=a-1;
		}
	}
	return sum;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>K;
		ll ret=1LL<<60;
		for(i=59;i>=0;i--) if(num(ret-(1LL<<i))>=K) ret-=1LL<<i;
		cout<<ret-1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
