class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        Map<Integer, Integer> mpp = new HashMap<>();
        int[] ans = new int[nums1.length];
        for(int i=nums2.length-1;i>=0;i--){
            while(!st.isEmpty() && st.peek()<= nums2[i]){
                st.pop();
            }
            if(st.isEmpty()){
                mpp.put(nums2[i],-1);
            }
            else mpp.put(nums2[i], st.peek());
            st.push(nums2[i]);
        }
        int i=0;
        for(int it: nums1){
            ans[i] = mpp.get(it);
            i++;
        }
        return ans;
    }
}