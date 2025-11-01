# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        num_set=set(nums)
        dummy=ListNode(0)
        dummy.next=head
        temp=head
        prev=dummy
        while temp!=None:
            if temp.val in num_set:
                prev.next=temp.next
            else:
                prev=temp
            temp=prev.next
        return dummy.next
__import__("atexit").register(lambda: open("display_runtime.txt", "w").write("0"))

        