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
vector<int> A;
string S;
unsigned long long B[101010];

int ok(int v) {
	int i;
	ZERO(B);
	FOR(i,N) B[i/64] |= (1LL*(A[i]>=v))<<i%64;
	int len=N;
	FORR(c,S) {
		if(c=='m') {
			for(i=0;i*64<=len;i++) B[i]=(B[i]&(B[i]>>1)) | ((B[i+1]<<63)&B[i]);
		}
		else {
			for(i=0;i*64<=len;i++) B[i]=(B[i]|(B[i]>>1)) | ((B[i+1]<<63)|B[i]);
		}
		len--;
		B[len/64] &= ~(1LL<<(len%64));
	}
	return B[0];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>x, A.push_back(x);
	cin>>S;
	
	int ret=0;
	for(i=16;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
