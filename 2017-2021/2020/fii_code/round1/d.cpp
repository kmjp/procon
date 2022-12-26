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

int N,X;
int A[202020];
ll S[2][202020];

ll pt(int cur,int ri) {
	ll ret= (S[ri%2][ri+1]-S[ri%2][cur])-(S[(ri+1)%2][ri]-S[(ri+1)%2][cur+1]);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i];
		sum+=A[i];
	}
	FOR(i,N) {
		S[0][i+1]=S[0][i];
		S[1][i+1]=S[1][i];
		if(i) S[i%2][i+1]+=min(X,A[i]+A[i-1]);
	}
	
	set<pair<ll,int>> C;
	set<int> alive;
	
	FOR(i,N-1) C.insert({min(X,A[i]+A[i+1]),i});
	alive.insert(-1);
	alive.insert(N);
	FOR(i,N) alive.insert(i);
	FOR(i,N/2) {
		auto it=C.rbegin();
		sum-=it->first;
		x=it->second;
		C.erase(*it);
		
		auto cur=alive.lower_bound(x);
		auto ri=next(cur);
		auto ri2=next(ri);
		auto le=prev(cur);
		x=*le;
		y=*ri2;
		j=*cur;
		r=*ri;
		
		if(y<N) C.erase({pt(r,y),r});
		if(x>=0) C.erase({pt(x,j),x});
		alive.erase(j);
		alive.erase(r);
		if(x>=0&&y<N) C.insert({pt(x,y),x});
		cout<<sum<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
