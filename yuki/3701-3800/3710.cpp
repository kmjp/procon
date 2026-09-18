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
vector<string> S[8][8];

vector<string> rotate(vector<string> S) {
	vector<string> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(string(H,' '));
	FOR(y,H) FOR(x,W) T[W-1-x][y]=S[y][x]; //left
	//FOR(y,H) FOR(x,W) T[x][y]=S[H-1-y][x]; //right
	return T;
}

int A[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		vector<string> A;
		FOR(y,M) {
			cin>>s;
			A.push_back(s);
		}
		FOR(j,4) {
			S[i][j]=A;
			A=rotate(A);
		}
	}
	int mi=101010;
	int mask;
	FOR(mask,1<<(2*N)) {
		ZERO(A);
		FOR(i,N) {
			vector<string> V=S[i][(mask>>(2*i))%4];
			FOR(y,M) FOR(x,M) A[y][x]|=V[y][x]=='#';
		}
		int sum=0;
		FOR(y,M) FOR(x,M) sum+=A[y][x];
		mi=min(mi,sum);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
