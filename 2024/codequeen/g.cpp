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
int C[202020];
vector<int> V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	multiset<pair<int,int>> M;
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		M.insert({-C[i],i+1});
	}
	M.insert({0,-1});
	int num=0;
	while(1) {
		int pre=-1;
		FOR(i,5) {
			auto it=M.begin();
			if(it->second==pre) it++;
			if(-it->first<=0) break;
			x=it->second;
			M.erase(it);
			C[x-1]--;
			pre=x;
			M.insert({-C[x-1],x});
			V[num].push_back(x);
		}
		if(i==5) num++;
		else break;
	}
	cout<<num<<endl;
	FOR(i,num) {
		FORR(a,V[i]) cout<<a<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
