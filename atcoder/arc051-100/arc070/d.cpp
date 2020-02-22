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
int A[5050];
bitset<8192> L[5050],R[5050];
ll LT[5050],RT[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	L[0][0]=1;
	R[N+1][0]=1;
	FOR(i,N) {
		bitset<8192> T=L[i];
		T<<=A[i];
		L[i+1]=L[i] | T;
		if(L[i].count() != T.count()) L[i+1][8191]=1;
		LT[i+1]=LT[i]+A[i];
	}
	for(i=N-1;i>=0;i--) {
		bitset<8192> T=R[i+2];
		T<<=A[i];
		R[i+1]=R[i+2] | T;
		if(R[i+2].count() != T.count()) R[i+1][8191]=1;
		RT[i+1]=RT[i+2]+A[i];
	}
	
	int ret=0;
	FOR(i,N) {
		ll LB=max(0,K-A[i]);
		ll RB=K-1;
		deque<int> AA,BB;
		FOR(x,8192) if(R[i+2][x]) AA.push_back(x);
		
		int hoge=1;
		FOR(x,8192) if(L[i][x]) {
			ll LB2=LB-x,RB2=RB-x;
			while(AA.size() && AA.back()>=LB2) BB.push_front(AA.back()),AA.pop_back();
			while(BB.size() && BB.back()>RB2) BB.pop_back();
			if(BB.size()) {
				hoge=0;
				break;
			}
		}
		
		ret+=hoge;
		
		
	}
	
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
