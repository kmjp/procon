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
		ll XA=0,XB=0,YA=0,YB=0;
		int cur=0;
		for(i=1;i<=100000&&N>0;i++) {
			x=min(N,i);
			N-=x;
			if(i%4<=1) {
				if(cur==0) {
					XA+=(x+1)/2;
					XB+=x/2;
				}
				else {
					XB+=(x+1)/2;
					XA+=x/2;
				}
			}
			else {
				if(cur==0) {
					YA+=(x+1)/2;
					YB+=x/2;
				}
				else {
					YB+=(x+1)/2;
					YA+=x/2;
				}
			}
			cur^=i%2;
		}
		if(0) {
			cout<<XA<<" "<<XB<<" "<<YA<<" "<<YB<<endl;
		}
		else {
			cout<<XA+XB<<" "<<YA+YB<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
