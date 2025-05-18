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
ll N,K;
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		if(K==1) {
			cout<<N%mo<<endl;
			continue;
		}
		
		vector<int> V={1,1};
		int num=0;
		while(1) {
			x=(V.back()+V[V.size()-2])%K;
			if(x==0) num++;
			V.push_back(x);
			if(V.back()==1&&V[V.size()-2]==1) break;
		}
		V.pop_back();
		V.pop_back();

		ll ret=((N-1)/num)%mo*V.size()%mo;
		ll pos=0;
		N-=(N-1)/num*num;
		while(N) {
			ret++;
			if(V[pos%V.size()]==0) N--;
			pos++;
			
		}
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
