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

ll N;
int A,B;
string S,T;

vector<int> C[26];

int ok(ll v) {
	ll lp=0;
	ll cur=0;
	FORR(c,T) {
		if(C[c].empty()) return 0;
		ll l=C[c].size()/3;
		lp+=(v-1)/l;
		ll a=v-(v-1)/l*l;
		int x=lower_bound(ALL(C[c]),cur+1)-C[c].begin();
		cur=C[c][x+a-1];
		lp+=cur/A;
		cur%=A;
		if(lp>N) return 0;
		
	}
	
	if(lp<N||(lp==N&&cur==0)) return 1;
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	A=S.size();
	B=T.size();
	FOR(i,A) {
		C[S[i]-'a'].push_back(i+1);
		C[S[i]-'a'].push_back(i+1+A);
		C[S[i]-'a'].push_back(i+1+2*A);
	}
	FOR(i,26) sort(ALL(C[i]));
	
	FORR(c,T) c-='a';
	ll ret=0;
	for(i=60;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
