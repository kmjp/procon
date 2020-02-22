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

int N,Q;
int A[101010],B[101010],C[101010];
int D[101010],E[101010];
vector<int> ev[101010];

int minm;
int sum[101010];
int num[101010];
int ng[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	FOR(i,N+1) cin>>C[i];
	sort(C,C+N+1);
	
	FOR(i,N) {
		B[i]=min(A[i],B[i]);
		A[i]=lower_bound(C,C+N+1,A[i])-C;
		B[i]=lower_bound(C,C+N+1,B[i])-C;
		if(B[i]<A[i]) ev[B[i]].push_back(i);
	}
	
	minm=N+2;
	FOR(i,N+1) sum[i]=-1;
	FOR(i,N) sum[A[i]]++;
	
	priority_queue<pair<int,int>> P;
	vector<vector<int>> seg;
	int ret=N;
	FOR(i,N+1) {
		if(i) sum[i]+=sum[i-1], ng[i]+=ng[i-1];
		FORR(e,ev[i]) P.push({A[e],e});
		while(sum[i]<0 && P.size()) {
			int x=P.top().second;
			P.pop();
			sum[i]++;
			sum[A[x]]--;
			seg.push_back({i,A[x]});
			ret--;
		}
		if(sum[i]==-1) {
			minm=min(minm,i);
			ng[i]++;
		}
		if(sum[i]<-1) minm=-1;
	}
	
	int minL=N+2;
	for(i=seg.size()-1;i>=0;i--) {
		if(ng[seg[i][1]-1]==((seg[i][0])?ng[seg[i][0]-1]:0) && seg[i][1]<=minL) {
			num[seg[i][0]]++;
			minL=seg[i][0];
		}
	}
	
	for(i=N+1;i>=0;i--) num[i]+=num[i+1];
	cin>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		x=lower_bound(C,C+N+1,x)-C;
		y=lower_bound(C,C+N+1,y)-C;
		//cout<<x<<y<<" : ";
		int rx=(minm<x)?-1:(N-seg.size()+(num[x]+1));
		int ry=(minm<y)?-1:(N-seg.size()+num[y]);
		
		cout<<max(rx,ry)<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
