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

int N,M,K;
ll A[1010101];

set<pair<ll,ll>> R;
set<int> alive;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	
	ll sum=0;
	j=0;
	FOR(i,N) {
		cin>>x;
		sum+=x;
		if(x+x==M) {
			continue;
		}
		
		if(j==0) {
			A[j++]=M-x-x;
		}
		else if((M-x-x<=0) == (A[j-1]<=0)) {
			A[j-1]+=M-x-x;
		}
		else {
			A[j++]=M-x-x;
		}
	}
	int TL=0,TR=j-1;
	if(A[TL]<0) TL++;
	if(TR>=0 && A[TR]<0) TR--;
	
	int nm=0;
	for(i=TL;i<=TR;i++) {
		if(A[i]<0) {
			nm++;
			A[i]=-A[i];
		}
		else {
			sum+=A[i];
		}
		
		R.insert({A[i],i});
		alive.insert(i);
	}
	FOR(i,nm-K+1) {
		if(R.empty()) break;
		auto v=*R.begin();
		R.erase(R.begin());
		sum-=v.first;
		
		if(i==nm-K) break;
		x=v.second;
		
		auto it=alive.find(x);
		if(it==alive.begin()) {
			alive.erase(x);
			x=*alive.begin();
			R.erase({A[x],x});
			alive.erase(alive.begin());
		}
		else if(next(it)==alive.end()) {
			alive.erase(x);
			x=*alive.rbegin();
			R.erase({A[x],x});
			alive.erase(x);
		}
		else {
			j=*prev(it);
			k=*next(it);
			alive.erase(x);
			alive.erase(k);
			R.erase({A[j],j});
			R.erase({A[x],x});
			R.erase({A[k],k});
			A[j]=A[j]+A[k]-A[x];
			R.insert({A[j],j});
		}
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
