class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        ans=[]
        adj=[[] for _ in range(numCourses)]
        
        for i in range(len(prerequisites)):
            adj[prerequisites[i][0]].append(prerequisites[i][1])
        print(adj)
        for i in range(len(queries)):
            tar=queries[i][1]
            q=[]
            f=0
            q.append(queries[i][0])
            vis=[0 for _ in range(numCourses)]
            while(len(q)!=0 and f==0):
                x=len(q)
                while(x>0 and f==0):
                    x-=1
                    node=q.pop(0)
                    for j in adj[node]:
                        if(vis[j]==0):
                            q.append(j)
                            vis[j]=1
                            if(j==tar):
                                ans.append(True)
                                f=1
                                break
            if(f==0):
                ans.append(False)
        return ans
                    
        