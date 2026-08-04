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

int T,H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		
		cin>>y>>x;
		if(y==0) continue;
		if(y==-1) assert(0);
		
		if(H==3&&W==3) {
			cout<<"2 2"<<endl;
			cin>>y>>x;
			if(y==0) continue;
			assert(0);
		}
		else if(H==3) {
			cout<<"1 "<<W-2<<endl;
			cin>>y>>x;
			if(y==0) continue;
			cout<<"2 "<<W-1<<endl;
			cin>>y>>x;
			if(y==0) continue;
			assert(0);
		}
		else if(W==3) {
			cout<<H-2<<" 1"<<endl;
			cin>>y>>x;
			if(y==0) continue;
			cout<<H-1<<" 2"<<endl;
			cin>>y>>x;
			if(y==0) continue;
			assert(0);
		}
		else {
			cout<<H-2<<" 1"<<endl;
			cin>>y>>x;
			if(y==0) continue;
			cout<<H-2<<" "<<W-2<<endl;
			cin>>y>>x;
			if(y==H-3) {
				cout<<H-3<<" "<<W-1<<endl;
			}
			else if(x==W-3) {
				cout<<H-1<<" "<<W-3<<endl;
			}
			else {
				cout<<H-1<<" "<<W-1<<endl;
			}
			cin>>y>>x;
			if(y==0) continue;
			assert(0);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
