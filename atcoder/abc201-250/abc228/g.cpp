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

int H,W,N;
string S[10];
const ll mo=998244353;

ll A[1<<10];
ll B[1<<10];
ll C[1<<10];


vector<int> FA[1<<10];
vector<int> FB[1<<10];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) c-='1';
	}
	
	int mask;
	FOR(mask,1<<10) if(mask) {
		FOR(i,9) {
			int to=0;
			FOR(y,H) if(mask&(1<<y)) {
				FOR(x,W) if(S[y][x]==i) to|=1<<x;
			}
			FA[mask].push_back(to);
		}
		FOR(i,9) {
			int to=0;
			FOR(x,W) if(mask&(1<<x)) {
				FOR(y,H) if(S[y][x]==i) to|=1<<y;
			}
			FB[mask].push_back(to);
		}
		
	}
	
	A[(1<<H)-1]=1;
	while(N--) {
		int mask;
		ZERO(B);
		ZERO(C);
		FOR(mask,1<<10) FORR(t,FA[mask]) (B[t]+=A[mask])%=mo;
		FOR(mask,1<<10) FORR(t,FB[mask]) (C[t]+=B[mask])%=mo;
		swap(C,A);
	}
	ll ret=0;
	FOR(mask,1<<10) if(mask) ret+=A[mask];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
