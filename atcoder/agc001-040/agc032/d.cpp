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
ll A,B;
int pos[5050];

ll from[10101];
ll to[10101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) {
		cin>>x;
		pos[x]=i*2+1;
	}
	
	for(i=1;i<=N;i++) {
		ll mi=1LL<<60;
		FOR(j,2*N+1) {
			mi=min(mi,from[j]);
			if(j%2==0) {
				if(j<pos[i]) to[j]=mi+B;
				if(j>pos[i]) to[j]=mi+A;
			}
			else if(j==pos[i]) to[j]=mi;
			else to[j]=1LL<<60;
		}
		
		swap(to,from);
	}
	
	
	cout<<*min_element(from,from+2*N+1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
