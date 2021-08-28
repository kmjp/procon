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
ll A[1<<7];
ll B[1<<7];
int C[1<<7];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) {
		cin>>A[i];
	}
	for(i=29;i>=0;i--) {
		set<pair<int,int>> S;
		FOR(x,1<<N) FOR(y,x) {
			if(((B[x]^B[y])>>i)==(B[x^y]>>i)) {
				S.insert({y,x});
			}
		}
		FOR(x,1<<N) {
			if(A[x]==-1) C[x]=2;
			else C[x]=(A[x]>>i)%2;
		}
		FOR(j,128) {
			FORR2(a,b,S) {
				if(a==0) {
					if(C[b]==0) C[a]=0;
				}
				else {
					if(C[a]==0&&C[b]==0) {
						if(C[a^b]==2) C[a^b]=0;
					}
				}
				
				if(C[a]<2&&C[b]<2&&C[a^b]<2&&C[a^b]<(C[a]^C[b])) {
					cout<<"No"<<endl;
					return;
				}
			}
		}
		FOR(x,1<<N) {
			if(C[x]==2) C[x]=1;
			B[x]|=C[x]<<i;
		}
	}
	cout<<"Yes"<<endl;
	FOR(i,1<<N) cout<<B[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
