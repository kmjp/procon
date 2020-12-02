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


	int N,K,X,Y;
set<int> S;
const ll mo=998244353;

ll from[1024][1024],fs[1024];
ll to[1024][1024];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X>>Y;
	FOR(i,K) {
		cin>>x;
		S.insert(x);
	}
	FORR(s,S) from[s][s]=1;
	FOR(i,N-1) {
		ZERO(to);
		FOR(j,1024) {
			fs[j]=0;
			FORR(s,S) fs[j]+=from[j][s];
			fs[j]%=mo;
		}
		FOR(j,1024) FORR(s,S) (to[j^s][s]+=fs[j]+mo-from[j][s])%=mo;
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,1024) if(X<=i&&i<=Y) FORR(s,S) {
		ret+=from[i][s];
	}
	
	cout<<(ret+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
