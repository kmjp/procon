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
int K;
string S;
int L;
ll M;

ll p10[1<<20];
ll p10M[1<<20];

ll floor_sum(ll N,ll M,ll A,ll B) {
	// sum(i=0...N-1) floor((A*i+B)/M)
	if(A<0) return floor_sum(N,M,-A,B+(N-1)*A); //A‚ª•‰‚Ìê‡ŒX‚«‚ð‹t‚É‚·‚é
	
	ll ret=0;
	if(B>=M) ret+=N*(B/M), B%=M;
	if(A>=M) ret+=N*(N-1)/2*(A/M), A%=M;
	
	ll Y=(A*N+B)/M;
	if(Y==0) return ret;
	//floor(Y/M)‚É’B‚·‚éX
	ll X=Y*M-B;
	//X‚Ì‰E‘¤‚ÍYŒÂ‚¸‚Â
	ret+=(N-(X+A-1)/A)*Y;
	// 90“x‰ñ“]AY=N‚Ìƒ‰ƒCƒ“‚Í–³Ž‹‚·‚é
	ret+=floor_sum(Y,A,M,(A-X%A)%A);
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>K>>S;
		L=S.size();
		M=0;
		FORR(c,S) M=(M*10+c-'0')%K;
		
		p10[0]=1;
		p10M[0]=1%K;
		
		FOR(i,L+20) {
			p10[i+1]=p10[i]*10;
			p10M[i+1]=(p10M[i]*10)%K;
		}
		
		int TL,TR;
		string ret(L+20,'x');
		for(TR=0;TR<=9;TR++) {
			ll mi=0,ma=p10[TR]-1;
			mi+=p10M[TR]*M%K;
			ma+=p10M[TR]*M%K;
			if(mi%K==0||mi/K!=ma/K) {
				ll add;
				if(mi%K==0) {
					add=0;
				}
				else {
					add=K-mi%K;
				}
				string tmp=S+string(TR,'0');
				FOR(i,TR) tmp[tmp.size()-1-i]+=add/p10[i]%10;
				
				if(tmp.size()<ret.size()) {
					ret=tmp;
				}
				else if(tmp.size()==ret.size()&&tmp<ret) {
					ret=tmp;
				}
				
			}
			else {
				mi%=K;
				ma%=K;
				ll step=p10M[TR+L]%K;
				ll cnt=floor_sum(1LL<<30,K,step,ma+K)-floor_sum(1LL<<30,K,step,mi+K-1);
				if(cnt==0) continue;
				ll up=(1LL<<30)-1;
				for(i=29;i>=0;i--) {
					ll cnt=floor_sum(up-(1LL<<i),K,step,ma+K)-floor_sum(up-(1LL<<i),K,step,mi+K-1);
					if(cnt) up-=1LL<<i;
				}
				up--;
				ll a=(up*p10M[TR+L]+p10[TR]*M)%K;
				ll add;
				if(a==0) {
					add=0;
				}
				else {
					add=K-a%K;
				}
				string tmp=to_string(up)+S+string(TR,'0');
				FOR(i,TR) tmp[tmp.size()-1-i]+=add/p10[i]%10;
				if(tmp.size()<ret.size()) {
					ret=tmp;
				}
				else if(tmp.size()==ret.size()&&tmp<ret) {
					ret=tmp;
				}
				
				
			}
			
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
