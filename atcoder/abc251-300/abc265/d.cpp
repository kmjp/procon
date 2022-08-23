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
ll S[202020];
ll P,Q,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>Q>>R;
	FOR(i,N) {
		cin>>x;
		S[i+1]=S[i]+x;
	}
	S[N+1]=1LL<<60;
	FOR(i,N) {
		x=lower_bound(S,S+N+1,S[i]+P)-S;
		if(x==N+1||S[x]!=S[i]+P) continue;
		y=lower_bound(S,S+N+1,S[x]+Q)-S;
		if(y==N+1||S[y]!=S[x]+Q) continue;
		x=lower_bound(S,S+N+1,S[y]+R)-S;
		if(x==N+1||S[x]!=S[y]+R) continue;
		cout<<"Yes"<<endl;
		return;
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
