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
ll A[65];
vector<ll> ret;

unsigned long long bitrev(unsigned long long x,int d=64) {
	x = (((x & 0xaaaaaaaaaaaaaaaaULL) >> 1) | ((x & 0x5555555555555555ULL) << 1));
	x = (((x & 0xccccccccccccccccULL) >> 2) | ((x & 0x3333333333333333ULL) << 2));
	x = (((x & 0xf0f0f0f0f0f0f0f0ULL) >> 4) | ((x & 0x0f0f0f0f0f0f0f0fULL) << 4));
	x = (((x & 0xff00ff00ff00ff00ULL) >> 8) | ((x & 0x00ff00ff00ff00ffULL) << 8));
	x = (((x & 0xffff0000ffff0000ULL) >>16) | ((x & 0x0000ffff0000ffffULL) <<16));
	x = ((x >> 32) | (x << 32));
	
	return x>>(64-d);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	
	ll did=0;
	set<ll> skip;
	for(i=N;i>=1;i--) {
		ll cur=0;
		set<ll> skip2;
		FOR(x,A[i]) {
			while(cur<1LL<<i) {
				ll val=bitrev(cur,i);
				cur++;
				if(skip.count(val)==0) {
					skip2.insert(val);
					ret.push_back((1LL<<i)+val);
					goto next;
				}
			}
			if(cur==1LL<<i) {
				ll a=*skip.begin();
				skip.erase(a);
				skip2.insert(a);
				ret.push_back((1LL<<i)+a);
			}
			next:
			;
		}
		set<ll> ns;
		FORR(e,skip) ns.insert(e/2);
		FORR(e,skip2) ns.insert(e/2);
		swap(skip,ns);
	}
	sort(ALL(ret));
	FORR(e,ret) cout<<e<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
