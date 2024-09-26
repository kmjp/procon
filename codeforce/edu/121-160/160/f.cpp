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
string S,A,B;

using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%1259,mul1=10007+(time(NULL)+((ll)&mul1)>>5)%2257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	pair<ll,ll> hash(VT s) { init(s); return hash(0,s.size()-1); }
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;
RollingHash ra,rb;

int X[606060],Y[606060];
ll cand[303030][26];

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
	int lower_bound(V val) { //’P’²‘‰Á‚ÌŽž‚Ì‚ÝŽg‚¦‚é
		V v0=0,v1=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) {
			if((ent+(1<<i)-1)*(v0+bit[0][ent+(1<<i)-1])+(v1+bit[1][ent+(1<<i)-1])<val) {
				v0+=bit[0][ent+(1<<i)-1];
				v1+=bit[1][ent+(1<<i)-1];
				ent+=(1<<i);
			}
		}
		return ent;
	}
};
BIT_r<ll,20> C;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	A="*";
	FORR(c,S) {
		A+=c;
		A+='*';
	}
	A.pop_back();
	N=A.size();
	B=A;
	reverse(ALL(B));
	ra.init(A);
	rb.init(B);
	
	ll sum=0;
	for(i=0;i<N;i++) {
		x=0;
		for(j=20;j--;j>=0) {
			int TL=i-x-(1<<j);
			int TR=i+x+(1<<j);
			if(TL<0||TR>=N) continue;
			auto p=ra.hash(TL,i);
			auto q=rb.hash(N-1-TR,N-1-i);
			if(p==q) x+=1<<j;
		}
		X[i]=x;
		
		int AL=i-(x+1);
		int AR=i+(x+1);
		x=0;
		for(j=20;j--;j>=0) {
			int TL=AL-x-(1<<j);
			int TR=AR+x+(1<<j);
			if(TL<0||TR>=N) continue;
			auto p=ra.hash(TL,AL-1);
			auto q=rb.hash(N-1-TR,N-1-AR-1);
			if(p==q) x+=1<<j;
		}
		Y[i]=x;
		
		int add0,add1=0;
		if(i%2==0) {
			
			add0=(X[i]+1)/2;
			if(i-(X[i]+1)>=0&&i+(X[i]+1)<N) add1=(X[i]+Y[i]+2)/2-add0;
			
			if(X[i]) {
				x=(i-X[i])/2;
				y=X[i]/2;
				C.add(x,x+y-1,1);
				C.add(x+y+1,x+y+y,-1);
			}
			
		}
		else {
			add0=1+X[i]/2;
			if(i-(X[i]+1)>=0&&i+(X[i]+1)<N) add1=1+(X[i]+Y[i]+1)/2-add0;
			if(X[i]>1) {
				x=(i-X[i])/2;
				y=X[i]/2;
				C.add(x,x+y-1,1);
				C.add(x+y,x+y,-y);
				C.add(x+y+1,x+y+1,y);
				C.add(x+y+2,x+y+y+1,-1);
			}
		}
		
		sum+=add0;
		if(i-(X[i]+1)>=0&&i+(X[i]+1)<N) {
			cand[(i-(X[i]+1))/2][A[i+X[i]+1]-'a']+=add1;
			cand[(i+(X[i]+1))/2][A[i-X[i]-1]-'a']+=add1;
		}
	}
	ll ret=sum;
	int pos=0;
	char c=S[0];
	FOR(i,S.size()) FOR(j,26) {
		ll pat=sum-C.total(i)+cand[i][j];
		if(pat>ret) {
			pos=i;
			c=j+'a';
			ret=pat;
		}
		else if(pat==ret) {
			if(i==pos) c=min(c,(char)(j+'a'));
			else if(i<pos) {
				string X=S.substr(i,1)+c;
				string Y=(char)(j+'a')+S.substr(pos,1);
				if(Y<X) pos=i,c=j+'a';
			}
			else {
				string X=c+S.substr(i,1);
				string Y=S.substr(pos,1)+(char)(j+'a');
				if(Y<X) pos=i,c=j+'a';
			}
		}
	}
	S[pos]=c;
	cout<<ret<<endl;
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
