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


int N,Q;
string T[101010];
string S[101010];
int A[101010];
int id[101010];
vector<pair<int,int>> V;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> bt;

map<string,int> C;
int total,hi;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i]>>A[i];
		V.push_back({A[i],i});
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i+N]>>S[i+N];
		if(T[i+N]=="+") {
			cin>>A[i+N];
			V.push_back({A[i+N],i+N});
		}
	}
	sort(ALL(V));
	reverse(ALL(V));
	FOR(i,V.size()) id[V[i].second]=i;
	
	FOR(i,N) {
		C[S[i]]=i;
		bt.add(id[i],1);
	}
	
	total=N;
	hi=N/5;
	FOR(i,Q) {
		//cout<<total<<" "<<hi<<" "<<T[i+N]<<" "<<S[i+N]<<endl;
		if(T[i+N]=="-") {
			x=C[S[i+N]];
			if(total%5==0) {
				if(bt(id[x])>hi) {
					y=bt.lower_bound(hi);
					_P("%s is not working now.\n",S[V[y].second].c_str());
				}
				hi--;
			}
			else {
				if(bt(id[x])<=hi) {
					y=bt.lower_bound(hi+1);
					_P("%s is working hard now.\n",S[V[y].second].c_str());
				}
			}
			total--;
			bt.add(id[x],-1);
		}
		else {
			C[S[i+N]]=i+N;
			bt.add(id[i+N],1);
			if(total%5==4) {
				total++;
				hi++;
				if(bt(id[i+N])<=hi) {
					_P("%s is working hard now.\n",S[i+N].c_str());
				}
				else {
					_P("%s is not working now.\n",S[i+N].c_str());
					x=bt.lower_bound(hi);
					_P("%s is working hard now.\n",S[V[x].second].c_str());
				}
			}
			else {
				total++;
				if(bt(id[i+N])<=hi) {
					_P("%s is working hard now.\n",S[i+N].c_str());
					x=bt.lower_bound(hi+1);
					_P("%s is not working now.\n",S[V[x].second].c_str());
				}
				else {
					_P("%s is not working now.\n",S[i+N].c_str());
				}
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
