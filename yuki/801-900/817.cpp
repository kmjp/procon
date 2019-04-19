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

int N;
ll K;
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		M[x]++;
		M[y+1]--;
	}
	vector<pair<int,ll>> V;
	FORR(m,M) if(m.second) V.push_back(m);
	
	ll cur=0;
	FOR(i,V.size()-1) {
		cur+=V[i].second;
		if(K<=(V[i+1].first-V[i].first)*cur) {
			cout<<V[i].first+(K-1)/cur<<endl;
			return;
		}
		else {
			K-=(V[i+1].first-V[i].first)*cur;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
