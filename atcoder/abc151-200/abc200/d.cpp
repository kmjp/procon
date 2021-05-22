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
int A[202];
pair<int,int> from[202][202][8];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]%=200;
	}
	MINUS(from);
	
	from[0][0][0]={0,0};
	FOR(i,N) {
		FOR(j,200) {
			FOR(x,8) if(from[i][j][x].first>=0) {
				// takeall
				from[i+1][j][x|4]={x,3};
				// take B;
				from[i+1][(j+A[i])%200][x|1]={x,1};
				// take C;
				from[i+1][(j+200-A[i])%200][x|2]={x,2};
			}
		}
	}
	
	x=0;
	if(from[N][0][3].first>=0) x=3;
	if(from[N][0][5].first>=0) x=5;
	if(from[N][0][6].first>=0) x=6;
	if(from[N][0][7].first>=0) x=7;
	
	if(x==0) {
		cout<<"No"<<endl;
	}
	else {
		vector<int> B,C;
		int cur=N;
		j=0;
		while(cur>0) {
			pair<int,int> v=from[cur][j][x];
			x=v.first;
			if(v.second&1) B.push_back(cur);
			if(v.second&2) C.push_back(cur);
			cur--;
			if(v.second==1) j=(j+200-A[cur])%200;
			if(v.second==2) j=(j+A[cur])%200;
		}
		assert(j==0&&x==0);
		cout<<"Yes"<<endl;
		reverse(ALL(B));
		reverse(ALL(C));
		cout<<B.size();
		FORR(b,B) cout<<" "<<(b);
		cout<<endl;
		cout<<C.size();
		FORR(b,C) cout<<" "<<(b);
		cout<<endl;
		
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
