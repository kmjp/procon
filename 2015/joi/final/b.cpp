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
int A[4020];
ll I[2080][2080];
ll J[2080][2080];

ll ioi(int start,int len);
ll joi(int start,int len){
	start%=N;
	if(J[start][len]>=0) return J[start][len];
	
	if(len==0) return 0;
	if(len==1) return A[start];
	return J[start][len] = max(A[start]+ioi(start+1,len-1),A[start+len-1]+ioi(start,len-1));
}

ll ioi(int start,int len) {
	start%=N;
	if(I[start][len]>=0) return I[start][len];
	
	if(len<=1) return 0;
	if(A[start]>A[start+len-1]) {
		return I[start][len] = joi(start+1,len-1);
	}
	else {
		return I[start][len] = joi(start,len-1);
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], A[i+N]=A[i];
	
	MINUS(I);
	MINUS(J);
	
	ll ma=0;
	FOR(i,N) ma=max(ma,A[i]+ioi(i+1,N-1));
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
