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

int N,K;
int A[51];
pair<int,int> P[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	K++;
	int sum=0;
	FOR(i,N) {
		cin>>A[i];
	}
	
	vector<int> T;
	int pre=-1;
	while(K--) {
		int mi=1010,tar=-1;
		FOR(i,N) if(i!=pre) {
			if(A[i]==0) return _P("-1\n");
			if(A[i]<mi) mi=A[i],tar=i;
		}
		FOR(i,N) if(i!=pre&&i!=tar) {
			T.push_back(i+1);
			A[i]--;
		}
		T.push_back(tar+1);
		A[tar]--;
		pre=tar;
	}
	
	cout<<T.size()<<endl;
	FORR(t,T) cout<<t<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
