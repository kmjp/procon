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
ll A[101];
vector<ll> cand;
map<ll,ll> memo;

ll num(ll x) {
	if(x==1) return 1;
	if(memo.count(x)) return memo[x];
	
	ll ret=x+1;
	FORR(c,cand) {
		if(x%c==0) ret=max(ret,1+c*num(x/c));
		if(c>=x) break;
	}
	return memo[x]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	ll tot=0;
	FOR(i,N) {
		cin>>A[i];
		cand.clear();
		for(ll a=2;a*a<=A[i];a++) if(A[i]%a==0) {
			cand.push_back(a);
			cand.push_back(A[i]/a);
		}
		sort(ALL(cand));
		
		tot+=num(A[i]);
	}
	cout<<tot<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
