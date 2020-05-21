28.78;0
# 利用堆的特性，构造两个堆，第一个堆是一个最大堆，堆顶为最大值；第二个堆是一个最小堆，堆顶为最小值；
# 保证第一个堆的堆顶小于第二个堆的堆顶，并保证两个堆的元素个数差距不超过1，那么两个堆顶就是在中间的元素
# 408ms, 28.78%; 25MB, 0%
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minHeap = []
        self.maxHeap = []
        

    def addNum(self, num: int) -> None:
        if len(self.minHeap) == 0:
            self.minHeap.append(num)
        elif len(self.maxHeap) == 0:
            if num > self.minHeap[0]:
                self.maxHeap.append(num)
            else:
                self.maxHeap.append(self.minHeap[0])
                self.minHeap[0] = num
        elif len(self.minHeap) == len(self.maxHeap):
            if num <= self.maxHeap[0]:
                #print('step1')
                self.insert(0, num)
            elif num >= self.minHeap[0]:
                self.insert(1, num)
        elif len(self.minHeap) == len(self.maxHeap) + 1:
            if num >= self.minHeap[0]:
                self.insert(1, num)
            else:
                self.insert(1, self.minHeap[0])
                self.substitute(0, num)
                
        elif len(self.minHeap) == len(self.maxHeap) - 1:
            if num <= self.maxHeap[0]:
                self.insert(0, num)
            else:
                self.insert(0, self.maxHeap[0])
                self.substitute(1, num)
            
            
    def insert(self, flag, value):
        if flag == 0:
            self.minHeap.append(value)
            i = len(self.minHeap) - 1
            while i != 0:
                if i % 2 == 0:
                    if self.minHeap[i] > self.minHeap[i//2-1]:
                        temp = self.minHeap[i]
                        self.minHeap[i] = self.minHeap[i//2-1]
                        self.minHeap[i//2-1] = temp
                        i = i//2-1
                    else:
                        break
                else:
                    #print('step2')
                    if self.minHeap[i] > self.minHeap[i//2]:
                        temp = self.minHeap[i]
                        self.minHeap[i] = self.minHeap[i//2]
                        self.minHeap[i//2] = temp
                        i = i//2
                    else:
                        break
        else:
            self.maxHeap.append(value)
            i = len(self.maxHeap) - 1
            while i != 0:
                if i % 2 == 0:
                    if self.maxHeap[i] < self.maxHeap[i//2-1]:
                        temp = self.maxHeap[i]
                        self.maxHeap[i] = self.maxHeap[i//2-1]
                        self.maxHeap[i//2-1] = temp
                        i = i//2-1
                    else:
                        break
                else:
                    if self.maxHeap[i] < self.maxHeap[i//2]:
                        temp = self.maxHeap[i]
                        self.maxHeap[i] = self.maxHeap[i//2]
                        self.maxHeap[i//2] = temp
                        i = i//2
                    else:
                        break
    
    def substitute(self, flag, value):
        if flag == 0:
            self.minHeap[0] = value
            length = len(self.minHeap)
            i = 0
            while i*2+1 < length:
                if i*2+2 < length:
                    if self.minHeap[i*2+1] <= self.minHeap[i*2+2] and self.minHeap[i] < self.minHeap[i*2+2]:
                        temp = self.minHeap[i]
                        self.minHeap[i] = self.minHeap[i*2+2]
                        self.minHeap[i*2+2] = temp
                        i = i*2+2
                    elif self.minHeap[i*2+1] > self.minHeap[i*2+2] and self.minHeap[i] < self.minHeap[i*2+1]:
                        temp = self.minHeap[i]
                        self.minHeap[i] = self.minHeap[i*2+1]
                        self.minHeap[i*2+1] = temp
                        i = i*2+1
                    else:
                        break
                else:
                    if self.minHeap[i] < self.minHeap[i*2+1]:
                        temp = self.minHeap[i]
                        self.minHeap[i] = self.minHeap[i*2+1]
                        self.minHeap[i*2+1] = temp
                        i = i*2+1
                    else:
                        break
        else:
            #print('substiture: {}'.format(value))
            self.maxHeap[0] = value
            length = len(self.maxHeap)
            i = 0
            while i*2+1 < length:
                if i*2+2 < length:
                    if self.maxHeap[i*2+1] >= self.maxHeap[i*2+2] and self.maxHeap[i] > self.maxHeap[i*2+2]:
                        temp = self.maxHeap[i]
                        self.maxHeap[i] = self.maxHeap[i*2+2]
                        self.maxHeap[i*2+2] = temp
                        i = i*2+2
                    elif self.maxHeap[i*2+1] < self.maxHeap[i*2+2] and self.maxHeap[i] > self.maxHeap[i*2+1]:
                        temp = self.maxHeap[i]
                        self.maxHeap[i] = self.maxHeap[i*2+1]
                        self.maxHeap[i*2+1] = temp
                        i = i*2+1
                    else:
                        break
                else:
                    if self.maxHeap[i] > self.maxHeap[i*2+1]:
                        temp = self.maxHeap[i]
                        self.maxHeap[i] = self.maxHeap[i*2+1]
                        self.maxHeap[i*2+1] = temp
                        i = i*2+1
                    else:
                        break
        
            

    def findMedian(self) -> float:
        #print('{} /// {}'.format(self.minHeap, self.maxHeap))
        if len(self.minHeap) == len(self.maxHeap):
            return (self.minHeap[0] + self.maxHeap[0]) / 2.0
        elif len(self.minHeap) == len(self.maxHeap) + 1:
            return float(self.minHeap[0])
        elif len(self.minHeap) == len(self.maxHeap) - 1:
            return float(self.maxHeap[0])
        else:
            print('something is wrong')


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()