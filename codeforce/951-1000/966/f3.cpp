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

int T;
int N,K;
int A[101],B[101];
int from[101],to[101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,K+1) from[i]=101010;
		from[0]=0;
		FOR(i,N) {
			cin>>x>>y;
			vector<int> S={0};
			while(x>1||y>1) {
				S.push_back(S.back()+min(x,y));
				if(x>y) x--;
				else y--;
			}
			S.push_back(S.back()+1);
			S.push_back(S.back());
			FOR(j,101) to[j]=101010;
			FOR(j,101) for(x=0;j+x<=K&&x<S.size();x++) to[j+x]=min(to[j+x],from[j]+S[x]);
			swap(from,to);
		}
		if(from[K]>100000) {
			cout<<-1<<endl;
		}
		else {
			cout<<from[K]<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
