#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[2000],B[2000],L[2000];
int num[2000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	int mi=10000;
	FOR(i,N) {
		ZERO(num);
		priority_queue<pair<int,int> > P;
		FOR(x,N) L[x]=A[x];
		FOR(x,N) P.push(make_pair(-L[x]*100000,x));
		
		FOR(x,N) {
			pair<int,int> p=P.top();
			P.pop();
			num[p.second]++;
			L[p.second] += B[(i+x)%N]/2;
			P.push(make_pair(-L[p.second]*100000-num[p.second],p.second));
		}
		mi=min(mi,*max_element(num,num+N));
		
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
