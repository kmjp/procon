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
ll K;
int A[202020];
int is[202020];

int first[202020];
int nex[202020];
int idnex[202020];
int pat[202020];
int ne[202020][45];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	MINUS(first);
	FOR(i,N) {
		cin>>A[i];
		if(first[A[i]]==-1) first[A[i]]=i;
	}
	
	for(i=1;i<=200000;i++) nex[i]=N;
	for(i=N-1;i>=0;i--) {
		idnex[i]=nex[A[i]];
		nex[A[i]]=i;
	}
	pat[N]=0;
	for(i=N-1;i>=0;i--) {
		if(idnex[i]==N) {
			pat[i]=first[A[i]]+1;
		}
		else {
			pat[i]=pat[idnex[i]+1];
		}
	}
	/*
	FOR(i,N) cout<<pat[i]<<" ";
	cout<<endl;
	*/
	FOR(i,N+1) ne[i][0]=pat[i];
	int cur=0;
	K--;
	FOR(i,42) {
		FOR(j,N+1) ne[j][i+1]=ne[ne[j][i]][i];
		if(K&(1LL<<i)) cur=ne[cur][i];
	}
	
	
	vector<int> V;
	//cout<<"!"<<cur<<" "<<pat[cur]<<endl;
	for(i=cur;i<N;i++) {
		if(is[A[i]]) {
			while(V.back()!=A[i]) {
				is[V.back()]=0;
				V.pop_back();
			}
			is[A[i]]=0;
			V.pop_back();
		}
		else {
			is[A[i]]=1;
			V.push_back(A[i]);
		}
	}
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	/*
	while(K--) {
		FOR(i,N) {
			if(is[A[i]]) {
				while(V.back()!=A[i]) {
					is[V.back()]=0;
					V.pop_back();
				}
				is[A[i]]=0;
				V.pop_back();
			}
			else {
				is[A[i]]=1;
				V.push_back(A[i]);
			}
		}
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
