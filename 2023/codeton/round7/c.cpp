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

int T,N,X;
int A[202020],B[202020];
int C[202020],D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X;
		FOR(i,N) {
			cin>>A[i];
			C[i]=A[i];
		}
		FOR(i,N) {
			cin>>B[i];
			D[i]=B[i];
		}
		sort(C,C+N);
		sort(D,D+N);
		rotate(D,D+X,D+N);
		x=0;
		multiset<pair<int,int>> V;
		FOR(i,N) {
			if(C[i]>D[i]) x++;
			V.insert({C[i],D[i]});
		}
		if(x==X) {
			cout<<"YES"<<endl;
			FOR(i,N) {
				auto it=V.lower_bound({A[i],0});
				cout<<it->second<<" ";
				V.erase(it);
			}
			cout<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
