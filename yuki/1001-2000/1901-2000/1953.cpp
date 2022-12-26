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

ll K;

int C[10]={1,0,0,0,1,0,1,0,2,1};
pair<ll,ll> dp[20][2][2];
string S;

pair<ll,ll> hoge(int d,int le,int lz) {
	if(d<0) return {lz,0};
	if(dp[d][le][lz].first>=0) return dp[d][le][lz];
	ll sum=0;
	ll num=0;
	
	int c;
	FOR(c,10) {
		if(le==0&&c>S[d]) break;
		pair<ll,ll> r=hoge(d-1,le|(c<S[d]),lz|(c>0));
		num+=r.first;
		sum+=r.second;
		if(c>0||lz) sum+=r.first*C[c];
	}
	
	
	return dp[d][le][lz]={num,sum};
	
}

ll num(ll v) {
	S=to_string(v);
	reverse(ALL(S));
	S+="000000000000000000";
	FORR(c,S) c-='0';
	MINUS(dp);
	
	return hoge(19,0,0).second;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>K;
	ll ret=1LL<<60;
	for(i=59;i>=1;i--) if(num(ret-(1LL<<i))>=K) ret-=1LL<<i;
	
	if(num(ret)==K) {
		cout<<ret<<endl;
	}
	else {
		cout<<-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
