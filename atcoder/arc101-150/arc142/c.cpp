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

int D[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=3;i<=N;i++) {
		cout<<"? 1 "<<i<<endl;
		cin>>D[1][i];
		cout<<"? 2 "<<i<<endl;
		cin>>D[2][i];
	}
	
	vector<int> cand;
	for(i=1;i<=N-1;i++) {
		int ok=1;
		int num=0;
		for(j=3;j<=N;j++) {
			if(D[1][j]+D[2][j]==i) {
				num++;
			}
			if(D[1][j]+D[2][j]<i) {
				ok=0;
			}
			if(abs(D[1][j]-D[2][j])>i) {
				ok=0;
			}
			if((D[1][j]+D[2][j]+i)%2==1) {
				ok=0;
			}
		}
		if(ok&&num==i-1) cand.push_back(i);
	}
	
	if(cand.size()==1) {
		cout<<"! "<<cand[0]<<endl;
	}
	else if(cand.size()==2) {
		assert(cand[0]+2==cand[1]);
		assert(cand[0]==1);
		x=y=0;
		for(j=3;j<=N;j++) {
			if(D[1][j]==1&&D[1][j]+D[2][j]==cand[1]) x=j;
			if(D[2][j]==1&&D[1][j]+D[2][j]==cand[1]) y=j;
		}
		if(x==0||y==0) {
			x=1;
		}
		else {
			cout<<"? "<<x<<" "<<y<<endl;
			cin>>r;
			
			if(r==3) {
				x=1;
			}
			else if(r==1) {
				x=3;
			}
			else {
				assert(0);
			}
		}
		cout<<"! "<<x<<endl;
	}
	else {
		assert(0);
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
