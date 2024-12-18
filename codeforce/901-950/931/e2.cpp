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
		int F=N;
		vector<vector<int>> V;
		if(N>13) {
			if(N%4==3) {
				V.push_back({1,2,N});
				N--;
			}
			if(N%4==0) {
				V.push_back({1,N-1,N});
				N-=2;
			}
			while(N>F/2) {
				if(N%4==2) {
					N-=11;
					V.push_back({N+0,N+1,N+2});
					V.push_back({N+4,N+5,N+6});
					V.push_back({N+8,N+9,N+10});
					V.push_back({N+3,N+7,N+11});
					N--;
				}
				if(N%4==1) {
					N-=11;
					V.push_back({N+0,N+4,N+8});
					V.push_back({N+1,N+2,N+3});
					V.push_back({N+5,N+6,N+7});
					V.push_back({N+9,N+10,N+11});
					N--;
				}
			}
		}
		else {
			if(N==3) V={{1,2,3}};
			if(N==4) V={{1,3,4}};
			if(N==5) V={{3,4,5}};
			if(N==6) V={{1,3,5},{2,4,6}};
			if(N==7) V={{3,5,7},{5,6,7},{2,3,4}};
			if(N==8) V={{5,6,7},{1,3,8}};
			if(N==9) V={{1,3,5},{2,4,6},{7,8,9}};
			if(N==10) V={{7,9,10},{1,5,6},{2,3,8}};
			if(N==11) V={{9,10,11},{5,6,7},{1,3,8}};
			if(N==12) V={{10,3,1},{8,9,5},{7,11,12}};
			if(N==13) V={{11,12,13},{7,9,10},{1,5,6},{2,3,8}};
			
		}
		cout<<V.size()<<endl;
		FORR(a,V) cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
