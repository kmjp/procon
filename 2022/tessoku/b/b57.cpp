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

ll N,K;
int D[303030][31];

ll F(ll a) {
	ll b=a,c=0;
	while(b) c+=b%10, b/=10;
	return a-c;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	FOR(i,301010) D[i][0]=F(i);
	FOR(i,30) FOR(j,301010) D[j][i+1]=D[D[j][i]][i];
	
	for(i=1;i<=N;i++) {
		int V=i;
		FOR(j,30) if(K&(1<<j)) V=D[V][j];
		cout<<V<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
