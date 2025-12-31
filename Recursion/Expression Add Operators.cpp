class Solution {
public:
    void Solve(int index, string &num, int target,
               vector<string> &out, string &list,
               long long result, long long prevnum) {

        if (index == num.size()) {
            if (result == target)
                out.push_back(list);
            return;
        }

        long long number = 0;
        int len = list.size();

        for (int i = index; i < num.size(); i++) {

            // 🚫 leading zero case
            if (i > index && num[index] == '0') break;

            number = number * 10 + (num[i] - '0');
            string curr = num.substr(index, i - index + 1);

            if (index == 0) {
                list += curr;
                Solve(i + 1, num, target, out, list, number, number);
                list.resize(len);
            } else {
                list += "+" + curr;
                Solve(i + 1, num, target, out, list,
                      result + number, number);
                list.resize(len);

                list += "-" + curr;
                Solve(i + 1, num, target, out, list,
                      result - number, -number);
                list.resize(len);

                list += "*" + curr;
                Solve(i + 1, num, target, out, list,
                      result - prevnum + prevnum * number,
                      prevnum * number);
                list.resize(len);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> out;
        string list;
        Solve(0, num, target, out, list, 0, 0);
        return out;
    }
};
