class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int bCount = 0;
        int deletions = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'b') {
                bCount++;
            } else {
                deletions = Math.min(deletions + 1, bCount);
            }
        }
        
        return deletions;
    }
}