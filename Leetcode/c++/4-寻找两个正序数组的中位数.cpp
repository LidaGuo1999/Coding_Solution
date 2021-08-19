/*
 *
 *
 *
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size()+nums2.size();
        int mid = count/2+1;
        int i = 0, j = 0, cnt = 0, n1 = -1, n2 = -1;

        while (i < nums1.size() && j < nums2.size()) {
            int tmp;
            if (nums1[i] <= nums2[j]) {
                tmp = nums1[i];
                i++;
            }
            else {
                tmp = nums2[j];\
                j++;
            }
            cnt++;
            if (cnt == mid-1) {
                n1 = tmp;
            } else if (cnt == mid) {
                n2 = tmp;
                break;
            }
        }
        while (cnt < mid && i < nums1.size()) {
            int tmp = nums1[i];
            i++;
            cnt++;
            if (cnt == mid-1) {
                n1 = tmp;
            } else if (cnt == mid) {
                n2 = tmp;
                break;
            }
        }
        while (cnt < mid && j < nums2.size()) {
            int tmp = nums2[j];
            j++;
            cnt++;
            if (cnt == mid-1) {
                n1 = tmp;
            } else if (cnt == mid) {
                n2 = tmp;
                break;
            }
        }

        if (count%2 == 0) {
            return ((double)n1+(double)n2)/2.0;
        } else {
            if (count == 1) return (double)n2;
            else return (double)n2;
        }
    }
};



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        int mid = total/2, k = mid;
        int i = 0, j = 0, ans1 = -1, ans2 = -2;

        if (total == 1) {
            if (nums1.size() == 1) return nums1[0];
            else if (nums2.size() == 1) return nums2[0];
        } 
        
        while (i < nums1.size() && j < nums2.size()) {
            //printf("%d %d %d\n", k, i, j);
            if (k == 1) {
                if (nums1[i] <= nums2[j]) {
                    ans1 = nums1[i];
                    i++;
                } else {
                    ans1 = nums2[j];
                    j++;
                }
                k = 0;
                break;
            }
            int move = k/2, ti = min(i+move-1, (int)nums1.size()-1), tj = min(j+move-1, (int)nums2.size()-1);
            if (ti < nums1.size() && tj < nums2.size()) {
                if (nums1[ti] <= nums2[tj]) {
                    k -= ti-i+1;
                    i = ti+1;
                } else {
                    k -= tj-j+1;
                    j = tj+1;
                }
            } else if (ti < nums1.size()) { 
                k -= nums2.size()-j;
                j = ti+1;
            } else if (tj < nums2.size()) {
                k -= nums1.size()-i;
                i = tj+1;
            }
        }
        if (i < nums1.size() && k >= 1) {
            ans1 = nums1[i+k-1];
            i += k;
        }
        if (j < nums2.size() && k >= 1) {
            ans1 = nums2[j+k-1];
            j += k;
        }

        if (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                    ans2 = nums1[i];
                    i++;
                } else {
                    ans2 = nums2[j];
                    j++;
                }
        } else if (i < nums1.size()) {
            ans2 = nums1[i];
            i++;
        } else if (j < nums2.size()) {
            ans2 = nums2[j];
            j++;
        }

        if (total%2 == 0) {
            //printf("%d %d\n", ans1, ans2);
            return (double)(ans1+ans2)/2.0;
        } else {
            //printf("%d %d\n", ans1, ans2);
            return (double)ans2;
        }
    }
};
