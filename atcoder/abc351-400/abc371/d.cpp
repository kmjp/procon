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

int N,Q;
vector<ll> X,S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	X.push_back(-1<<30);
	S.push_back(0);
	FOR(i,N) {
		cin>>x;
		X.push_back(x);
	}
	FOR(i,N) {
		cin>>x;
		S.push_back(S.back()+x);
	}
	X.push_back(1<<30);
	S.push_back(S.back());
	cin>>Q;
	while(Q--) {
		int L,R;
		cin>>L>>R;
		x=lower_bound(ALL(X),R+1)-X.begin();
		ll ret=S[x-1];
		x=lower_bound(ALL(X),L)-X.begin();
		ret-=S[x-1];
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
