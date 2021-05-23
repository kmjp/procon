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

int N,Q,L,R,X;
map<int,ll> num;
set<pair<int,int>> S;
ll sum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		sum+=num[x];
		num[x]++;
		S.insert({i,x});
	}
	S.insert({-1,0});
	S.insert({N,0});
	
	cin>>Q;
	while(Q--) {
		cin>>L>>R>>X;
		L--;
		auto it=S.lower_bound({L,0});
		if(it->first!=L) S.insert({L,prev(it)->second});
		it=S.lower_bound({R,0});
		if(it->first!=R) S.insert({R,prev(it)->second});
		while(1) {
			auto it=S.lower_bound({L,0});
			if(it->first==R) break;
			auto it2=next(it);
			x=it2->first-it->first;
			y=it->second;
			S.erase(it);
			sum-=num[y]*(num[y]-1)/2;
			num[y]-=x;
			sum+=num[y]*(num[y]-1)/2;
		}
		S.insert({L,X});
		sum-=num[X]*(num[X]-1)/2;
		num[X]+=R-L;
		sum+=num[X]*(num[X]-1)/2;
		
		
		
		cout<<sum<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
