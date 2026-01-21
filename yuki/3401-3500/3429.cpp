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

int N;
string S[402];

ll from[202][202];
ll to[202][202];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>s;
		FOR(x,N) S[y+x].push_back(s[x]);
	}
	
	FOR(y,N) from[y][y]=1;
	for(i=1;i<=N-1;i++) {
		ZERO(to);
		FOR(x,N) FOR(y,N) if(from[x][y]) {
			int x2,y2;
			for(x2=max(0,x-1);x2<=min(x,(int)S[N-1-i].size()-1);x2++) for(y2=max(0,y-1);y2<=min(y,(int)S[N-1+i].size()-1);y2++) {
				if(S[N-1-i][x2]==S[N-1+i][y2]) (to[x2][y2]+=from[x][y])%=mo;
			}
		}
		
		swap(from,to);
	}
	cout<<from[0][0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
