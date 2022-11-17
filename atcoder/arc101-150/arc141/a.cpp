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

int T;
ll N;

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		string S;
		cin>>N;
		S=to_string(N);
		ll ma=0;
		
		for(i=1;i<S.size();i++) if(S.size()%i==0) {
			string T=S.substr(0,i);
			string C;
			FOR(j,S.size()/i) C+=T;
			ll v=atoll(C.c_str());
			if(v<=N) ma=max(ma,v);
			
			ll a=atoll(T.c_str())-1;
			T=to_string(a);
			if(a&&T.size()==i) {
				C="";
				FOR(j,S.size()/i) C+=T;
				ll v=atoll(C.c_str());
				if(v<=N) ma=max(ma,v);
			}
		}
		
		ll v=1;
		while(v<=(1LL<<60)/10) {
			v*=10;
			s=to_string(v-1);
			if(v-1<=N&&v>=10) ma=max(ma,v-1);
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
