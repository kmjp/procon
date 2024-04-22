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
int A[1010][1010];

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V[2];
	for(i=1;i<=N*N;i++) V[i%2].push_back(i);
	
	
	if(N==3) {
		vector<int> V={1,2,3,4,5,6,7,8,9};
		do {
			FOR(y,3) FOR(x,3) A[y][x]=V[y*3+x];
			int ok=1;
			FOR(y,3) FOR(x,3) {
				if(y&&isprime(A[y][x]+A[y-1][x])) ok=0;
				if(x&&isprime(A[y][x]+A[y][x-1])) ok=0;
			}
			if(ok) {
				FOR(y,3) {
					FOR(x,3) cout<<A[y][x]<<" ";
					cout<<endl;
				}
				return;
			}
			
		} while(next_permutation(ALL(V)));
		
		return;
	}
	
	
	if(N%2==0) {
		FOR(i,N) {
			A[N/2-1][i]=V[0].back();
			for(j=V[1].size()-1;j>=0;j--) if((V[0].back()+V[1][j])%3==0) {
				A[N/2][i]=V[1][j];
				swap(V[1][j],V[1][V[1].size()-1]);
				V[1].pop_back();
				break;
			}
			V[0].pop_back();
		}
		
		FOR(y,N) FOR(x,N) if(A[y][x]==0) {
			if(y<N/2) {
				A[y][x]=V[0].back();
				V[0].pop_back();
			}
			else {
				A[y][x]=V[1].back();
				V[1].pop_back();
			}
		}
	}
	else {
		for(j=V[0].size()-1;j>=0;j--) if(V[0][j]%3==2) {
			A[N/2-1][N/2]=V[0][j];
			swap(V[0][j],V[0][V[0].size()-1]);
			V[0].pop_back();
			break;
		}
		sort(ALL(V[0]));
		reverse(ALL(V[0]));
		
		for(j=V[0].size()-1;j>=0;j--) if(V[0][j]%3==2) {
			A[N/2][N/2+1]=V[0][j];
			swap(V[0][j],V[0][V[0].size()-1]);
			V[0].pop_back();
			break;
		}
		sort(ALL(V[0]));
		
		FOR(i,N) {
			if(i<N/2) {
				A[N/2-1][i]=V[0].back();
				V[0].pop_back();
			}
			else if(i>N/2+1) {
				A[N/2][i]=V[0].back();
				V[0].pop_back();
			}
		}
		FOR(i,N) {
			if(i<=N/2) {
				for(j=V[1].size()-1;j>=0;j--) if((A[N/2-1][i]+V[1][j])%3==0) {
					A[N/2][i]=V[1][j];
					swap(V[1][j],V[1][V[1].size()-1]);
					V[1].pop_back();
					break;
				}
			}
			else {
				for(j=V[1].size()-1;j>=0;j--) if((A[N/2][i]+V[1][j])%3==0) {
					A[N/2+1][i]=V[1][j];
					swap(V[1][j],V[1][V[1].size()-1]);
					V[1].pop_back();
					break;
				}
			}
		}
		
		FOR(y,N) FOR(x,N) if(A[y][x]==0) {
			if(y<N/2||(y==N/2&&x>N/2)) {
				A[y][x]=V[0].back();
				V[0].pop_back();
			}
			else {
				A[y][x]=V[1].back();
				V[1].pop_back();
			}
		}
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
