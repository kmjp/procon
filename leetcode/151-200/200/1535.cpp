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
    int getWinner(vector<int>& arr, int k) {
		queue<int> Q;
		int cur=arr[0];
		int i;
		for(i=1;i<arr.size();i++) Q.push(arr[i]);
		int win=0;
		k=min(k,1000000);
		while(win<k) {
			i=Q.front();
			Q.pop();
			if(cur>i) {
				win++;
				Q.push(i);
			}
			else {
				win=1;
				Q.push(cur);
				cur=i;
			}
			
		}
		return cur;
		
        
    }
};

