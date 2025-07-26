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

int T,N,M,Q;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>Q;
		vector<pair<int,int>> V={{M,M}};
		while(Q--) {
			cin>>x;
			int ism=0;
			vector<pair<int,int>> W={};
			FORR2(a,b,V) {
				if(a<=x&&x<=b) {
					ism=1;
					if(a==x&&b==x) continue;
				}
				else if(b<x) {
					b++;
				}
				else {
					a--;
				}
				W.push_back({a,b});
			}
			if(ism) {
				W.push_back({1,1});
				W.push_back({N,N});
			}
			sort(ALL(W));
			V.clear();
			int ret=0;
			FORR2(a,b,W) {
				if(V.empty()||V.back().second<a) {
					ret+=b-a+1;
					V.push_back({a,b});
				}
				else if(b>V.back().second) {
					ret+=b-V.back().second;
					V.back().second=b;
				}
			}
			
			cout<<ret<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
