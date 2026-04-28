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
int X[202020],Y[202020],Z[202020];
vector<int> E[202020];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		multiset<int> YA,YB,ZA,ZB;
		FOR(i,N) E[i].clear();
		FOR(i,N) {
			cin>>X[i]>>Y[i]>>Z[i];
			X[i]--,Y[i]--,Z[i]--;
			E[X[i]].push_back(i);
			YB.insert(Y[i]);
			ZB.insert(Z[i]);
		}
		int ret=N;
		FOR(i,N) {
			FORR(e,E[i]) {
				YB.erase(YB.find(Y[e]));
				ZB.erase(ZB.find(Z[e]));
				YA.insert(Y[e]);
				ZA.insert(Z[e]);
			}
			if(YA.size()<N&&YB.size()<N) {
				if(*YA.rbegin()<*YB.begin()&&*ZA.rbegin()<*ZB.begin()) {
					ret=min(ret,(int)ZB.size());
				}
			}
			
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
