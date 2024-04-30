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
int P[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<pair<int,int>> S={{0,0}};
	ll ret=0;
	ll sum=0;
	vector<int> ma,mi;
	for(i=1;i<=N;i++) {
		cin>>P[i];
		while(ma.size()&&P[ma.back()]<P[i]) {
			auto it=S.lower_bound({ma.back(),0});
			if(next(it)->second==1) sum+=ma.back()-prev(it)->first;
			S.erase(it);
			ma.pop_back();
		}
		while(mi.size()&&P[mi.back()]>P[i]) {
			auto it=S.lower_bound({mi.back(),1});
			if(next(it)->second==0) sum-=mi.back()-prev(it)->first;
			S.erase(it);
			mi.pop_back();
		}
		ret+=sum;
		ma.push_back(i);
		mi.push_back(i);
		S.insert({i,0});
		S.insert({i,1});
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
