class Node:
    data = None
    next = None

    def __init__(self, data):
        self.data = data

head = Node(1)
n1 = Node(2)
n2 = Node(3)
n3 = Node(4)
# n4 = Node(5)
# n5 = Node(6)

head.next = n1
n1.next = n2
n2.next = n3
# n3.next = n4
# n4.next = n5

def pl(head):
    if not head:
        return
    print(head.data)
    pl(head.next)

def lstlast(head):
    if not head:
        return
    if not head.next:
        return head
    return (lstlast(head.next))

def rotate(head):
    first = lstlast(head).data
    curr = head.next
    aux = head.data
    while curr.next:
        next = curr.data
        curr.data = aux
        aux = next 
        curr = curr.next
    curr.data = aux
    head.data = first
    return head

head = rotate(head)
pl(head)
