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
int A[202020];
int P[2][202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> C[2];
	FOR(i,N) {
		cin>>A[i];
		C[A[i]%2].push_back(i);
	}
	if(N==1) {
		cout<<-1<<endl;
	}
	else if(N==2) {
		if(((A[0]+1)^(A[1]+2))==((A[0]+2)^(A[1]+1))) {
			cout<<1<<" "<<2<<endl;
			cout<<2<<" "<<1<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
	else {
		if(C[1].size()>=2) {
			x=C[1][0];
			y=C[1][1];
			k=3;
			P[0][x]=P[1][y]=1;
			P[0][y]=P[1][x]=2;
			
			FOR(i,N) if(i!=x&&i!=y) P[0][i]=P[1][i]=k++;
		}
		else {
			x=C[0][0];
			y=C[0][1];
			k=1;
			P[0][x]=P[1][y]=2;
			P[0][y]=P[1][x]=3;
			
			FOR(i,N) if(i!=x&&i!=y) {
				P[0][i]=P[1][i]=k++;
				if(k==2) k=4;
			}
		}
		FOR(i,N) cout<<P[0][i]<<" ";
		cout<<endl;
		FOR(i,N) cout<<P[1][i]<<" ";
		cout<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
