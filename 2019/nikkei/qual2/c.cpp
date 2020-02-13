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
int A[101010],ok[101010];
int B[101010];
pair<int,int> P[101010];
set<int> add[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) {
		P[i]={B[i],A[i]};
	}
	sort(A,A+N);
	sort(B,B+N);
	FOR(i,N) {
		if(B[i]<A[i]) return _P("No\n");
	}
	sort(P,P+N);
	FOR(i,N) {
		A[i]=P[i].second;
		B[i]=P[i].first;
	}
	FOR(i,N) {
		ok[i]=lower_bound(B,B+N,A[i])-B;
		//cout<<i<<" "<<A[i]<<" "<<B[i]<<" "<<ok[i]<<endl;
		add[ok[i]].insert(i);
	}
	
	set<int> S;
	FOR(i,N-1) {
		FORR(e,add[i]) S.insert(e);
		//cout<<i<<" "<<S.size()<<endl;
		assert(S.size());
		if(S.count(i)) return _P("Yes\n");
		
		x=*S.rbegin();
		S.erase(x);
		swap(A[i],A[x]);
		swap(ok[i],ok[x]);
		add[ok[x]].erase(i);
		add[ok[x]].insert(x);
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
