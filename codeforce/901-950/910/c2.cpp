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

int T,N,M,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		K-=(N-1)+(M-1);
		if(K<0||K%2) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			FOR(y,N) {
				FOR(x,M-1) {
					int pat=(K%4)&&(x==0);
					cout<<"RB"[(x%2)^pat]<<" ";
				}
				cout<<endl;
			}
			FOR(y,N-1) {
				
				FOR(x,M) {
					int pat=(K%4)&&(x<=1)&&(y==0);
					if(pat) {
						cout<<"R ";
					}
					else {
						cout<<"BR"[(y%2)^(M%2)]<<" ";
					}
				}
				cout<<endl;
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
