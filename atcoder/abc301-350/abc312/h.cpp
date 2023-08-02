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
string S[202020];
ll R[202020];
ll ret[202020];

using VT = string;
map<string,vector<int>> M;



vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		auto Z=Zalgo(S[i]);
		R[i]=1;
		for(j=1;j<S[i].size();j++) if(S[i].size()%j==0&&j+Z[j]==S[i].size()) R[i]=max((ll)R[i],(ll)S[i].size()/j);
		S[i]=S[i].substr(0,S[i].size()/R[i]);
		M[S[i]].push_back(i);
	}
	FORR2(a,V,M) {
		map<ll,ll> pre;
		set<ll> S;
		FORR(v,V) {
			r=R[v];
			ll cur=pre[r]+r;
			while(S.count(cur)) cur+=r;
			S.insert(cur);
			pre[r]=cur;
			ret[v]=cur/r;
		}
		
	}
	FOR(i,N) cout<<ret[i]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
