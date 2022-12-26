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


//A051584

ll N;

set<int> H[1010100];

ll issq(ll V) {
	ll a=sqrt(V);
	if(a*a==V) return a;
	if((a-1)*(a-1)==V) return a-1;
	if((a+1)*(a+1)==V) return a+1;
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll M=N*N;
	vector<ll> A;
	for(i=1;1LL*i*i<=M;i++) if(M%i==0) {
		A.push_back(i);
		if(1LL*i*i!=M) A.push_back(M/i);
	}
	
	sort(ALL(A));
	
	int num=0;
	FOR(x,A.size()) {
		if(A[x]>N) break;
		for(y=x;y<A.size();y++) {
			if(A[y]>N) break;
			if(M%(A[x]*A[y])) continue;
			ll c=-M/(A[x]*A[y]);
			ll b=A[x]+A[y];
			ll d=b*b-4*c;
			if(d<0) continue;
			ll v=issq(d);
			if(v<0) continue;
			v-=b;
			if(v<0) continue;
			if(v%2) continue;
			if(A[y]<=v/2 && v/2<N) num++;
			
			
			
		}
	}
	
	
	
	
	cout<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
