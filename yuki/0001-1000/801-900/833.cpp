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

//‚³‚ç‚É’Zk
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

set<int> S;
int N,Q;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=1;i<=N;i++) {
		cin>>x;
		bt.add(i,x);
		S.insert(i);
	}
	S.insert(0);
	S.insert(N+1);
	while(Q--) {
		cin>>i>>x;
		if(i==1) S.erase(x+1);
		if(i==2) S.insert(x+1);
		if(i==3) bt.add(x,1);
		if(i==4) {
			auto it=S.lower_bound(x);
			if(*it==x) {
				it++;
				y=*it;
			}
			else {
				y=*it;
				it--;
				x=*it;
			}
			cout<<(bt(y-1)-bt(x-1))<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
