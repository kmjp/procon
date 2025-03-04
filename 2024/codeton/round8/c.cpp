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

int T,N,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>Y;
		vector<int> A;
		FOR(i,X) {
			cin>>x;
			A.push_back(x-1);
		}
		sort(ALL(A));
		vector<int> V[2];
		int ret=X-2;
		FOR(i,A.size()-1) {
			x=A[i+1]-A[i];
			if(x==1) continue;
			if(x==2) {
				ret++;
				continue;
			}
			V[x%2].push_back(x);
		}
		x=A[0]+N-A.back();
		if(x==2) ret++;
		if(x>=3) V[x%2].push_back(x);
		sort(ALL(V[0]));
		sort(ALL(V[1]));
		reverse(ALL(V[1]));
		FORR(v,V[0]) {
			int a=min(Y,v/2-1);
			if(a==v/2-1) {
				ret+=v-1;
			}
			else {
				ret+=a*2;
			}
			Y-=a;
		}
		FORR(v,V[1]) {
			int a=min(Y,v/2);
			ret+=a*2;
			Y-=a;
		}
		
		
		cout<<min(N-2,ret)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
