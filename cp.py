# class Solution:
#     def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         # hold = None
#         # itr = head

#         # while(itr.next):
#         #     if itr.val > itr.next.val:
#         #         itr.next = itr.next.next
#         #         itr.next.next = itr
#         #         head = itr.next
#         #     else:
#         #         itr = itr.next

#         m = dict()
#         itr = head
#         while(itr):
#             m[itr.val] = itr.next
#             itr = itr.next

#         l = sorted(list(m.keys()))
#         head = m[l[0]]
#         temp = head
#         for i in range(0, len(l)-1):
#             temp.next = m[l[i+1]]
#             temp = temp.next
#         while(itr):
#             # m[itr.val] = itr.next
#             print(itr.val)
#             itr = itr.next

#         return head

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        hashmap = set()
        i, j = 0, 0
        counter = 0
        while(j < len(s)):
            
            if (s[j] in hashmap):
                if (j-i > counter):
                    print('counter updated to ', j-i)
                    counter = j-i
                while(s[i]!=s[j]):
                    print('removed: ', s[i])
                    hashmap.remove(s[i])
                    i+=1
                print('removed: ', s[i])
                hashmap.remove(s[i])
                i+=1
            else:
                print('value of j: ', j)
                print('adding: ', s[j])
                hashmap.add(s[j])
                # counter+=1
                j+=1
        return(counter)

print(Solution().lengthOfLongestSubstring("pwwkew"))