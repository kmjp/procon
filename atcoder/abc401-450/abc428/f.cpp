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
ll W[202020],D[202020];
int Q;

template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	SegTree_MulAdd(){sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return ret*mul[k]+add[k]*(y-x);
	}
	void propagate(int k,int s) {
		mul[k*2]*=mul[k];
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		add[k*2]+=add[k];
		sum[k*2]+=add[k]*s/2;
		mul[k*2+1]*=mul[k];
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		add[k*2+1]+=add[k];
		sum[k*2+1]+=add[k]*s/2;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			mul[k]*=v;
			add[k]*=v;
			sum[k]*=v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			sum[k]+=(r-l)*v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
};

SegTree_MulAdd<ll, 1<<18> st;

int in(int v,ll pos) {
	ll a=W[N-1]/2+st.getval(v,N)-W[v]/2;
	return (pos>=a&&pos<=a+W[v]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>W[i];
		W[i]*=2;
	}
	vector<pair<int,int>> V={{N-1,-1}};
	FOR(i,N-1) {
		st.doadd(i,i+1,-(W[i+1]-W[i])/2);
	}
	cin>>Q;
	while(Q--) {
		cin>>i>>x;
		
		if(i==1||i==2) {
			x-=2;
			if(x<0) continue;
			y=(i==1)?-1:1;
			int L=0,R=x+1;
			while(V.back().first<=x) {
				if(V.back().second==-1) {
					st.domul(L,V.back().first+1,-1);
				}
				L=V.back().first+1;
				V.pop_back();
			}
			if(L<R&&V.back().second==-1) {
				st.domul(L,R,-1);
			}
			
			if(y==-1) {
				st.domul(0,x+1,-1);
				V.push_back({x,-1});
			}
			else {
				V.push_back({x,1});
			}
		}
		else {
			x=x*2+1;
			
			int cur=0;
			for(i=20;i>=0;i--) if(cur+(1<<i)<=N&&in(cur+(1<<i)-1,x)==0) cur+=1<<i;
			
			cout<<N-cur<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
