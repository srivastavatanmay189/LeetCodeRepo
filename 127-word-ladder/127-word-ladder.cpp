class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int posi=-1;
        int x=0;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord){
                posi=i;
                break;
            }
        }
        if(posi==-1)
            return 0;
        vector<int> visi(n,-1);
        unordered_map<int,vector<int>> mp;
        queue<pair<int,string>> q;
        q.push({0,beginWord});
        
        while(!q.empty()){
            string xy=q.front().second;
            int val=q.front().first;
            q.pop();
            
            for(int i=0;i<n;i++){
                int count=0;
                // cout<<xy<<" "<<wordList[i]<<" "<<endl;
                for(int j=0;j<xy.length();j++){
                    if(xy[j]!=wordList[i][j])
                        count++;
                }
                // cout<<count<<" ";
                if(count==1 && visi[i]==-1){
                    // cout<<"Heelo";
                    mp[val].push_back(i+1);
                    visi[i]=1;
                    q.push({i+1,wordList[i]});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(auto y:mp[i]){
        //         cout<<i<<" "<<y;
        //     }
        //     cout<<endl;
        // }
        if(visi[posi]==-1)
            return 0;
        
        queue<int> qi;
        qi.push(0);
        qi.push(-1);
        int ans=1;
        vector<int> visit(n,-1);
        // visit[0]=1;
        while(!qi.empty()){
            int xyz=qi.front();
            qi.pop();
            
            if(xyz==-1){
                ans++;
                if(!qi.empty()){
                    qi.push(-1);
                }
            }
            else{
                for(auto xi:mp[xyz]){
                    if(posi+1==xi)
                        return ans+1;
                    
                    // if(visit[xi-1]==-1){
                        qi.push(xi);
                        // visit[xi-1];
                    // }
                }
            }
        }
        return -1;
        
    }
};