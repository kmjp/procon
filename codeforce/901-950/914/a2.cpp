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
int A,B,X[2],Y[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B;
		vector<pair<int,int>> V={{A,B},{-A,B},{A,-B},{-A,-B}};
		map<pair<int,int>,int> M;
		
		cin>>X[0]>>Y[0]>>X[1]>>Y[1];
		FOR(i,2) {
			FORR2(a,b,V) {
				M[{X[i]+a,Y[i]+b}]++;
				if(abs(a)!=abs(b)) M[{X[i]+b,Y[i]+a}]++;
			}
		}
		int ret=0;
		FORR2(a,b,M) if(b==2) ret++;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
