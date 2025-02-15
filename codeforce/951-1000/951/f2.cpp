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

int T,N,nex[101010];

pair<int,int> ask(int d) {
	cout<<"? "<<d<<endl;
	int x,y;
	cin>>x>>y;
	return {x,y};
}

pair<int,int> hoge(int N) {
	if(N==1) {
		auto p=ask(0);
		return {p.first,p.first};
	}
	if(N==2) {
		auto p=ask(0);
		auto q=ask(0);
		nex[p.first]=q.first;
		return {p.first,q.first};
	}
	
	auto p=ask(N-2);
	int v=p.first;
	int ng=p.second;
	if(ng==0) {
		// N-1’¸“_
		auto q=ask(0);
		nex[q.first]=v;
		auto ret=hoge(N-2);
		nex[v]=ret.first;
		return {q.first,ret.second};
		
	}
	else {
		auto ret=hoge(N-1);
		if(ng!=ret.first) {
			nex[v]=ret.first;
			return {v,ret.second};
		}
		else {
			nex[ret.second]=v;
			return {ret.first,v};
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) nex[i+1]=-1;
		x=hoge(N).first;
		cout<<"!";
		while(x!=-1) {
			cout<<" "<<x;
			x=nex[x];
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
