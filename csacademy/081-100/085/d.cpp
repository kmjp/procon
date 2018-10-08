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
vector<int> X;
vector<pair<int,int>> ret;

void hoge(int v) {
	if(v==0 || K==0) {
		_P("%d ",v);
	}
	else {
		K--;
		hoge(v-1);
		hoge(v-1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ret.reserve(1<<20);
	X.push_back(40);
	FOR(i,N) {
		cin>>x;
		while(X.back()<x) {
			ret.push_back({X.back(),1});
			K--;
			X.back()++;
			while(X.size()>=2 && X.back()==X[X.size()-2]) X.pop_back(), X.back()++;
		}
		ret.push_back({x,0});
		X.push_back(x);
		while(X.size()>=2 && X.back()==X[X.size()-2]) X.pop_back(), X.back()++;
	}
	
	X.erase(X.begin());
	
	while(X.size()>1 || X.back()!=30) {
		
		if(X.size()>=2 && X.back()==X[X.size()-2]) {
			X.pop_back();
		}
		else {
			ret.push_back({X.back(),1});
			K--;
		}
		X.back()++;
		
	}
	assert(K>=0 && ret.size()<1<<20);
	FORR(r,ret) {
		if(r.second==0) {
			_P("%d ",r.first);
		}
		else {
			hoge(r.first);
		}
	}
	_P("\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
