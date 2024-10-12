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

int Q;
ll Y;
ll S[202020];

__int128 eval(ll x) {
	if(x<0) return -1;
	vector<__int128> A;
	int i;
	FOR(i,Q) {
		if(S[i]>=0) {
			A.push_back(S[i]);
		}
		else if(S[i]==-4) {
			A.push_back(x);
		}
		else {
			__int128 a=A.back();
			A.pop_back();
			__int128 b=A.back();
			A.pop_back();
			if(S[i]==-1) A.push_back(a+b);
			if(S[i]==-2) A.push_back(min(a,b));
			if(S[i]==-3) A.push_back(max(a,b));
		}
	}
	return A[0];
		
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q>>Y;
	FOR(i,Q) {
		cin>>s;
		if(s=="+") S[i]=-1;
		else if(s=="min") S[i]=-2;
		else if(s=="max") S[i]=-3;
		else if(s=="X") S[i]=-4;
		else S[i]=atoll(s.c_str());
	}
	
	
	if(eval(Y)<Y) {
		cout<<-1<<endl;
		return;
	}
	ll ret=Y;
	for(i=60;i>=0;i--) if(eval(ret-(1LL<<i))>=Y) ret-=1LL<<i;
	if(eval(ret)==Y) cout<<ret<<endl;
	else cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
