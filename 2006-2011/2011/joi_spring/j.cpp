#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class SegTree_3 {
public:
	int val;
	int ma;
	ll L,R;
	SegTree_3 *le,*ri;
	SegTree_3(ll LL,ll RR){
		L=LL;
		R=RR;
		val=ma=0;
		le=ri=NULL;
	};
	
	int ask(int v) {
		if(v>ma) return -1<<30;
		v-=val;
		if(v<=0) return R-1;
		
		if(ri) {
			int ret=ri->ask(v);
			if(ret>=0) return ret;
		}
		if(le) {
			int ret=le->ask(v);
			if(ret>=0) return ret;
		}
		return -1<<30;
	}
	
	void update(int x,int y, int v) {
		if(x<=L && R<=y) {
			val+=v;
			ma+=v;
		}
		else if(L < y && x < R) {
			if(le==NULL) le=new SegTree_3(L,(L+R)/2);
			if(ri==NULL) ri=new SegTree_3((L+R)/2,R);
			le->update(x,y,v);
			ri->update(x,y,v);
			ma=max(le->ma,ri->ma)+val;
		}
	}
};

ll M,B;
SegTree_3 root(0,1LL<<32);
multiset<int> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>B;
	while(M--) {
		cin>>s;
		if(s=="E") break;
		cin>>x;
		if(s=="A") {
			S.insert(x);
			root.update(x,x+B+1,1);
		}
		else {
			y=root.ask(x);
			if(y<0) {
				cout<<"NO"<<endl;
			}
			else {
				vector<int> R;
				while(x--) {
					auto it=prev(S.lower_bound(y+1));
					R.push_back(*it);
					root.update(*it,*it+B+1,-1);
					S.erase(it);
				}
				reverse(ALL(R));
				FOR(i,R.size()) {
					cout<<R[i];
					if(i<R.size()-1) cout<<" ";
				}
				cout<<endl;
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
