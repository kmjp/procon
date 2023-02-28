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

int H,W,Q;
string A[202020],B[202020];
int rot[202020];
int SW;
string ret;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) cin>>A[y];
	if(H>W) {
		SW=1;
		FOR(y,H) FOR(x,W) B[x].push_back(A[y][x]);
		
		swap(H,W);
	}
	else {
		FOR(y,H) B[y]=A[y];
	}
	while(Q--) {
		int T,P;
		char C;
		cin>>T>>P>>C;
		if(SW) T=3-T;
		P--;
		if(T==1) {
			ret+=B[P][(rot[P]+W-1)%W];
			B[P][(rot[P]+W-1)%W]=C;
			rot[P]=(rot[P]+W-1)%W;
		}
		else {
			FOR(y,H) {
				x=(P+rot[y])%W;
				swap(C,B[y][x]);
			}
			ret+=C;
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
