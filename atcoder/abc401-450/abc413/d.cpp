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

int T;
int N;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> A[2];
		FOR(i,N) {
			cin>>x;
			if(x>=0) A[0].push_back(x);
			else A[1].push_back(-x);
		}
		sort(ALL(A[0]));
		sort(ALL(A[1]));
		if(A[0].empty()) swap(A[0],A[1]);
		vector<ll> V;
		if(A[1].empty()) {
			V=A[0];
		}
		else {
			if(A[0].size()+1==A[1].size()) {
				FOR(i,A[0].size()) {
					V.push_back(A[1][i]);
					V.push_back(A[0][i]);
				}
				V.push_back(A[1][i]);
			}
			else if(A[1].size()+1==A[0].size()) {
				FOR(i,A[1].size()) {
					V.push_back(A[0][i]);
					V.push_back(A[1][i]);
				}
				V.push_back(A[0][i]);
			}
			else if(A[0].size()==A[1].size()&&A[0][0]<A[1][0]) {
				FOR(i,A[1].size()) {
					V.push_back(A[0][i]);
					V.push_back(A[1][i]);
				}
			}
			else if(A[0].size()==A[1].size()) {
				FOR(i,A[1].size()) {
					V.push_back(A[1][i]);
					V.push_back(A[0][i]);
				}
			}
			else {
				cout<<"No"<<endl;
				continue;
			}
		}
		FOR(i,N-1) if(V[i+1]*V[0]!=V[i]*V[1]) break;
		if(i==N-1) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
