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
ll mo;

ll from[101][101][101];
ll to[101][101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>mo;
	from[0][0][0]=1;
	for(i=1;i<N;i++) {
		ZERO(to);
		FOR(k,i+1) {
			ll S[105][105]={};
			FOR(x,i+1) FOR(y,i+1) {
				S[x+1][y+1]=(S[x+1][y]+S[x][y+1]+mo-S[x][y]+from[x][y][k])%mo;
			}
			FOR(x,i+1) FOR(y,i+1) {
				(to[x][y][k+1]+=(S[x][y]+S[i+1][i+1]-S[x][i+1]-S[i+1][y]+S[x][y]+4*mo))%=mo;
				(to[x][y][k]+=(S[i+1][y]+S[x][i+1]-2*S[x][y]+4*mo))%=mo;
			}
		}
		
		swap(from,to);
	}
	
	ll ret=0;
	FOR(x,N+1) FOR(y,N+1) ret+=from[x][y][K];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
