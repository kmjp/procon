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
int H,W;
vector<int> A[252525];

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) A[y].resize(W);
		deque<int> C;
		FOR(y,H) {
			if(y%2==0) C.push_front(y);
			else C.push_back(y);
		}
		FOR(y,C.size()) {
			FOR(x,W) {
				A[y][x]=C[y]*W+x+1;
			}
		}
		
		if(isprime(W)) {
			int is=0;
			FOR(y,C.size()) {
				if(is) {
					FOR(x,W-1) swap(A[y][x],A[y][x+1]);
				}
				if(C[y]==0) is=1;
			}
			
		}
		
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
