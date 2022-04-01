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
int A[1010101],B[1000000][6];
int C[1010101];
int S[10][10][10][10][10][10];

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>A[i];
		x=A[i];
		C[A[i]]++;
		FOR(j,6) {
			B[i][j]=x%10;
			x/=10;
		}
		S[B[i][0]][B[i][1]][B[i][2]][B[i][3]][B[i][4]][B[i][5]]++;
	}
	int r[6],t[6];
	FOR(r[0],10)
	FOR(r[1],10)
	FOR(r[2],10)
	FOR(r[3],10)
	FOR(r[4],10)
	FOR(r[5],10) {
		int sum=0;
		int mask;
		FOR(mask,1<<6) if(mask) {
			int m=-1;
			int ng=0;
			FOR(i,6)  {
				t[i]=r[i];
				if(mask&(1<<i)) {
					t[i]--;
					m=-m;
					if(t[i]<0) ng=1;
				}
			}
			if(ng) continue;
			sum+=m*S[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]];
		}
		S[r[0]][r[1]][r[2]][r[3]][r[4]][r[5]]+=sum;
	}
	FOR(i,1000000) {
		x=i;
		int dup=1;
		FOR(j,6) {
			r[j]=x%10;
			if(r[j]>=5) dup=0;
			x/=10;
			r[j]=9-r[j];
		}
		if(dup) ret-=1LL*C[i];
		ret+=1LL*C[i]*S[r[0]][r[1]][r[2]][r[3]][r[4]][r[5]];
		
		
	}
	cout<<ret/2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
