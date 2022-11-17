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
int A[666666];
int C[666666];
set<int> P[606060];
int L[606060],R[606060];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		C[A[i]]++;
		x=A[i];
		y=0;
		while(x%2==0) {
			x/=2;
			y++;
		}
		P[x].insert(y);
	}
	
	for(i=1;i<=2*M;i+=2) R[i]=100;
	int ng=0;
	for(i=1;i<=2*M;i+=2) {
		auto it=P[i].lower_bound(R[i]);
		if(it==P[i].begin()) {
			ng=1;
			break;
		}
		R[i]=*prev(it);
		for(j=i*2;j<=2*M;j+=i) if(j%2) R[j]=min(R[j],R[i]);
	}
	for(i=2*M-1;i>=1;i-=2) {
		L[i]=-1;
		for(j=i*2;j<=2*M;j+=i) if(j%2) L[i]=max(L[j],L[i]);
		auto it=P[i].lower_bound(L[i]+1);
		if(it==P[i].end()) {
			ng=1;
			break;
		}
		L[i]=*it;
	}
	
	FOR(i,N) {
		if(ng) {
			cout<<"No"<<endl;
		}
		else {
			x=A[i];
			y=0;
			while(x%2==0) {
				x/=2;
				y++;
			}
			if(L[x]<=y&&y<=R[x]) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
