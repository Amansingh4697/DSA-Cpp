class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // int time  = 0;
        // int freq[26] = {0};
        // int cooldown[26] = {0};
        // // step1: calculate frequency
        // for(int i = 0;i<tasks.size();i++){
        //   freq[tasks[i]-'A']++;
        // }
        // // step2 : loop till maps has element if not break
        // while(true){
        //     bool done = true;
        //     // does any tasks remaining if not break
        //     for(int i = 0;i<26;i++){
        //         if(freq[i]>0){
        //             done = false;
        //             break;
        //         }
        //     }
        //     if(done) break;
        //     int maxFreq = 0;
        //     int bestIndex = -1;
        //     // find best availabe task
        //    for(int i = 0;i<26;i++){
        //     if(cooldown[i]<=time && freq[i]>0){
        //       if(freq[i]>maxFreq){
        //         maxFreq = freq[i];
        //         bestIndex = i;
        //       }
        //     }
        //    }
        //  if(bestIndex != -1){
        //     freq[bestIndex]--;
        //     cooldown[bestIndex] = time + n + 1;
        //  }
        //  time++;
        // } 
        //  return time; 
        int time = 0;  
        vector<int> freq(26, 0);
        for(int i = 0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(auto &it:freq){
            if(it>0){
                pq.push(it);
            }
        }
        while(!pq.empty()){
            vector<int> temp;
            for(int i = 1;i<=n+1;i++){
                if(!pq.empty()){
                     int f = pq.top();
                     f--;
                     pq.pop();
                     temp.push_back(f);
                }
            }
            for(auto &f:temp){
                if(f>0){
                    pq.push(f);
                }
            }
            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += (n+1);
            }
        }
        return time;
    }
};
