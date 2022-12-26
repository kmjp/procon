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

int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	int pre=0;
	vector<pair<int,int>> V;
	FOR(i,N) {
		cin>>x;
		if(i==0) V.push_back({x,i});
		else {
			if(__gcd(x,V.back().first)<V.back().first) V.push_back({__gcd(x,V.back().first),i});
		}
	}
	
	FOR(i,Q) {
		cin>>x;
		FOR(j,V.size()) {
			x=__gcd(x,V[j].first);
			if(x==1) {
				cout<<V[j].second+1<<endl;
				break;
			}
		}
		if(j==V.size()) cout<<x<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
