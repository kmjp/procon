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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	vector<int> X,Y;
	FOR(i,1<<N) X.push_back(1+i),Y.push_back(1+i);
	
	FORR(c,S) {
		vector<int> X2,Y2;
		
		int len=X.size()/2;
		if(c=='0') {
			FOR(x,len) X2.push_back(X[x]);
			FOR(x,len) Y2.push_back(Y[x*2]);
		}
		else {
			FOR(x,len) X2.push_back(X[x*2+1]);
			FOR(x,len) Y2.push_back(Y[len+x]);
		}
		X=X2;
		Y=Y2;
	}
	for(i=X[0];i<=Y.back();i++) cout<<i<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
