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


int N;
pair<int,int> P[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first;
	}
	FOR(i,N) {
		cin>>P[i].second;
	}
	
	vector<int> A,B;
	A={P[0].first};
	B={P[0].second};
	for(i=1;i<N;i++) {
		
		while(A.size()&&(A.back()>P[i].first)) {
			A.pop_back();
			B.pop_back();
		}
		A.push_back(P[i].first);
		B.push_back(P[i].second);
	}
	
	while(A.back()!=A[0]&&A.back()>B[0]) {
		A.pop_back();
		B.pop_back();
	}
	x=1<<30;
	FOR(i,A.size()) if(A[i]==A[0]) x=min(x,B[i]);
	if(x<=A[0]) {
		cout<<A[0]<<" "<<x<<endl;
		return;
	}
	int del=1;
	for(i=1;i<A.size();i++) {
		if(A[i]!=B[0]) {
			if(B[i]>B[i-1]) {
				del=0;
				break;
			}
			if(B[i]<B[i-1]) {
				del=1;
				break;
			}
		}
	}
	FOR(i,A.size()) {
		if(A[i]==B[0]&&del) continue;
		cout<<A[i]<<" ";
	}
	FOR(i,A.size()) {
		if(A[i]==B[0]&&del) continue;
		cout<<B[i]<<" ";
	}
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
