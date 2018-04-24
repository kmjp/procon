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

vector<pair<int,ll>> A,B;
vector<pair<int,ll>> ret;

void add(int a,ll b) {
	if(b==0) return;
	if(ret.empty() || ret.back().first!=a) ret.push_back({a,0});
	ret.back().second+=b;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll tot=1LL<<50;
	cin>>x;
	FOR(i,x) {
		cin>>j>>k;
		tot-=k;
		A.push_back({j,k});
	}
	A.insert(A.begin(),{0,tot});
	tot=1LL<<50;
	cin>>x;
	FOR(i,x) {
		cin>>j>>k;
		tot-=k;
		B.push_back({j,k});
	}
	B.insert(B.begin(),{0,tot});
	int c=0;
	
	while(A.size()) {
		ll mi=min(A.back().second,B.back().second);
		x=A.back().first+B.back().first;
		A.back().second-=mi;
		B.back().second-=mi;
		if(A.back().second==0) A.pop_back();
		if(B.back().second==0) B.pop_back();
		
		if(c==0) {
			if(x>=10) {
				add(x%10,1);
				add((x+1)%10,mi-1);
				c=1;
			}
			else {
				add(x,mi);
			}
		}
		else if(c==1) {
			if(x>=10) {
				add((x+1)%10,mi);
				c=1;
			}
			else if(x==9) {
				add(0,mi);
				c=1;
			}
			else {
				add(x+1,1);
				add(x,mi-1);
				c=0;
			}
		}
	}
	while(ret.size()>1 && ret.back().first==0) ret.pop_back();
	reverse(ALL(ret));
	cout<<ret.size()<<endl;
	FORR(a,ret) cout<<a.first<<" "<<a.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
