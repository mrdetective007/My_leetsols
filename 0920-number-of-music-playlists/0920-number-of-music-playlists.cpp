class Solution {
public:
    const int MOD = 1e9 + 7;

    long Playlists(int len, int uniq, int k, vector<vector < int>> &dp, int n){
        if (len == 0 && uniq == 0)
            return 1LL;
        if (len == 0 || uniq == 0)
            return 0LL;
        if (dp[len][uniq] != -1)
            return dp[len][uniq];

        long replayOldSong = 0LL;
        long addNewSong = (Playlists(len - 1, uniq - 1, k, dp, n) *(n - uniq + 1)) % MOD;
        if (uniq > k)
            replayOldSong = (Playlists(len - 1, uniq, k, dp, n) *(uniq - k)) % MOD;

        return dp[len][uniq] = (addNewSong + replayOldSong) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k){
        
        vector<vector < int>> dp(goal + 1, vector<int> (n + 1, -1));
        return Playlists(goal, n, k, dp, n);
    }
};