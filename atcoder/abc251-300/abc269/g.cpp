#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
int A[202020],B[202020],C[404040];
int D[404040];
const int E=202020;
deque<pair<int,int>> Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int S=0;
	
	FOR(i,N) {
		cin>>A[i]>>B[i];
		if(A[i]!=B[i]) C[B[i]-A[i]+E]++;
		S+=A[i];
	}
	FOR(i,404040) D[i]=1<<30;
	D[E]=0;
	FOR(i,404040) if(C[i]) {
		int d=i-E;
		int e=C[i];
		if(d>0) {
			FOR(j,d) {
				Q.clear();
				for(x=j;x<404040;x+=d) {
					if(D[x]<1<<30) {
						y=D[x];
						k=y-x/d;
						while(Q.size()&&Q.back().second>=k) Q.pop_back();
						Q.push_back({x,k});
					}
					if(Q.size()&&Q.front().first+e*d<x) Q.pop_front();
					if(Q.size()) D[x]=min(D[x],Q.front().second+x/d);
				}
			}
		}
		else {
			d=-d;
			FOR(j,d) {
				Q.clear();
				for(x=404040-1-j;x>=0;x-=d) {
					if(D[x]<1<<30) {
						y=D[x];
						k=y+x/d;
						while(Q.size()&&Q.back().second>=k) Q.pop_back();
						Q.push_back({x,k});
					}
					if(Q.size()&&Q.front().first-e*d>x) Q.pop_front();
					if(Q.size()) D[x]=min(D[x],Q.front().second-x/d);
				}
			}
		}
	}
	
	FOR(i,M+1) {
		int d=i-S;
		if(D[d+E]>=1<<30) {
			cout<<-1<<endl;
		}
		else {
			cout<<D[d+E]<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
