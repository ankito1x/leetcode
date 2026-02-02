from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        n = len(nums)
        result = nums[0]
        
        selected = SortedList()
        candidates = SortedList()
        current_sum = 0
        
        for i in range(1, min(n, dist + 2)):
            selected.add(nums[i])
            current_sum += nums[i]
            
            if len(selected) >= k:
                largest = selected.pop()
                current_sum -= largest
                candidates.add(largest)
        
        min_cost = result + current_sum
        
        for i in range(dist + 2, n):
            new_val = nums[i]
            
            if not selected or new_val <= selected[-1]:
                selected.add(new_val)
                current_sum += new_val
                
                if len(selected) > k - 1:
                    largest = selected.pop()
                    current_sum -= largest
                    candidates.add(largest)
            else:
                candidates.add(new_val)
            
            left_val = nums[i - dist - 1]
            
            if left_val in selected:
                selected.remove(left_val)
                current_sum -= left_val
                
                if candidates:
                    smallest = candidates.pop(0)
                    selected.add(smallest)
                    current_sum += smallest
            else:
                candidates.remove(left_val)
            
            min_cost = min(min_cost, result + current_sum)
        
        return min_cost