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

int N,M;
set<int> W[101010],L[101010],NF[101010];
int R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		W[x].insert(y);
		L[y].insert(x);
	}
	FOR(i,N) W[i+1].insert(i+1),L[i+1].insert(i+1);
	for(i=1;i<=N;i++) {
		int cur=0;
		while(1) {
			auto it=W[i].lower_bound(cur);
			if(it==W[i].end()) break;
			cur=*it;
			while(W[i].count(cur)) cur++;
			NF[i].insert(cur);
		}
		
	}
	
	int A=0,B=1<<30;
	for(i=1;i<=N;i++) {
		R[i]=i+1;
		FORR(l,L[i]) {
			R[i]=max(R[i],*NF[l].lower_bound(i));
		}
		if(R[i]<=N && R[i]-i<B-A) A=i,B=R[i];
	}
	if(B==1<<30) {
		cout<<-1<<endl;
	}
	else {
		cout<<A<<" "<<B<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
