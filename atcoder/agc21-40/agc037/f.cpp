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
int A[202020];
int L[202020];
int R[202020];
set<int> S;
set<pair<int,int>> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	A[0]=1LL<<30;
	A[N+1]=1LL<<30;
	
	S.insert(0);
	S.insert(N+1);
	cand.insert({1<<30,0});
	for(i=1;i<=N;i++) {
		cin>>A[i];
		L[i]=R[i]=1;
		S.insert(i);
		cand.insert({A[i],i});
	}
	
	ll ret=N;
	while(1) {
		auto c=*cand.begin();
		/*
		FORR(a,cand) cout<<a.first<<":"<<a.second<<" ";
		cout<<ret<<endl;
		*/
		
		if(c.first>=1<<30) break;
		x=y=c.second;
		
		vector<vector<int>> V;
		while(1) {
			//cout<<"take"<<y<<endl;
			V.push_back({y,L[y],R[y]});
			S.erase(y);
			cand.erase({A[y],y});
			y=*S.lower_bound(y+1);
			if(A[y]!=A[x]) break;
		}
		
		/*
		cout<<"!";
		FORR(v,V) cout<<v[0]<<":"<<v[1]<<":"<<v[2]<<"  ";
		cout<<endl;
		*/
		
		int nl=V.size();
		int ns=nl/M;
		if(ns==0) {
			A[x]=1<<30;
			S.insert(x);
			continue;
		}
		
		int RT=0;
		for(i=M-1;i<V.size();i++) RT+=V[i][2];
		FOR(i,V.size()-M+1) {
			//cout<<"ok"<<V[i][1]<<" "<<RT<<endl;
			ret+=1LL*V[i][1]*RT;
			RT-=V[i+M-1][2];
		}
		FOR(i,ns) L[x+i]=R[x+i]=0;
		FOR(i,V.size()) {
			if(i>=M-1) R[x+(i+1)/M-1]+=V[i][2];
			j=V.size()-1-i;
			if(j>=M-1) {
				j=(j+1)/M-1;
				L[x+ns-1-j]+=V[i][1];
			}
		}
		
		RT=0;
		for(i=M-1;i<ns;i++) RT+=R[x+i];
		FOR(i,ns-M+1) {
			ret-=1LL*L[x+i]*RT;
			RT-=R[x+i+M-1];
		}
		
		A[x]++;
		FOR(i,ns) {
			A[x+i]=A[x];
			cand.insert({A[x+i],x+i});
			S.insert(x+i);
		}
		
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
