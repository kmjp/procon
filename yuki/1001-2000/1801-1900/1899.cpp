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
ll N,A,B;

ll floor_sum(ll N,ll M,ll A,ll B) {
	// sum(i=0...N-1) floor((A*i+B)/M)
	
	ll ret=0;
	if(B>=M) ret+=N*(B/M), B%=M;
	if(A>=M) ret+=N*(N-1)/2*(A/M), A%=M;
	
	ll Y=(A*N+B)/M;
	if(Y==0) return ret;
	//floor(Y/M)�ɒB����X
	ll X=Y*M-B;
	//X�̉E����Y����
	ret+=(N-(X+A-1)/A)*Y;
	// 90�x��]�AY=N�̃��C���͖�������
	ret+=floor_sum(Y,A,M,(A-X%A)%A);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		ll ret=0;
		
		ll ma=N,mi=ma%A;
		ret+=floor_sum(ma/A,1,A,N%A);
		ret+=floor_sum(ma/B,1,B,N%B);
		ret-=floor_sum(ma/A,B,A,N%A);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}