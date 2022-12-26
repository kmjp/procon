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

vector<valarray<ll>> FWHT(vector<valarray<ll>> P) {
	int i,j;
    for (int len = 1; 2 * len <= P.size(); len <<= 1) {
        for (int i = 0; i < P.size(); i += 2 * len) {
			FOR(j,len) {
                valarray<ll> u = P[i + j];
                valarray<ll> v = P[i + len + j];
                P[i + j] = u + v;
                P[i + len + j] = u - v;
            }
        }
    }
    
    return P;
}

vector<ll> A[32],B[32];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<valarray<ll>> A(1<<N),B(1<<N);
	
	int mask;
	FOR(mask,1<<N) {
		A[mask].resize(32);
		FOR(i,32) cin>>A[mask][i];
	}
	FOR(mask,1<<N) {
		B[mask].resize(32);
		FOR(i,32) cin>>B[mask][i];
	}
	
	A=FWHT(A);
	B=FWHT(B);
	FOR(mask,1<<N) {
		valarray<ll> V(63);
		FOR(x,32) FOR(y,32) V[x+y]+=A[mask][x]*B[mask][y];
		A[mask]=V;
	}
	A=FWHT(A);
	FOR(mask,1<<N) {
		FORR(v,A[mask]) {
			v>>=N;
			cout<<abs(v)%2<<" ";
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
