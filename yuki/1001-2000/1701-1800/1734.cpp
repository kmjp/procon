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
int A[202020];

set<pair<int,int>> seg;
set<pair<int,int>> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	seg.insert({-1,0});
	seg.insert({1,202020});
	seg.insert({303030,0});
	cand.insert({202020,1});
	cand.insert({0,303030});
	

	int ret=0;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		
		auto it=seg.lower_bound({x+1,-1});
		it--;
		if(it->first+it->second-1<x) continue;
		ret++;
		y=x-it->first+1;
		vector<pair<int,int>> V;
		while(cand.rbegin()->first>=y) {
			V.push_back(*cand.rbegin());
			cand.erase(*cand.rbegin());
		}
		FORR2(a,b,V) {
			seg.erase({b,a});
			if(y>1) {
				seg.insert({b,y-1});
				cand.insert({y-1,b});
			}
			if(a>y) {
				seg.insert({b+y,a-y});
				cand.insert({a-y,b+y});
			}
			
		}
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
