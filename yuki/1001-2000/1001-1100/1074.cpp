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

class AreaRect {
	map<ll,ll> M;
public:
	ll sum;
	AreaRect() {
		M[0]=1LL<<60;
		M[1LL<<60]=0;
		sum=0;
	}
	void add(ll x,ll y) {
		auto k=M.lower_bound(x);
		if(k->second>=y) return;
		while(prev(M.lower_bound(x))->second<=y) {
			auto p=*prev(M.lower_bound(x));
			M.erase(p.first);
			sum-=(p.first-prev(M.lower_bound(p.first))->first)*(p.second-M.lower_bound(p.first)->second);
		}
		sum += (x-prev(M.lower_bound(x))->first)*(y-M.lower_bound(x)->second);
		M[x]=y;
	}
};

AreaRect M[4];

int N;
int X1,X2,Y1,Y2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll pre=0;
	FOR(i,N) {
		cin>>X1>>Y1>>X2>>Y2;
		M[0].add(-X1,-Y1);
		M[1].add(-X1,Y2);
		M[2].add(X2,-Y1);
		M[3].add(X2,Y2);
		ll sum=M[0].sum+M[1].sum+M[2].sum+M[3].sum;
		cout<<sum-pre<<endl;
		pre=sum;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
