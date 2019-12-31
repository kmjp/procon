#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>x, A.push_back(x-1);
	FOR(i,N) cin>>x, B.push_back(x-1);
	
	int mi=N;
	FOR(i,N) {
		int num=0;
		
		int rev[51]={};
		FOR(x,N) rev[A[x]]=x;
		FOR(x,N) {
			FOR(y,x) if(rev[B[y]]>rev[B[x]]) num++;
		}
		
		mi=min(mi,num);
		
		A.push_back(A[0]);
		A.erase(A.begin());
		B.push_back(B[0]);
		B.erase(B.begin());
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
