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


class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int mi=1<<30;
		int i;
		FOR(i,100) {
			int s=targetSeconds-(60*i);
			if(s<0||s>99) continue;
			string S;
			if(i) {
				S="000"+to_string(s);
				S=to_string(i)+S.substr(S.size()-2);
			}
			else {
				S=to_string(s);
			}
			int cur=startAt;
			int a=S.size()*pushCost;
			FORR(c,S) {
				c-='0';
				if(cur!=c) a+=moveCost;
				cur=c;
			}
			mi=min(mi,a);
		}
        return mi;
    }
};
