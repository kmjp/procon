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

int TH,TW,H,W,N;
int R[202020],C[202020];
map<int,vector<int>> ev;

template<class V,int NV> class SegTree_2 {
public:
	vector<V> sum,val;
	SegTree_2(){sum.resize(NV*2); val.resize(NV*2);}
	
	
	ll update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) {
			return 0;
		}
		if(x<=l && r<=y) {
			val[k]+=v;
			if(val[k]) return 0;
			return sum[k];
		}
		else if(l < y && x < r) {
			sum[k]=0;
			sum[k]+=update(x,y,v,l,(l+r)/2,k*2);
			sum[k]+=update(x,y,v,(l+r)/2,r,k*2+1);
			if(val[k]) return 0;
			return sum[k];
		}
		else {
			if(val[k]) return 0;
			return sum[k];
		}
	}
	//‰Šú‰»
};
SegTree_2<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>TH>>TW>>H>>W>>N;
	
	vector<int> Rs={0,TH-H+1};
	FOR(i,N) {
		cin>>R[i]>>C[i];
		Rs.push_back(max(R[i]-H,0));
		Rs.push_back(R[i]);
		ev[max(C[i]-W,0)].push_back(R[i]);
		ev[C[i]].push_back(-R[i]);
	}
	ev[TW-W+1].push_back(0);
	sort(ALL(Rs));
	while(Rs.back()>TH-H+1) Rs.pop_back();
	Rs.erase(unique(ALL(Rs)),Rs.end());
	FOR(i,Rs.size()-1) {
		st.sum[i+(1<<20)]=Rs[i+1]-Rs[i];
	}
	for(i=(1<<20)-1;i>=1;i--) st.sum[i]=st.sum[i*2]+st.sum[i*2+1];
	ll ret=0;
	int pre=0;
	int now=TH-H+1;
	FORR2(a,b,ev) {
		ret+=1LL*now*(a-pre);
		if(a==TW-W+1) break;
		pre=a;
		FORR(v,b) {
			x=v;
			if(v<0) x=-v;
			int aa=lower_bound(ALL(Rs),max(x-H,0))-Rs.begin();
			int bb=lower_bound(ALL(Rs),min(x,TH-H+1))-Rs.begin();
			if(v>=0) st.update(aa,bb,1);
			else st.update(aa,bb,-1);
		}
		now=st.sum[1];
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
