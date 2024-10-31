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
int N,M;
pair<int,int> X[303030];
ll S[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>X[i].first>>X[i].second;
			if(X[i].first<=X[i].second) {
				N--;
				i--;
			}
		}
		
		if(N<M) {
			cout<<0<<endl;
			continue;
		}
		
		sort(X,X+N);
		FOR(i,N) S[i+1]=S[i]+X[i].first-X[i].second;
		ll ret=0;
		multiset<ll> V;
		ll mp=0;
		FOR(i,M-1) {
			V.insert({1LL<<60});
		}
		
		if(M==1) ret=S[N];
		
		for(i=N-1;i>=0;i--) {
			x=X[i].second;
			mp+=x;
			V.insert(x);
			ll a=*V.rbegin();
			if(a!=1LL<<60) mp-=a;
			V.erase(V.find(a));
			if(V.empty()||*V.rbegin()!=1LL<<60) ret=max(ret,S[i]-mp+M-1);
			
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
