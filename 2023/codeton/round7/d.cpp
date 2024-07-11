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
int N,Q;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		int sum=0;
		set<int> one;
		FOR(i,N) {
			cin>>A[i];
			sum+=A[i];
			if(A[i]==1) one.insert(i);
		}
		while(Q--) {
			cin>>i;
			if(i==1) {
				cin>>x;
				int ok=0;
				if(x%2==sum%2) {
					if(sum>=x) ok=1;
				}
				else if(one.size()) {
					if(sum-(2**one.begin()+1)>=x) ok=1;
					if(sum-(2*(N-1-*one.rbegin())+1)>=x) ok=1;
				}
				
				
				if(ok) {
					cout<<"YES"<<endl;
				}
				else {
					cout<<"NO"<<endl;
				}
			}
			else {
				cin>>x>>y;
				x--;
				if(A[x]==y) continue;
				one.erase(x);
				sum-=A[x];
				A[x]=y;
				sum+=A[x];
				if(A[x]==1) one.insert(x);
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
