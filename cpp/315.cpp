class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        idx.resize(n);
        tmp.resize(n);
        result.resize(n, 0);
        this->nums = nums;
        iota(idx.begin(), idx.end(), 0); // fill idx with 0, 1, 2, ..., n-1
        if(n > 0) mergeSort(0, n - 1);
        return result;
    }
private:
    vector<int> idx; // index of the element in the original array
    vector<int> tmp; // temporary array to store the merged result
    vector<int> result; // result array to store the count of smaller numbers after self
    vector<int> nums;
    void mergeSort(int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
    void merge(int left, int mid, int right) {
        int a = left, b = mid + 1, k = left, movedRight = 0;
        while(a <= mid && b <= right) {
            // if the element at idx[b] is smaller than the element at idx[a], move it to the right
            // and increment the count of moved elements for the element at idx[b]
            if(nums[idx[b]] < nums[idx[a]]) {
                tmp[k++] = idx[b++];
                movedRight++;
            }
            // if the element at idx[a] is smaller than the element at idx[b], increment the count of smaller elements for the element at idx[a]
            // and move the element at idx[a] to the right
            else {
                result[idx[a]] += movedRight;
                tmp[k++] = idx[a++];
            }
        }
        while(a <= mid) {
            result[idx[a]] += movedRight;
            tmp[k++] = idx[a++];
        }
        while(b <= right) tmp[k++] = idx[b++];
        for(int i = left; i <= right; i++) idx[i] = tmp[i];
    }
};