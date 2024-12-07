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
string S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<char,int> M;
	M['C']=0;
	M['D']=1;
	M['H']=2;
	M['S']=3;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		vector<string> A[4];
		FOR(i,2*N) {
			cin>>s;
			A[M[s[1]]].push_back(s);
		}
		y=A[0].size()%2+A[1].size()%2+A[2].size()%2+A[3].size()%2;
		x=A[M[S[0]]].size();
		y-=A[M[S[0]]].size()%2;
		if(x<y) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		FOR(i,4) {
			sort(ALL(A[i]));
			if(i==M[S[0]]) continue;
			for(j=0;j+1<A[i].size();j+=2) {
				cout<<A[i][j]<<" "<<A[i][j+1]<<endl;
			}
			if(A[i].size()%2) {
				cout<<A[i].back()<<" "<<A[M[S[0]]].back()<<endl;
				A[M[S[0]]].pop_back();
			}
			A[i].clear();
		}
		FOR(i,4) {
			for(j=0;j+1<A[i].size();j+=2) {
				cout<<A[i][j]<<" "<<A[i][j+1]<<endl;
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
