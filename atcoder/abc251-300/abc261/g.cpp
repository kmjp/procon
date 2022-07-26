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


string S,T;
int K;
vector<string> A[26];

ll E[256][256];

map<string,ll> M[256];
map<pair<string,string>,ll> memo;

ll hoge2(string a,string b);
ll hoge(char c,string s) {
	if(s.empty()) return 1LL<<30;
	if(s.size()==1) return E[c][s[0]];
	if(M[c].count(s)) return M[c][s];
	ll& ret=M[c][s];
	ret=1LL<<30;
	
	for(int a='a';a<='z';a++) if(E[c][a]<1LL<<30) {
		FORR(m,A[a]) ret=min(ret,1+E[c][a]+hoge2(m,s));
	}
	
	return ret;
}


ll hoge2(string a,string b) {
	if(a==b) return 0;
	if(a.empty()) return 1LL<<30;
	if(a.size()>b.size()) return 1LL<<30;
	if(memo.count({a,b})) return memo[{a,b}];
	
	if(a.size()==1) return hoge(a[0],b);
	
	ll& ret=memo[{a,b}];
	ret=1LL<<30;
	int i;
	for(i=1;i<=b.size()-(a.size()-1);i++) {
		ll c=hoge(a[0],b.substr(0,i));
		if(c<1LL<<30) ret=min(ret,c+hoge2(a.substr(1),b.substr(i)));
	}
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	cin>>K;
	FOR(x,256) FOR(y,256) E[x][y]=(x==y)?0:1<<30;
	
	FOR(i,K) {
		string a,b;
		cin>>a>>b;
		if(b.size()==1) {
			E[a[0]][b[0]]=1;
		}
		else {
			A[a[0]].push_back(b);
		}
	}
	FOR(k,256) FOR(x,256) FOR(y,256) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	
	ll ret=hoge2(S,T);
	if(ret>=1LL<<30) {
		ret=-1;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
