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

int Q;
multiset<pair<int,int>> L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			L.insert({x,y});
			R.insert({y,x});
		}
		else if(i==2) {
			L.erase(L.find({x,y}));
			R.erase(R.find({y,x}));
		}
		else {
			int L1=x,R1=y,L2,R2;
			cin>>L2>>R2;
			if(L1==L2 && R1==R2) {
				cout<<0<<endl;
				continue;
			}
			if(R1<L2 || R2<L1) {
				cout<<1<<endl;
				continue;
			}
			if(L1>L2) swap(L1,L2), swap(R1,R2);
			auto it=L.lower_bound({max(R1,R2)+1,0});
			if(it!=L.end()) {
				cout<<2<<endl;
				continue;
			}
			it=R.lower_bound({min(L1,L2),0});
			if(it!=R.begin()) {
				cout<<2<<endl;
				continue;
			}
			if(R1>=R2) {
				cout<<-1<<endl;
				continue;
			}
			it=L.lower_bound({R1+1,0});
			if(it==L.end()) {
				cout<<-1<<endl;
				continue;
			}
			it=R.lower_bound({L2,0});
			if(it==R.begin()) {
				cout<<-1<<endl;
				continue;
			}
			cout<<3<<endl;
				
			
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
