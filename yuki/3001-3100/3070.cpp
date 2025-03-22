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
int A,B,Z;

const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> V;
	FOR(i,N) {
		cin>>x;
		if(x>0) A++;
		if(x<0) B++;
		if(x==0) V.push_back(1);
	}
	ll a=1,b=1;
	FOR(i,A-1) a=a*2%mo;
	FOR(i,B-1) b=b*2%mo;
	ll ret=1;
	if(A) V.push_back(a);
	if(B) V.push_back(b);
	ret=1;
	FOR(i,V.size()) ret=ret*(i+1);
	FORR(a,V) ret=ret*a%mo;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
