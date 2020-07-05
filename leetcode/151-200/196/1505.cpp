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




template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;


class Solution {
public:
    string minInteger(string num, int k) {
		set<int> S[10];
		int N=num.size();
		int i,j;
		ZERO(bt.bit);
		FOR(i,N) {
			S[num[i]-'0'].insert(i);
			bt.add(i,1);
		}
		
		string R;
		FOR(i,N) {
			FOR(j,10) if(S[j].size()) {
				int x=*S[j].begin();
				int y=bt(x);
				if(y<=k+1) {
					k-=y-1;
					R.push_back(j+'0');
					S[j].erase(S[j].begin());
					bt.add(x,-1);
					break;
				}
			}
		}
        return R;
    }
};

