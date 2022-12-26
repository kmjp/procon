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

ll mo=1000000007;
ll H,W;

ll A[3030303];
vector<int> P[3030303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	ll ret=0;
	// â°Ç∆èc
	ret=((W-1)*H+(H-1)*W)%mo;
	
	for(y=1;y<=H-1;y++) A[y]=H-y;
	for(y=1;y<=3000000;y++) {
		for(i=y*2;i<=3000000;i+=y) A[y]+=A[i];
		A[y]%=mo;
	}
	
	for(y=2;y<=3010101;y++) if(P[y].empty()) {
		for(i=y;i<=3010101;i+=y) P[i].push_back(y);
	}
	
	ll v=0;
	for(x=1;x<=W-1;x++) {
		int mask;
		ll tot=0;
		FOR(mask,1<<P[x].size()) {
			ll v=1;
			FOR(i,P[x].size()) if(mask&(1<<i)) v*=P[x][i];
			if(__builtin_popcount(mask)%2==0) tot+=A[v];
			else tot-=A[v];
		}
		ret+=tot%mo*(W-x)*2%mo;
	}
	cout<<(ret%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
