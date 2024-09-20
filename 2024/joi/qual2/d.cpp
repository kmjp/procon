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
int ret[4][3535][3535];
vector<string> S;

int L[3535][3535];

vector<string> rotate(vector<string> S) {
	vector<string> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(string(H,' '));
	FOR(y,H) FOR(x,W) T[W-1-x][y]=S[y][x]; //left
	//FOR(y,H) FOR(x,W) T[x][y]=S[H-1-y][x]; //right
	return T;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>s;
		S.push_back(s);
	}
	FOR(r,4) {
		FOR(y,N) {
			FOR(x,N) {
				L[y][x]=x;
				if(y&&x&&S[y][x]==S[y-1][x-1]) L[y][x]=L[y-1][x-1];
			}
			for(int x=0,R=0;x<N;x++) {
				while(R<N&&L[y][R]<=x) R++;
				ret[r][y][x]=R-x-1;
			}
		}
		
		S=rotate(S);
	}
	
	int ma=0;
	FOR(y,N) FOR(x,N) {
		k=min({ret[0][y][x],ret[2][N-1-y][N-1-x],ret[1][N-1-x][y],ret[3][x][N-1-y]});
		ma=max(ma,k);
	}
	int ret=1;
	FOR(i,ma) ret+=(i+1)*4;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
