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


int N,Q;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<int> M;
	cin>>N>>Q;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		if(A[i]>1) M.insert(i);
	}
	while(Q--) {
		int T,X,Y;
		cin>>T>>X>>Y;
		if(T==1) {
			M.erase(X);
			A[X]=Y;
			if(A[X]>1) M.insert(X);
		}
		else {
			auto it=M.lower_bound(Y+1);
			if(M.begin()==it) {
				if((Y-X)%2) {
					cout<<"S"<<endl;
				}
				else {
					cout<<"F"<<endl;
				}
			}
			else {
				it--;
				if(*it<X) {
					if((Y-X)%2) {
						cout<<"S"<<endl;
					}
					else {
						cout<<"F"<<endl;
					}
				}
				else {
					if((Y-*it)%2) {
						cout<<"S"<<endl;
					}
					else {
						cout<<"F"<<endl;
					}
				}
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
