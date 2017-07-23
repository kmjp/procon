#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
vector<int> V;
vector<pair<int,int>> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int zero=0;
	FOR(i,K) {
		cin>>x;
		if(x==0) zero=1;
		else V.push_back(x);
	}
	sort(ALL(V));
	R.push_back({-2,0});
	FORR(r,V) {
		if(r==R.back().first+R.back().second) {
			R.back().second++;
		}
		else {
			R.push_back({r,1});
		}
	}
	
	int ma=0;
	for(i=1;i<R.size();i++) {
		ma=max(ma,R[i].second);
		if(R[i-1].first+R[i-1].second+zero==R[i].first) ma=max(ma,R[i-1].second+R[i].second+1);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
