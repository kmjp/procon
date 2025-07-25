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

int A;
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>N;
	set<ll> V;
	for(i=1;i<1000000;i++) {
		string A=to_string(i);
		string B=A;
		reverse(ALL(B));
		string C=A+B;
		string D=A+B.substr(1);
		ll a=atoll(C.c_str());
		ll b=atoll(D.c_str());
		V.insert(a);
		V.insert(b);
	}
	
	ll ret=0;
	FORR(v,V) if(v<=N) {
		string B;
		ll a=v;
		while(a) {
			B+=a%A;
			a/=A;
		}
		string C=B;
		reverse(ALL(C));
		if(B==C) ret+=v;
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
