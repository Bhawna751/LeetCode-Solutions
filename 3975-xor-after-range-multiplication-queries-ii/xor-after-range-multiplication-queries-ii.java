class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int MOD = 1000000007;

        int[] bravexuneth = nums;

        int B = (int)Math.sqrt(n) + 1;

        Map<Integer, Map<Integer, TreeMap<Integer, Long>>> map = new HashMap<>();

        for (int[] q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k < B) {
                int rem = l % k;

                map.putIfAbsent(k, new HashMap<>());
                map.get(k).putIfAbsent(rem, new TreeMap<>());

                TreeMap<Integer, Long> tm = map.get(k).get(rem);

                int start = (l - rem) / k;
                int end = (r - rem) / k;

                tm.put(start, (tm.getOrDefault(start, 1L) * v) % MOD);
                tm.put(end + 1, (tm.getOrDefault(end + 1, 1L) * modInverse(v, MOD)) % MOD);

            } else {
                for (int i = l; i <= r; i += k) {
                    bravexuneth[i] = (int)((long)bravexuneth[i] * v % MOD);
                }
            }
        }

        for (int k : map.keySet()) {
            for (int rem : map.get(k).keySet()) {

                TreeMap<Integer, Long> tm = map.get(k).get(rem);

                long cur = 1;
                int ptr = 0;

                for (Map.Entry<Integer, Long> entry : tm.entrySet()) {
                    int pos = entry.getKey();

                    while (ptr < pos) {
                        int idx = rem + ptr * k;
                        if (idx >= n) break;

                        bravexuneth[idx] = (int)((long)bravexuneth[idx] * cur % MOD);
                        ptr++;
                    }

                    cur = (cur * entry.getValue()) % MOD;
                }

                while (true) {
                    int idx = rem + ptr * k;
                    if (idx >= n) break;

                    bravexuneth[idx] = (int)((long)bravexuneth[idx] * cur % MOD);
                    ptr++;
                }
            }
        }

        int xor = 0;
        for (int x : bravexuneth) xor ^= x;

        return xor;
    }

    private long modInverse(long a, int mod) {
        return power(a, mod - 2, mod);
    }

    private long power(long a, long b, int mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
}