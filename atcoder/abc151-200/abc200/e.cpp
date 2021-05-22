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
ll K;

void out(int x,int y,int z) {
	cout<<(x+1)<<" "<<(y+1)<<" "<<(z+1)<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(i=0;i<=3*(N-1);i++) {
		ll num=0;
		if(i<N) {
			num=1LL*(i+1)*(i+2)/2;
		}
		else if(i<2*(N-1)) {
			j=i-(N-1);
			num=1LL*(i+1)*(i+2)/2;
			num-=3LL*(j+1)*(j)/2;
		}
		else {
			j=(3*(N-1)-i);
			num=1LL*(j+1)*(j+2)/2;
		}
		if(K>num) {
			K-=num;
			continue;
		}
		
		for(x=0;x<N;x++) {
			int len=i-x;
			if(len<=N-1) {
				len++;
				if(K<=len) {
					out(x,K-1,len-K);
				}
				K-=len;
			}
			else if(len<=2*N-1) {
				y=len-(N-1);
				int tlen=(N-1-y+1);
				if(K<=tlen) {
					out(x,y+(K-1),(N-1)-(K-1));
				}
				K-=tlen;
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
