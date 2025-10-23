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
ll A[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		
		ll ret=0;
		vector<ll> X,Y;
		FOR(i,N-1) Y.push_back(A[i]);
		for(i=1;i<N;i++) X.push_back(A[i]);
		sort(ALL(X));
		sort(ALL(Y));
		reverse(ALL(X));
		reverse(ALL(Y));
		X.resize(K);
		Y.resize(K);
		X.push_back(A[0]);
		Y.push_back(A[N-1]);
		ll a=0,b=0;
		FORR(v,X) a+=v;
		FORR(v,Y) b+=v;
		ret=max(a,b);
		if(K>=2) {
			for(i=1;i<N-1;i++) {
				vector<ll> X,Y;
				FOR(j,N) {
					if(j<i) X.push_back(A[j]);
					if(j>i) Y.push_back(A[j]);
				}
				sort(ALL(X));
				sort(ALL(Y));
				ll a=A[i];
				a+=X.back();
				a+=Y.back();
				X.pop_back();
				Y.pop_back();
				FORR(b,Y) X.push_back(b);
				sort(ALL(X));
				reverse(ALL(X));
				FOR(j,K-2) a+=X[j];
				ret=max(ret,a);
			}
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
