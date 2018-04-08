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

int M,K;

bool cmp(const pair<int,int>& L,const pair<int,int>& R) {
	return 1LL*L.first*R.second<1LL*L.second*R.first;
}

set<pair<int,int>, bool(*)(const pair<int,int>&,const pair<int,int>&)> S(cmp);

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>K;
	for(i=2;i<=M;i++) S.insert({1,i});
	FOR(i,K) {
		if(S.empty()) return _P("-1\n");
		pair<int,int> p=*S.begin();
		S.erase(p);
		
		if(i==K-1) {
			cout<<p.first<<" "<<p.second<<endl;
			break;
		}
		
		p.first++;
		while(__gcd(p.first,p.second)>1) p.first++;
		if(p.first<p.second) S.insert(p);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
