#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	for(int a3=0;a3<=200;a3++) {
		for(int a4=0;a4<=200;a4++) {
			if(a3+a4>250) continue;
			int left=K-a3*a4;
			if(left<0 || left>200) continue;
			if(left==0) {
				if(a3+a4<=250) {
					cout<<a3+a4<<endl;
					FOR(i,a3) cout<<3<<" ";
					FOR(i,a4) cout<<4<<" ";
					return;
				}
				continue;
			}
			for(int a5=1;a5<=250-a3-a4;a5++) if(left%a5==0) {
				int a6=left/a5;
				if(a3+a4+a5+a6<=250) {
					cout<<a3+a4+a5+a6<<endl;
					FOR(i,a3) cout<<3<<" ";
					FOR(i,a4) cout<<4<<" ";
					FOR(i,a5) cout<<5<<" ";
					FOR(i,a6) cout<<6<<" ";
					return;
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
