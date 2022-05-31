#User function Template for python3

class Solution:
	def nCrModM(self, n, r, m):
		# Code here
		def leastPrimeFactor(n):
           least_prime = [0] * (n + 1)
       
           least_prime[1] = 1
       
           for i in range(2, n + 1):
               if (least_prime[i] == 0):
                   least_prime[i] = i
       
                   for j in range(2 * i, n + 1, i):
                       if (least_prime[j] == 0):
                           least_prime[j] = i
           return least_prime
       
       
       # To compute x^y under modulo m
        def power(x, y, m):
           if (y == 0):
               return 1
       
           p = power(x, y // 2, m) % m
           p = (p * p) % m
       
           if (y % 2 == 0):
               return p
           else:
               return ((x * p) % m)
       
        def ncr_kris(n, r, p):
           if(n < r):
               return 0
           if(r > n - r):
               r = n - r
           num = den = 1
           for i in range(r):
               num = (num * (n - i)) % p
               den = (den * (i + 1)) % p
           ans =(num * power(den, p - 2, p)) % p
           return ans
       
           
        def toBaseB(N, B):
           digits = []
           while N > 0:
             digits.insert(0, N % B)
             N = N // B
           return digits
       
        def nCrModp_Lucas(n, r, p):
           m = toBaseB(n, p)
           n = toBaseB(r, p)
           l1 = len(m)
           l2 = len(n)
           ans = 1
           for i in range(l2):
               ans = (ans * ncr_kris(m[(l1-l2) + i], n[i], p)) % p
           return ans

        SPF = leastPrimeFactor(m)

        PrimeFactors = []

        x = m

        i = 0

        ans = 0

        while x != 1:

           PrimeFactors.append(SPF[x])

           ans = ans + ((nCrModp_Lucas(n, r, PrimeFactors[i]) * (m//PrimeFactors[i]) * (power(m//PrimeFactors[i], PrimeFactors[i] - 2, PrimeFactors[i]))) % m)

           i += 1

           x = x // SPF[x]

        return ans % m


#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n, r, m = input().split()
		n = int(n)
		r = int(r)
		m = int(m)
		obj = Solution()
		ans = obj.nCrModM(n, r, m)
		print(ans)


# } Driver Code Ends