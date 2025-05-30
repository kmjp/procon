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

int T,N,M,A[202020];
int D[2][202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		int sum=0;
		vector<int> V;
		FOR(i,N) {
			cin>>x;
			y=x;
			D[0][i]=D[1][i]=0;
			while(y) {
				D[0][i]++;
				y/=10;
			}
			while(x%10==0) x/=10;
			while(x) {
				D[1][i]++;
				x/=10;
			}
			sum+=D[1][i];
			V.push_back(D[0][i]-D[1][i]);
		}
		
		sort(ALL(V));
		reverse(ALL(V));
		for(i=1;i<N;i+=2) sum+=V[i];
		if(sum>M) {
			cout<<"Sasha"<<endl;
		}
		else {
			cout<<"Anna"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
