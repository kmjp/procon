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

int T,N,M;
ll A[202020],H[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<pair<int,int>> V;
		ll S=0;
		FOR(i,N) {
			cin>>A[i];
			V.push_back({A[i],i+1});
			S+=A[i];
		}
		if(M*2>N) {
			cout<<-1<<endl;
			continue;
		}
		sort(ALL(V));
		if(M) {
			cout<<N-M<<endl;
			for(i=M;i<N;i++) {
				cout<<V[i].second<<" "<<V[i-M].second<<endl;
			}
		}
		else {
			if(S-V[N-1].first<V[N-1].first) {
				cout<<-1<<endl;
			}
			else {
				cout<<N-1<<endl;
				FOR(i,N-1) {
					if(V[i].first>=V[N-1].first) break;
					cout<<V[i].second<<" "<<V[N-1].second<<endl;
					V[N-1].first-=V[i].first;
				}
				for(j=i+1;j<N;j++) {
					cout<<V[j].second<<" "<<V[j-1].second<<endl;
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
