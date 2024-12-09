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
string S[7];
int V[7][7];

int ok(int p) {
	int y,x;
	for(y=1;y<6;y++) for(x=1;x<6;x++) if((x+y)%2==p) {
		int s=V[y][x]+V[y+1][x+1]+V[y+1][x-1]+V[y-1][x+1]+V[y-1][x-1];
		if(s==5) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(y,7) {
			cin>>S[y];
			FORR(c,S[y]) c=(c=='B');
		}
		vector<pair<int,int>> A[2];
		for(y=1;y<6;y++) for(x=1;x<6;x++) {
			A[(x+y)%2].push_back({y,x});
		}
		
		int ret[2]={100,100};
		FOR(i,2) {
			int mask;
			FOR(mask,1<<A[i].size()) {
				FOR(y,7) FOR(x,7) V[y][x]=S[y][x];
				FOR(j,A[i].size()) if(mask&(1<<j)) V[A[i][j].first][A[i][j].second]=0;
				if(ok(i)) ret[i]=min(ret[i],__builtin_popcount(mask));
			}
		}
		cout<<ret[0]+ret[1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
