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

int N,Q;
int A[201010];
int B[201010];
multiset<int> p,n;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	ll S=0,T=0;
	FOR(i,2*N) cin>>A[i], S+=A[i];
	FOR(i,2*N) {
		cin>>B[i];
		B[i]-=A[i];
		if(i!=0 && i!=2*N-1) {
			if(B[i]>0) {
				p.insert(B[i]);
				T+=B[i];
			}
			else {
				n.insert(-B[i]);
			}
		}
	}
	while(Q--) {
		cin>>i>>x>>y;
		i--;
		S-=A[i];
		if(i!=0 && i!=2*N-1) {
			if(B[i]>0) {
				p.erase(p.find(B[i]));
				T-=B[i];
			}
			else {
				n.erase(n.find(-B[i]));
			}
		}
		
		A[i]=x;
		S+=x;
		B[i]=y-A[i];
		if(i!=0 && i!=2*N-1) {
			if(B[i]>0) {
				p.insert(B[i]);
				T+=B[i];
			}
			else {
				n.insert(-B[i]);
			}
		}
		
		ll ma=0;
		if(p.size()%2==0) ma=S+T;
		else ma=S+max(T-*p.begin(),T-*n.begin());
		cout<<ma<<endl;
		
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
