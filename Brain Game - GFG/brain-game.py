#User function Template for python3

class Solution:
	def brainGame(self, nums):
		# Code here
		x=[0]*1005
        for i in range(2,1001):
            for j in range(2*i,1001,i):
                x[j]= max(x[j],1+x[i]);
        b=0;
        for i in range(len(nums)):
            b=b^x[nums[i]];
        if(b==0):
            return False
        return True;

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		nums = list(map(int,input().split()))
		ob = Solution()
		ans = ob.brainGame(nums)
		if(ans):
			print("A")
		else:
			print("B")

# } Driver Code Ends