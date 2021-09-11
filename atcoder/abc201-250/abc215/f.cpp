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
int X[202020],Y[202020];

int ok(int v) {
	vector<pair<int,int>> ev;
	
	int i;
	FOR(i,N) {
		ev.push_back({X[i],i});
		ev.push_back({X[i]+v,N+i});
	}
	sort(ALL(ev));
	int ma=-1<<30;
	int mi=1<<30;
	FORR2(x,i,ev) {
		if(i<N) {
			if(ma-Y[i]>v) return 0;
			if(Y[i]-mi>v) return 0;
		}
		else {
			i-=N;
			ma=max(ma,Y[i]);
			mi=min(mi,Y[i]);
			
		}
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	
	int ret=(1<<30)-1;
	for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
