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
string A,B,C;

ll hoge(string A,string B) {
	vector<int> X,Y;
	int i;
	FOR(i,2*N) {
		if(A[i]=='1') X.push_back(i);
		if(B[i]=='1') Y.push_back(i);
	}
	ll ret=0;
	FOR(i,N) ret+=abs(X[i]-Y[i]);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C;
	string D;
	vector<int> V[3];
	
	FOR(i,2*N) {
		int X[3]={};
		if(A[i]=='0') V[0].push_back(i);
		if(B[i]=='0') V[1].push_back(i);
		if(C[i]=='0') V[2].push_back(i);
		D+='1';
	}
	FOR(i,N) {
		int B[3]={V[0][i],V[1][i],V[2][i]};
		sort(B,B+3);
		D[B[1]]='0';
	}
	
	
	ll ret=hoge(A,D)+hoge(B,D)+hoge(C,D);
	cout<<ret<<endl;
	cout<<D<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
