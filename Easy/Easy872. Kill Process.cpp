/*

requirements

872. Kill Process
In this problem, each process has a unique PID (process id) and PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

Example
Example 1:

Input: PID = [1, 3, 10, 5], PPID = [3, 0, 5, 3], killID = 5
Output: [5, 10]
Explanation: Kill 5 will also kill 10.
     3
   /   \
  1     5
       /
      10
Example 2:

Input: PID = [1, 2, 3], PPID = [0, 1, 1], killID = 2
Output: [2]
Notice
The given kill id is guaranteed to be one of the given PIDs.
There is at least one PID in the list.
*/

class Solution
{
  private:
    void dfs(int now, vector<int> &ans, map<int, vector<int>> &child)
    {
        ans.push_back(now);
        if (child.find(now) != child.end())
        {
            for (int next : child[now])
            {
                dfs(next, ans, child);
            }
        }
    }

  public:
    /**
     * @param pid: the process id
     * @param ppid: the parent process id
     * @param kill: a PID you want to kill
     * @return: a list of PIDs of processes that will be killed in the end
     */
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        int n = pid.size();
        map<int, vector<int>> child;
        for (int i = 0; i < n; i++)
        {
            if (child.find(ppid[i]) == child.end())
            {
                child[ppid[i]] = vector<int>();
            }
            child[ppid[i]].push_back(pid[i]);
        }

        vector<int> ans;
        dfs(kill, ans, child);

        return ans;
    }
};