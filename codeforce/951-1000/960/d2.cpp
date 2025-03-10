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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int f=0,s=0;
		int ret=0;
		FOR(i,N) {
			cin>>x;
			if(f==0&&s==0) {
				//2å¬à»â∫Ç»ÇÁ2*2ÅAÇªÇÍà»è„Ç»ÇÁçsè¡Çµ
				if(x) {
					ret++;
					if(x<=2) f=1;
				}
			}
			else if(f) {
				f=0;
				if(x>=3) {
					ret++;
					if(x<=4) s=1;
				}
			}
			else {
				s=0;
				if(x) {
					ret++;
					if(x<=4) f=1;
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
