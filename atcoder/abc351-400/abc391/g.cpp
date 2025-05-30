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
string S;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FORR(c,S) c-='a';
	
	map<vector<int>,ll> from,to;
	from[vector<int>(N+1)]=1;
	
	while(M--) {
		to.clear();
		FORR2(a,b,from) {
			FOR(i,26) {
				vector<int> nx(N+1);
				FOR(j,N) {
					nx[j+1]=max(nx[j],a[j+1]);
					if(S[j]==i) nx[j+1]=max(nx[j+1],a[j]+1);
				}
				(to[nx]+=b)%=mo;
			}
		}
		swap(from,to);
	}
	ll ret[11]={};
	FORR2(a,b,from) {
		(ret[a[N]]+=b)%=mo;
	}
	FOR(i,N+1) cout<<ret[i]%mo<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
