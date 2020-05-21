from typing import List
# 使用堆的思想，维护一个大小为k的最小堆，其中存储的是当前最大的k个数。然后遍历数组，如果数组元素大于当前堆顶元素，
# 就替换当前堆顶元素并向下传播。最终便利完后堆顶元素就是当前第k大的元素
# 128ms, 33.98%; 14.2MB, 15.79%
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = [-66535 for i in range(k)]
        for i in range(len(nums)):
            self.insert(heap, nums[i], k)
        return heap[0]
        
        
    def insert(self, heap, value, k):
        if value > heap[0]:
            heap[0] = value
            i = 0
            while i*2+1 < k:
                if i*2+2 < k:
                    if heap[i*2+1] <= heap[i*2+2] and value > heap[i*2+1]:
                        temp = heap[i]
                        heap[i] = heap[i*2+1]
                        heap[i*2+1] = temp
                        i = i*2+1
                    elif heap[i*2+1] >= heap[i*2+2] and value > heap[i*2+2]:
                        temp = heap[i]
                        heap[i] = heap[i*2+2]
                        heap[i*2+2] = temp
                        i = i*2+2
                    else:
                        break
                else:
                    if heap[i*2+1] < heap[i]:
                        temp = heap[i]
                        heap[i] = heap[i*2+1]
                        heap[i*2+1] = temp
                        i = i*2+1
                    else:
                        break

                
                
    
        