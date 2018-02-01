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

int N,M;
vector<pair<int,int>> S[101010];
set<vector<int>> V;
int ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>r>>y;
		if(x!=r) S[y].push_back({min(x,r),max(x,r)});
	}
	
	for(i=1;i<=100000;i++) V.insert({i,i,i});
	
	for(y=100000;y>=0;y--) {
		FORR(e,S[y]) {
			vector<int> L={e.first,1000000,-1};
			vector<int> R={e.second,1000000,-1};
			
			while(1) {
				auto it=V.lower_bound({e.first,0,0});
				if(it==V.end()) break;
				vector<int> v=*it;
				if(v[0]>e.second) break;
				V.erase(it);
				x=v[0];
				if(x-e.first<=e.second-x) {
					L[1]=min(L[1],v[1]);
					L[2]=max(L[2],v[2]);
				}
				else {
					R[1]=min(R[1],v[1]);
					R[2]=max(R[2],v[2]);
				}
			}
			if(L[1]<=L[2]) V.insert(L);
			if(R[1]<=R[2]) V.insert(R);
		}
	}
	FORR(s,V) {
		for(x=s[1];x<=s[2];x++) ret[x]=s[0];
	}
	FOR(i,M) {
		cin>>x;
		cout<<ret[x]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
