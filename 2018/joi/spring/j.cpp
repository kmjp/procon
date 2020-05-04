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
ll A[202020];

ll sum=0;
set<pair<ll,ll>> R;
set<int> alive;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		R.insert({-A[i],i});
		alive.insert(i);
	}
	
	ll sum=0;
	FOR(i,(N+1)/2) {
		auto v=*R.begin();
		R.erase(R.begin());
		sum+=-v.first;
		cout<<sum<<endl;
		if(i==(N+1)/2-1) break;
		x=v.second;
		
		auto it=alive.find(x);
		if(it==alive.begin()) {
			alive.erase(x);
			x=*alive.begin();
			R.erase({-A[x],x});
			alive.erase(alive.begin());
		}
		else if(next(it)==alive.end()) {
			alive.erase(x);
			x=*alive.rbegin();
			R.erase({-A[x],x});
			alive.erase(x);
		}
		else {
			j=*prev(it);
			k=*next(it);
			alive.erase(x);
			alive.erase(k);
			R.erase({-A[j],j});
			R.erase({-A[x],x});
			R.erase({-A[k],k});
			A[j]=A[j]+A[k]-A[x];
			R.insert({-A[j],j});
		}
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
