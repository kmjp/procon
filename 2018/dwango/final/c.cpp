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

int M;
vector<pair<int,ll>> V;

vector<pair<int,ll>> half(vector<pair<int,ll>> V) {
	vector<pair<int,ll>> R;
	int x=1;
	FORR(v,V) {
		R.push_back({v.first,(v.second+x)/2});
		x ^= v.second%2;
	}
	return R;
}

vector<pair<int,ll>> step(vector<pair<int,ll>> V) {
	int i;
	vector<pair<int,ll>> R;
	FOR(i,V.size()) {
		if(V[i].second>2) R.push_back({V[i].first,V[i].second-2});
		if(V[i].second>=2 && i<V.size()-1) R.push_back({V[i+1].first,1});
		if(V[i].second>=1 && i<V.size()-1) {
			if(V[i+1].second>=2) R.push_back({V[i].first,1});
			else if(i<V.size()-2) R.push_back({V[i].first^V[i+1].first^V[i+2].first,1});
		}
	}
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		if(V.empty() || V.back().first!=x) V.push_back({x,0});
		V.back().second+=y;
	}
	
	while(1) {
		if(V.size()==1 && V[0].second==1) {
			cout<<V[0].first<<endl;
			return;
		}
		
		vector<pair<int,ll>> V2;
		ll L=0;
		FORR(v,V) if(v.second) {
			if(V2.empty() || V2.back().first!=v.first) V2.push_back({v.first,0});
			V2.back().second+=v.second;
			L+=v.second;
		}
		
		if((L-1)%4==0) {
			V=half(V2);
		}
		else {
			V=step(V2);
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
