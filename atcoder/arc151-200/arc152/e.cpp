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
int W[1<<18];
ll S[1<<18];

int ok[18];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	x=0;
	vector<ll> A;
	FOR(i,(1<<N)-1) {
		cin>>x;
		A.push_back(x);
	}
	FOR(i,N) ok[i]=2;
	
	
	for(int cur=N-1;cur>=0;cur--) {
		FORR(a,A) {
			if(a&(1<<cur)) ok[cur]=1;
		}
		
		vector<ll> B;
		int state=0;
		FORR(a,A) {
			if(a&(1<<cur)) {
				if(state==0) {
					B.push_back(a);
					state=1;
				}
				else {
					B.back()^=a;
					state=0;
				}
			}
			else if(state) {
				B.back()^=a;
			}
			else {
				B.push_back(a);
			}
		}
		A=B;
	}
	
	int ret=1;
	FOR(i,N) ret*=ok[i];
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
