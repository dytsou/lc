package main

import (
	"bufio"
	"os"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}
	if list1.Val < list2.Val {
		list1.Next = mergeTwoLists(list1.Next, list2)
		return list1
	}
	list2.Next = mergeTwoLists(list1, list2.Next)
	return list2
}

func createList(input string) *ListNode {
	var head, tail *ListNode
	for _, val := range input {
		node := &ListNode{Val: int(val - '0')}
		if head == nil {
			head = node
			tail = node
		} else {
			tail.Next = node
			tail = node
		}
	}
	return head
}

func printList(head *ListNode) {
	for head != nil {
		if head.Next != nil {
			print(head.Val, " -> ")
		} else {
			print(head.Val)
		}
		head = head.Next
	}
	println()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input1 := scanner.Text()
	scanner.Scan()
	input2 := scanner.Text()

	list1 := createList(input1)
	list2 := createList(input2)

	result := mergeTwoLists(list1, list2)
	printList(result)
}
