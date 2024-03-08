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

int T,N;
int Y1[202020],Y2[202020],X1[202020],X2[202020];

int L[2][202020],R[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>Y1[i]>>X1[i]>>Y2[i]>>X2[i];
			V.push_back({X2[i],i});
		}
		vector<pair<pair<int,int>,int>> S[2];
		S[0]={{{-1,-1},N}};
		S[1]={{{-1,-1},N}};
		sort(ALL(V));
		FORR2(x,i,V) {
			if(Y1[i]!=Y2[i]) {
				FOR(y,2) {
					while(S[y].back().first.first>=X1[i]) S[y].pop_back();
					if(S[y].back().first.second>=X1[i]) {
						S[y].back().first.second=X1[i]-1;
					}
					S[y].push_back({{X1[i],X2[i]},i});
				}
			}
			else {
				y=Y1[i]-1;
				while(S[y].back().first.first>=X1[i]) S[y].pop_back();
				if(S[y].back().first.second>=X2[i]) continue;
				X1[i]=max(X1[i],S[y].back().first.second+1);
				S[y].push_back({{X1[i],X2[i]},i});
			}
		}
		FOR(i,N+1) FOR(j,2) L[j][i]=R[j][i]=0;
		ll ret=-2;
		FOR(y,2) {
			FORR2(xs,i,S[y]) {
				L[y][i]=xs.first;
				R[y][i]=xs.second;
				ret+=xs.second-xs.first+1;
			}
		}
		cout<<ret<<endl;
		FOR(i,N) {
			assert(L[0][i]==0||L[1][i]==0||(L[0][i]==L[1][i]&&R[0][i]==R[1][i]));
			if(L[0][i]==0&&L[1][i]==0) {
				cout<<"0 0 0 0"<<endl;
			}
			else if(L[0][i]&&L[1][i]) {
				cout<<"1 "<<L[0][i]<<" 2 "<<R[0][i]<<endl;
			}
			else if(L[0][i]) {
				cout<<"1 "<<L[0][i]<<" 1 "<<R[0][i]<<endl;
			}
			else if(L[1][i]) {
				cout<<"2 "<<L[1][i]<<" 2 "<<R[1][i]<<endl;
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
