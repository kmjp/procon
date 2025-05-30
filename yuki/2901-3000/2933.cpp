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


string S,T;
int A,B;
int Q;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> SB,TB;

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	int merge(int a,int b) {
		if(a==-2) return b;
		if(b==-2) return a;
		if(a!=b) return -1;
		return a;
	}
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return -2;
		if(x<=l && r<=y) return ma[k]%26;
		int a=merge(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		if(a!=-1) a=(a+val[k])%26;
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			(val[k]+=v)%=26;
			if(ma[k]!=-1) {
				(ma[k]+=v)%=26;
			}
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=merge(ma[k*2],ma[k*2+1]);
			if(ma[k]!=-1) (ma[k]+=val[k])%=26;
		}
	}
};
SegTree_3<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	A=S.size();
	B=T.size();
	FOR(i,A) SB.add(i,S[i]-'a'),SB.add(i+1,-(S[i]-'a'));
	FOR(i,B) TB.add(i,T[i]-'a'),TB.add(i+1,-(T[i]-'a'));
	FOR(i,min(A,B)) st.update(i,i+1,(S[i]-T[i]+26)%26);
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1||i==2) {
			int L,R;
			cin>>L>>R>>x;
			L--;
			if(i==1) {
				st.update(L,R,x);
				SB.add(L,x);
				SB.add(R,26-x);
			}
			else {
				st.update(L,R,26-x);
				TB.add(L,x);
				TB.add(R,26-x);
			}
		}
		else {
			cin>>x;
			x--;
			if(st.getval(x,min(A,B))==0) {
				if(A>B) cout<<"Greater"<<endl;
				else if(A==B) cout<<"Equals"<<endl;
				else cout<<"Lesser"<<endl;
			}
			else {
				y=min(A,B);
				for(i=20;i>=0;i--) if(y-(1<<i)>x&&st.getval(x,y-(1<<i))!=0) y-=1<<i;
				y--;
				i=SB(y)%26;
				j=TB(y)%26;
				if(i>j) cout<<"Greater"<<endl;
				else if(i==j) cout<<"Equals"<<endl;
				else cout<<"Lesser"<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
