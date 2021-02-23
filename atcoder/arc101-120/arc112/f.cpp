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

int N,M;
ll A[17];

int hoge(ll v) {
	int ret=0;
	for(int i=1;i<=N;i++) {
		ret+=v%(i*2);
		v/=(i*2);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	A[0]=1;
	for(i=1;i<=16;i++) A[i]=A[i-1]*(2*i);
	
	cin>>N>>M;
	ll v=0;
	FOR(i,N) {
		cin>>x;
		v+=x*A[i];
	}
	ll g=A[N]-1;
	
	FOR(y,M) {
		ll w=0;
		FOR(x,N) {
			cin>>i;
			w+=i*A[x];
		}
		g=__gcd(g,w);
	}
	
	if(A[N]/g<=10000000) {
		int ret=10101010;
		FOR(i,A[N]/g+2) {
			ret=min(ret,hoge(v));
			v+=g;
			if(v>=A[N]) v-=A[N]-1;
		}
		cout<<ret<<endl;
	}
	else {
		deque<pair<ll,int>> D;
		for(i=1;i<=N;i++) D.push_back({A[i-1],100+i});
		while(D.size()) {
			ll cur=D.front().first;
			int nex=D.front().second;
			D.pop_front();
			if(cur%g==v%g) {
				cout<<nex/100<<endl;
				return;
			}
			for(i=nex%100;i<=N;i++) D.push_back({cur+A[i-1],(nex/100+1)*100+i});
			
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
