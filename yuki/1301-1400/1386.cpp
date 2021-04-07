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

int N,Q;
ll V[101010];
ll A[101010];
ll B[101010];


vector<vector<int>> R;

void dfs(int cur,ll v) {
	if(v==0) return;
	if(v/2) {
		dfs(cur,v/2);
		B[cur]*=2;
		R.push_back({3,cur,cur});
	}
	if(v%2) {
		if(v>0) R.push_back({1,cur}), B[cur]++;
		else R.push_back({2,cur}), B[cur]--;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		if(x==1) {
			if(y==1) {
				V[1]++;
				V[2]+=3;
				V[3]+=2;
			}
			else if(y==2) {
				V[2]++;
				V[3]+=2;
			}
			else {
				V[y]++;
				V[y+1]++;
			}
			//for(j=y;j<=N;j++) A[j]+=1LL*(j-y+1)*(j-y+1);
		}
		else {
			V[1]+=1LL*y*y;
			V[2]-=2*y-1;
			V[3]+=2;
			V[y+2]--;
			V[y+3]--;
			//for(j=1;j<=y;j++) A[j]+=1LL*(j-y+1)*(j-y+1);
		}
	}
	//cout<<"S1 "; FOR(i,N) cout<<A[i+1]<<" "; cout<<endl;
	for(i=1;i<=N;i++) dfs(i,V[i]);
	//cout<<"S1 ";FOR(i,N) cout<<B[i+1]<<" ";	cout<<endl;
	for(i=3;i<N;i++) R.push_back({3,i+1,i}), B[i+1]+=B[i];
	//cout<<"S1 ";FOR(i,N) cout<<B[i+1]<<" ";	cout<<endl;
	for(i=2;i<N;i++) R.push_back({3,i+1,i}), B[i+1]+=B[i];
	//cout<<"S1 ";FOR(i,N) cout<<B[i+1]<<" ";	cout<<endl;
	for(i=1;i<N;i++) R.push_back({3,i+1,i}), B[i+1]+=B[i];
	//cout<<"S1 ";FOR(i,N) cout<<B[i+1]<<" ";	cout<<endl;
	cout<<R.size()<<endl;
	FORR(r,R) {
		FORR(v,r) cout<<v<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
