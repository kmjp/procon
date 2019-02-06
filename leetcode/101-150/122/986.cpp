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
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
		vector<pair<int,int>> P;
		FORR(a,A) FORR(b,B) {
			int L=max(a.start,b.start);
			int R=min(a.end,b.end);
			if(L<=R) P.push_back({L,R});
		}
		sort(ALL(P));
		vector<Interval> R;
		FORR(p,P) R.push_back(Interval(p.first,p.second));
		return R;
        
    }
};
