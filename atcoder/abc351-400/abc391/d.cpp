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

int N,W,Q;
int X[202020],Y[202020];
vector<pair<int,int>> Xs[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(ret);
	cin>>N>>W;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Xs[X[i]].push_back({Y[i],i});
	}
	FOR(x,W) sort(ALL(Xs[x]));
	FOR(y,202020) {
		int ma=0;
		FOR(x,W) {
			if(Xs[x].size()<y+1) {
				ma=1<<30;
			}
			else {
				ma=max(ma,Xs[x][y].first);
			}
		}
		if(ma==1<<30) break;
		FOR(x,W) ret[Xs[x][y].second]=ma;
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		y--;
		if(ret[y]==-1||ret[y]>x) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
