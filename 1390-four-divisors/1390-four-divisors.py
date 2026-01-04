class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        cnt = 0
        for num in nums:
            dividers = [1, num]
            for i in range(2, int(math.sqrt(num)) + 1):
                if num % i == 0:
                    dividers.append(i)
                    if num // i != i:
                        dividers.append(num // i)
                if len(dividers) > 4:
                    break

            if len(dividers) == 4:
                cnt += sum(dividers)
        
        return cnt
        
        