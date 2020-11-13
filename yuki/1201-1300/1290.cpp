#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll B[101010];
set<int> R[2020202];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>B[i];
	FOR(i,M) {
		cin>>x>>y;
		R[x-1].insert(y);
	}
	FOR(i,N) {
		if(R[i].size()) {
			x=*R[i].begin();
			R[i].erase(R[i].begin());
			if(R[x].size()<R[i].size()) swap(R[i],R[x]);
			FORR(v,R[i]) R[x].insert(v);
			R[i].clear();
			ll v=bt(i);
			if(i%2==0) {
				ll d=B[i]-v;
				bt.add(i,d);
				bt.add(x,-d);
			}
			else {
				ll d=B[i]-(-v);
				bt.add(i,-d);
				bt.add(x,d);
			}
		}
		if(i%2==0&&bt(i)!=B[i]) {
			cout<<"NO"<<endl;
			return;
		}
		if(i%2==1&&bt(i)!=-B[i]) {
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
