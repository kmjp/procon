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

int N,K;
int D[202020];
ll S[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll ret=1LL<<60;
	FOR(i,N) cin>>D[i];
	FOR(j,2) {
		FOR(i,N) D[i]=(1<<30)-D[i];
		sort(D,D+N);
		FOR(i,N) S[i+1]=S[i]+D[i];
		FOR(i,N) {
			ll lef=1LL*D[i]*i-S[i];
			x=lower_bound(D,D+N,D[i]+K)-D;
			ll ri=S[N]-S[x]-1LL*(N-x)*(D[i]+K-1);
			ret=min(ret,lef+ri);
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
