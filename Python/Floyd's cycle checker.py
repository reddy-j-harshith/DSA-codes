# This code is to check for cycles in a directed graph
# which can be represented by a Linked List in which
# the nodes are pointing to the next

def cycle(llist):
    slow = llist.head
    fast = llist.head
    met = False
    while fast is not None and fast.nxt is not None:
        slow = slow.next
        fast = fast.nxt.nxt
        if slow == fast:
            met = True
            break
    if not met:
        return None
    else:
        slow = llist.head
        while slow != fast:
            slow = slow.nxt
            fast = fast.next
    return slow


# Time complexity of O(n) and Space complexity of O(1).
# Floyd's Algorithm can also be used to find the duplicates
# when we are given an array size of n + 1 to be filled with
# n distinct integers.

# Solution: Represent the given number in a Linked List in a
# way that each node points to the index of its value.

# Ex: 4  3  7  8  6  9  2  1  5  2
# The first node '4' will point to the index 4.
# Here the two nodes '2' will point to the same node '7'.
# For the sake of solving the question, we don't even need to
# create a linked list.

def find_duplicate(arr):
    slow = 0
    fast = 0
    while True:
        slow = arr[slow]
        fast = arr[arr[fast]]
        if slow == fast:
            break
    slow = 0
    while slow != fast:
        slow = arr[slow]
        fast = arr[fast]
    return slow


array = (4, 3, 7, 8, 6, 9, 2, 1, 5, 2)
value = find_duplicate(array)
print(f"The entry duplicate value in the given array is: {value}")
