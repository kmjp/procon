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

string S;
ll K;
int N;

vector<ll> num,sum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	N=S.size();
	sum.push_back(0);
	int ret=0;
	FOR(j,N) {
		if(S[j]=='Y') {
			num.push_back(j);
			sum.push_back(sum.back()+j);
		}
	}
	
	for(i=20;i>=0;i--) {
		int v=ret+(1<<i);
		if(v>num.size()) continue;
		int le=(v-1)/2;
		int ri=v-(1+le);
		
		FOR(j,num.size()) {
			x=j-le;
			y=j+ri;
			if(x<0||y>=num.size()) continue;
			ll as=1LL*le*num[j]-(sum[j]-sum[x])-1LL*le*(le+1)/2;
			ll bs=sum[y+1]-sum[j+1]-1LL*ri*num[j]-1LL*ri*(ri+1)/2;
			if(as+bs<=K) {
				ret=v;
				break;
			}
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
