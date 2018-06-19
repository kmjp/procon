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

ll N;
uint32_t x = 0, y = 1, z = 2, w = 3;
uint32_t generate() { 
    uint32_t t = (x^(x<<11));
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
    return w;
}

vector<ll> cand;

void solve() {
	int i,j,k,l,r; string s;
	
	cin>>k;
	N=10000001;
	ll v=0;
	for(i=32;i>=0;i--) {
		x=k;
		y = 1, z = 2, w = 3;
		int num=0;
		FOR(j,N) if(generate()<=v+(1LL<<i)) num++;
		if(num<N/2+1) v+=1LL<<i;
		
	}
	cout<<v+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
