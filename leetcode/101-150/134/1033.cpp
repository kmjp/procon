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
    vector<int> numMovesStones(int a, int b, int c) {
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		
        vector<int> R;
        R.push_back(0);
        R.push_back(b-a-1+c-b-1);
        if(a+1<b) R[0]++;
        if(b+1<c) R[0]++;
        if(a+2==b || b+2==c) R[0]=1;
		return R;
    }
};

