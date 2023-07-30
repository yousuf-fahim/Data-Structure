class MinHeap:

    SMALLEST_NUMBER = -987654321

    def __init__(self, size):
        self.size = size
        self.heap = [self.SMALLEST_NUMBER] * (self.size + 1)
        self.current_pointer = 1

        print(self.heap)


    def top(self):
    
        if self.current_pointer == 1:
            return "Heap is empty"

        return self.heap[1]

    def insert(self, element):

        if self.current_pointer > self.size:
            print("Max number of elements reached, couldn't insert")
            return

        index = self.current_pointer
        self.current_pointer+=1
        self.heap[index] = element
        parent = self.current_pointer // 2

        while parent >= 1 and self.heap[parent] > element:
            self.heap[parent], self.heap[index] = self.heap[index], self.heap[parent]
            index = parent
            parent = index // 2

    def pop(self):

        if self.current_pointer == 1:
            print("Heap is already empty")
            return

        self.current_pointer-=1
        self.heap[1] = self.heap[self.current_pointer]
        self.heap[self.current_pointer] = self.SMALLEST_NUMBER
        index = 1

        print(self.heap)

        while index < self.current_pointer:

            left = 2 * index
            right = left + 1

            if left < self.current_pointer and self.heap[left] < self.heap[index]:
                self.heap[left], self.heap[index] = self.heap[index], self.heap[left]
                index = left
            elif right < self.current_pointer and self.heap[right] < self.heap[index]:
                self.heap[right], self.heap[index] = self.heap[index], self.heap[right]
                index = right
            else:
                break

    def __str__(self) -> str:
        return str(self.heap)


if __name__ == "__main__":

    heap = MinHeap(6)
    print(heap.top())
    heap.insert(3)
    heap.insert(2)
    heap.insert(5)
    heap.insert(1)
    print(heap.top())
    heap.insert(2)
    heap.insert(-100)
    print(heap)
    heap.pop()
    print(heap.top())
