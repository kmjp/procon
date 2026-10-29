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
ll N,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	int out=0;
	FOR(j,T) {
		cin>>N;
		vector<ll> cand;
		FOR(i,N) {
			cin>>A[i];
			cand.push_back(A[i]);
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		if(N>=61) cand.resize(61);
		vector<int> ret;
		FORR(c,cand) {
			
			ll S=0;
			ll ma=2*c+1;
			FOR(i,N) if(A[i]<=c) S+=A[i];
			ll cur=0;
			vector<int> st;
			FOR(i,N) if(A[i]<=c) {
				S-=A[i];
				while(st.size()&&st.back()<A[i]&&cur-st.back()+A[i]+S>=ma) {
					cur-=st.back();
					st.pop_back();
				}
				if(cur+A[i]+S>=ma) {
					st.push_back(A[i]);
					cur+=A[i];
				}
			}
			
			ret=max(ret,st);
		}
		if(ret.size()<3) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret.size()<<endl;
			FORR(r,ret) cout<<r<<" ";
			cout<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
