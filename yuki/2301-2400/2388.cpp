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

int N,M,K;
string S;
const ll mo=998244353;

ll from[28];
ll to[28];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S;
	
	
	ll ret=0;
	int mask=0;
	from[0]=1;
	FOR(i,M) {
		ZERO(to);
		
		for(j=1;j<=26;j++) {
			(to[j]+=from[j]*j)%=mo;
			(to[j+1]+=from[j]*(26-j))%=mo;
		}
		if(i<N) {
			x=__builtin_popcount(mask);
			FOR(j,S[i]-'a') {
				if(mask&(1<<j)) {
					(to[x]+=from[0])%=mo;
				}
				else {
					(to[x+1]+=from[0])%=mo;
				}
			}
			mask|=1<<(S[i]-'a');
			to[0]=from[0];
		}
		
		swap(from,to);
		if(i<N-1&&__builtin_popcount(mask)>=K) ret++;
		for(j=K;j<=26;j++) (ret+=from[j])%=mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
