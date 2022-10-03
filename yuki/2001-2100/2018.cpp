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
string S,T;
int A[202020];
int B[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	if(S[0]!=T[0]||S[N-1]!=T[N-1]) {
		cout<<-1<<endl;
		return;
	}
	vector<int> X,Y;
	FOR(i,N-1) {
		A[i]=(S[i]!=S[i+1])^(i%2);
		B[i]=(T[i]!=T[i+1])^(i%2);
		if(A[i]) X.push_back(i);
		if(B[i]) Y.push_back(i);
	}
	if(X.size()!=Y.size()) {
		cout<<-1<<endl;
	}
	else {
		ll ret=0;
		FOR(i,X.size()) ret+=abs(X[i]-Y[i]);
		cout<<ret<<endl;
	}
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
