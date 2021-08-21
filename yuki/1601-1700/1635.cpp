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

ll N,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll mi=N-1;
	ll ma=0;
	if(N%2==0) {
		ma=(N/2+1+N)*(N/2)-(N/2+1);
		ma-=(1+N/2)*(N/2)-N/2;
	}
	else {
		ma=(N/2+2+N)*(N/2)-(N/2+2)+N/2+1;
		ma-=(1+N/2)*(N/2);
	}
	
	if(K>=mi&&K<=N*(N-1)/2) {
		vector<int> A,B,C,D;
		for(int L=1,R=N;L<=R;) {
			C.push_back(L++);
			if(L<=R) C.push_back(R--);
		}
		FORR(c,C) {
			if(A.empty()) {
				A.push_back(c);
			}
			else {
				if(abs(c-A.back())<=K) {
					K-=abs(c-A.back());
					A.push_back(c);
				}
				else {
					D.push_back(c);
				}
			}
		}
		cout<<A[0];
		sort(ALL(D));
		FORR(d,D) cout<<" "<<d;
		FORR(a,A) if(a!=1) cout<<" "<<a;
		cout<<endl;
		return;
	}
	else if(K>=mi&&K<=ma) {
		vector<int> R;
		if(N%2==0) {
			
			FOR(i,N/2) {
				R.push_back(N/2+1+i);
				R.push_back(1+i);
			}
		}
		else {
			FOR(i,N/2) {
				R.push_back(N/2+2+i);
				R.push_back(1+i);
			}
			R.push_back(N/2+1);
		}
		ll dif=ma-K;
		swap(R[dif*2],R[0]);
		FORR(r,R) cout<<r<<" ";
		cout<<endl;
		return;
	}
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
