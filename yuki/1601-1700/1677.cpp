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

int cur;
string S;
int K;
const ll mo=998244353;
vector<ll> dfs() {
	if(S[cur]=='m') {
		char c=S[cur+1];
		cur+=4;
		vector<ll> A=dfs();
		cur++;
		vector<ll> B=dfs();
		cur++;
		
		vector<ll> C={0,0,0};
		int a,b;
		FOR(a,3) FOR(b,3) {
			if(c=='a'||c=='?') {
				(C[max(a,b)]+=A[a]*B[b])%=mo;
			}
			if(c=='e'||c=='?') {
				int ne=0;
				if(ne==a||ne==b) ne++;
				if(ne==a||ne==b) ne++;
				if(ne==a||ne==b) ne++;
				(C[ne]+=A[a]*B[b])%=mo;
			}
		}
		return C;
		
	}
	else {
		char c=S[cur++];
		if(c=='0') return {1,0,0};
		if(c=='1') return {0,1,0};
		if(c=='2') return {0,0,1};
		return {1,1,1};
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	auto A=dfs();
	cout<<A[K]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
