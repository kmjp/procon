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


string N;
int K;

map<int,ll> M[20][2][2];

ll p10[20];

map<int,ll> hoge(int d,int les,int first) {
	if(d==-1) {
		map<int,ll> A;
		if(first==0) A[1]=1;
		return A;
	}
	if(M[d][les][first].size()) return M[d][les][first];
	map<int,ll>& C=M[d][les][first];
	
	int i;
	if(les==1) {
		for(i=0;i<=N[d]-'0';i++) {
			if(i==N[d]-'0') {
				auto a=hoge(d-1,les,(i==0)?first:0);
				FORR2(b,c,a) C[min(1LL*b*i,K+1LL)]+=c;
			}
			else {
				auto a=hoge(d-1,0,(i==0)?first:0);
				if(first&&i==0) {
					FORR2(b,c,a) C[b]+=c;
				}
				else {
					FORR2(b,c,a) C[min(1LL*b*i,K+1LL)]+=c;
				}
			}
		}
	}
	else {
		for(i=0;i<=9;i++) {
			auto a=hoge(d-1,0,(i==0)?first:0);
			if(first&&i==0) {
				FORR2(b,c,a) C[b]+=c;
			}
			else {
				FORR2(b,c,a) C[min(1LL*b*i,K+1LL)]+=c;
			}
		}
	}
	
	return C;
}

void solve() {
	int i,j,k,l,x,y; string s;
	
	p10[0]=1;
	for(i=1;i<=18;i++) p10[i]=p10[i-1]*10;
	
	cin>>N>>K;
	
	reverse(ALL(N));
	auto r=hoge(N.size()-1,1,1);
	ll ret=0;
	FORR2(a,b,r) if(a<=K) ret+=b;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
