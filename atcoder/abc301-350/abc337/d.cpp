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

int H,W,K;
string S[202020];

int A[202020],B[202020];
int hoge(string S) {
	int N=S.size();
	int i;
	int ret=1<<20;
	FOR(i,N) {
		A[i+1]=A[i]+(S[i]=='o');
		B[i+1]=B[i]+(S[i]=='x');
		if(i+1>=K &&B[i+1]-B[i+1-K]==0) {
			ret=min(ret,K-(A[i+1]-A[i+1-K]));
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	int ret=1<<20;
	FOR(y,H) {
		cin>>S[y];
		ret=min(ret,hoge(S[y]));
	}
	FOR(x,W) {
		string T;
		FOR(y,H) T+=S[y][x];
		ret=min(ret,hoge(T));
	}
	
	
	if(ret==1<<20) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
