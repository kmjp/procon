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

map<string,int> A;
vector<int> B[10101];

class TweetCounts {
public:
    TweetCounts() {
		A.clear();
		int i;
		FOR(i,10050) B[i].clear();
        
    }
    
    void recordTweet(string tweetName, int time) {
		if(A.count(tweetName)==0) {
			int x=A.size();
			A[tweetName]=x;
		}
		int x=A[tweetName];
		B[x].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
		vector<int> V;
		endTime++;
		int span;
		if(freq=="second") span=1;
		if(freq=="minute") span=60;
		if(freq=="hour") span=3600;
		if(freq=="day") span=3600*24;
		V.resize((endTime-startTime+span-1)/span);
		if(A.count(tweetName)==0) return V;
		int x=A[tweetName];
		FORR(b,B[x]) {
			if(b>=startTime && b<endTime) {
				V[(b-startTime)/span]++;
			}
		}
		return V;
		
		
        
    }
};

