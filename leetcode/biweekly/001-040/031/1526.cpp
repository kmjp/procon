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

    int minNumberOperations(vector<int>& target) {
		ll ret=0;
		vector<int> V;
		V.push_back(0);
		FORR(t,target) {
			int la=0;
			while(V.back()>t) V.pop_back(), la=1;
			if(la==0) ret+=t-V.back();
			V.push_back(t);
		}
        return ret;
    }
};
