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
string T;
string S;
int L[505050];
int R[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) {
		cin>>S;
		x=0;
		FORR(c,S) if(x<T.size()&&T[x]==c) x++;
		L[x]++;
		x=0;
		reverse(ALL(S));
		FORR(c,S) if(x<T.size()&&T[T.size()-1-x]==c) x++;
		R[x]++;
	}
	
	for(i=500000;i>=0;i--) R[i]+=R[i+1];
	ll ret=0;
	for(i=0;i<=T.size();i++) ret+=1LL*L[i]*R[T.size()-i];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
