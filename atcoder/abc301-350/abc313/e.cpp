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
string S;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	vector<pair<int,int>> V;
	FOR(i,N) {
		if(V.empty()||V.back().first!=S[i]-'0') V.push_back({S[i]-'0',0});
		V.back().second++;
		if(i&&S[i]>'1'&&S[i-1]>'1') {
			cout<<-1<<endl;
			return;
		}
	}
	
	if(V.size()==1) {
		cout<<V[0].second-1<<endl;
		return;
	}
	
	ll ret=0;
	for(i=V.size()-1;i>=0;i--) if(V[i].first==1) {
		ll num;
		if(i==V.size()-1) {
			num=V[i].second;
		}
		else {
			num=ret+V[i].second+1+(1+ret)*(V[i+1].first-1);
		}
		ret=num%mo;
	}
	if(V[0].first==1) ret+=mo-1;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
