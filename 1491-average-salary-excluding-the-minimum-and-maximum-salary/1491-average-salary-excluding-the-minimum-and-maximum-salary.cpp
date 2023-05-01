class Solution {
public:
    double average(vector<int>& salaries) {
        int minSalary = INT_MAX, maxSalary = INT_MIN, sum = 0;
        for (auto &salary : salaries) {
            sum += salary;
            minSalary = min(minSalary, salary);
            maxSalary = max(maxSalary, salary);
        }
        return (sum - minSalary - maxSalary) / (double)(salaries.size() - 2);
    }
};