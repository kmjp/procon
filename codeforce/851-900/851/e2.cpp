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
ll A[202020],S[202020];
int C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<ll,int> M;
	M[-1LL<<60]=1<<20;
	M[0]=0;
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		C[i+1]=C[i]+1;
		auto it=M.lower_bound(S[i+1]+1);
		it--;
		C[i+1]=min(C[i]+1,it->second);
		it=M.lower_bound(S[i]+1);
		it--;
		if(it->second<=C[i+1]&&it->first<=S[i+1]) {
			continue;
		}
		else {
			M[S[i+1]]=C[i+1];
			while(1) {
				it=M.lower_bound(S[i+1]+1);
				if(it!=M.end()&&it->second>=C[i+1]) {
					M.erase(it);
				}
				else {
					break;
				}
			}
		}
	}
	
	
	
	cout<<N-C[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
