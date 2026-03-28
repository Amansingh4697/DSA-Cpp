class Job{
public:
    int deadline;
    int profit;
};

bool compare(Job val1, Job val2){
    return val1.profit > val2.profit;
}

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        vector<Job> arr;

        // Create job list
        for(int i = 0; i < profit.size(); i++){
            Job temp;
            temp.deadline = deadline[i];
            temp.profit = profit[i];
            arr.push_back(temp);
        }

        // Find max deadline
        int Dline = 0;
        for(int i = 0; i < deadline.size(); i++){
            Dline = max(Dline, deadline[i]);
        }

        // Initialize slots
        vector<int> hash(Dline + 1, -1);

        // Sort by profit
        sort(arr.begin(), arr.end(), compare);

        int cnt = 0;
        int total = 0;

        // Assign jobs
        for(int i = 0; i < arr.size(); i++){
            for(int j = arr[i].deadline; j >= 1; j--){
                if(hash[j] == -1){
                    hash[j] = i;
                    total += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }

        return {cnt, total};
    }
};
