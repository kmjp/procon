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

int T,H,W;
vector<ll> A[1010101];
ll R[1<<20];
ll C[1<<20];
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>S;
		FOR(y,H) R[y]=0;
		FOR(x,W) C[x]=0;
		FOR(y,H) {
			A[y].resize(W);
			FOR(x,W) {
				cin>>A[y][x];
				R[y]+=A[y][x];
				C[x]+=A[y][x];
			}
		}
		y=x=0;
		FORR(c,S) {
			if(c=='D') {
				A[y][x]=-R[y];
				R[y]+=A[y][x];
				C[x]+=A[y][x];
				y++;
			}
			else {
				A[y][x]=-C[x];
				R[y]+=A[y][x];
				C[x]+=A[y][x];
				x++;
			}
		}
		A[y][x]=-R[y];
		FOR(y,H) {
			FOR(x,W) cout<<A[y][x]<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
