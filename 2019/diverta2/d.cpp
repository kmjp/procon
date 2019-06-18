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
ll G[2],A[2],B[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2) cin>>G[i]>>A[i]>>B[i];
	
	if(G[0]>=G[1] && A[0]>=A[1] && B[0]>=B[1]) {
		swap(G[0],G[1]);
		swap(A[0],A[1]);
		swap(B[0],B[1]);
	}
	
	ll ret=N;
	if(G[0]<=G[1]&&A[0]<=A[1]&&B[0]<=B[1]) {
		for(x=0;x<=N;x+=G[0]) {
			for(y=0;x+y<=N;y+=A[0]) {
				int z=(N-x-y)/B[0]*B[0];
				ll cur=(N-x-y-z)+x/G[0]*G[1]+y/A[0]*A[1]+z/B[0]*B[1];
				ret=max(ret,cur);
			}
		}
	}
	else {
		if(G[0]>=G[1]&&A[0]<A[1]) swap(G[0],A[0]),swap(G[1],A[1]);
		if(A[0]>=A[1]&&B[0]<B[1]) swap(B[0],A[0]),swap(B[1],A[1]);
		if(G[0]>=G[1]&&A[0]<A[1]) swap(G[0],A[0]),swap(G[1],A[1]);
		
		
		if(A[0]<A[1]) {
			for(x=0;x<=N;x+=G[0]) {
				for(y=0;x+y<=N;y+=A[0]) {
					ll cur=(N-x-y)+x/G[0]*G[1]+y/A[0]*A[1];
					ll v=cur/B[1];
					cur=cur%B[1]+v*B[0];
					ret=max(ret,cur);
				}
			}
		}
		else {
			ll v=N/G[0];
			ll cur=N%G[0]+v*G[1];
			for(x=0;x<=cur;x+=A[1]) {
				y=(cur-x)/B[1]*B[1];
				ll ncur=(cur-x-y)+x/A[1]*A[0]+y/B[1]*B[0];
				ret=max(ret,ncur);
			}
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
