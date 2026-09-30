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

int N,Q;
vector<pair<int,char>> ev;
vector<int> tile[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	ev.push_back({0,'a'});
	FOR(i,N) tile[i].push_back(0);
	FOR(i,Q) {
		cin>>x;
		if(x==1) {
			cin>>y;
			tile[y-1].push_back(i+1);
		}
		else {
			cin>>s;
			ev.push_back({i+1,s[0]});
		}
	}
	
	FOR(i,N) {
		if(tile[i].size()%2) tile[i].push_back(Q+1);
		char ret='a';
		FOR(j,tile[i].size()/2) {
			int L=tile[i][j*2];
			int R=tile[i][j*2+1];
			x=lower_bound(ALL(ev),make_pair(R,'a'))-ev.begin();
			if(ev[x-1].first>=L) ret=ev[x-1].second;
		}
		cout<<ret;
		
		
	}
	cout<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
