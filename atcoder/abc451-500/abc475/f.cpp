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

int H,W;
vector<string> S;
vector<int> C[202020];
int A[202020];
vector<string> flip(vector<string> S) {
	vector<string> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(string(H,' '));
	FOR(y,H) FOR(x,W) T[x][y]=S[y][x]; //left
	return T;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>s;
		S.push_back(s);
	}
	if(H<W) {
		swap(H,W);
		S=flip(S);
	}
	FOR(y,H) {
		C[y].push_back(0);
		FORR(c,S[y]) C[y].push_back(C[y].back()+(c=='.'));
	}
	ll ret=1;
	for(int x1=0;x1<W;x1++) for(int x2=x1;x2<W;x2++) {
		int y1=-1,y2=-1;
		FOR(y,H) {
			A[y+1]=A[y];
			if(S[y][x1]=='.') y1=y;
			if(S[y][x2]=='.') y2=y;
			if(C[y][x2+1]-C[y][x1]) {
				A[y+1]++;
				ret+=A[min(y1,y2)+1];
			}
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
