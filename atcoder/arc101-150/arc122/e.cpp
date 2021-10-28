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

__int128 gcd(__int128 x, __int128 y) {
    while (y > 0) {
        __int128 r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> A(N);
	FOR(i,N) cin>>A[i];
	
	vector<ll> R;
	while(A.size()>1) {
		
		FOR(i,A.size()) {
			__int128 LC=1;
			FOR(j,A.size()) if(i!=j) {
				LC=LC/gcd(LC,(__int128)A[j])*A[j];
				LC=gcd(LC,(__int128)A[i]);
			}
			if(LC!=A[i]) break;
		}
		
		if(i==A.size()) {
			cout<<"No"<<endl;
			return;
		}
		R.push_back(A[i]);
		A.erase(A.begin()+i);
		
	}
	
	R.push_back(A[0]);
	
	cout<<"Yes"<<endl;
	reverse(ALL(R));
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
