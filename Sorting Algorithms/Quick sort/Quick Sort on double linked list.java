// A Java program to sort a linked list using Quicksort 
class QuickSort_using_Doubly_LinkedList{ 
	Node head; 
	
/* a node of the doubly linked list */
	static class Node{ 
		private int data; 
		private Node next; 
		private Node prev; 
		
		Node(int d){ 
			data = d; 
			next = null; 
			prev = null; 
		} 
	} 
	
// A utility function to find last node of linked list	 
	Node lastNode(Node node){ 
		while(node.next!=null) 
			node = node.next; 
		return node; 
	} 
	

/* Considers last element as pivot, places the pivot element at its 
correct position in sorted array, and places all smaller (smaller than 
pivot) to left of pivot and all greater elements to right of pivot */
	Node partition(Node l,Node h) 
	{ 
	// set pivot as h element 
		int x = h.data; 
		
		// similar to i = l-1 for array implementation 
		Node i = l.prev; 
		
		// Similar to "for (int j = l; j <= h- 1; j++)" 
		for(Node j=l; j!=h; j=j.next) 
		{ 
			if(j.data <= x) 
			{ 
				// Similar to i++ for array 
				i = (i==null) ? l : i.next; 
				int temp = i.data; 
				i.data = j.data; 
				j.data = temp; 
			} 
		} 
		i = (i==null) ? l : i.next; // Similar to i++ 
		int temp = i.data; 
		i.data = h.data; 
		h.data = temp; 
		return i; 
	} 
	
	/* A recursive implementation of quicksort for linked list */
	void _quickSort(Node l,Node h) 
	{ 
		if(h!=null && l!=h && l!=h.next){ 
			Node temp = partition(l,h); 
			_quickSort(l,temp.prev); 
			_quickSort(temp.next,h); 
		} 
	} 
	
	// The main function to sort a linked list. It mainly calls _quickSort() 
	public void quickSort(Node node) 
	{ 
		// Find last node 
		Node head = lastNode(node); 
		
		// Call the recursive QuickSort 
		_quickSort(node,head); 
	} 
	
	// A utility function to print contents of arr 
	public void printList(Node head) 
	{ 
		while(head!=null){ 
			System.out.print(head.data+" "); 
			head = head.next; 
		} 
	} 
	
	/* Function to insert a node at the beginning of the Doubly Linked List */
	void push(int new_Data) 
	{ 
		Node new_Node = new Node(new_Data);	 /* allocate node */
		
		// if head is null, head = new_Node 
		if(head==null){ 
			head = new_Node; 
			return; 
		} 
		
		/* link the old list off the new node */
		new_Node.next = head; 
		
		/* change prev of head node to new node */
		head.prev = new_Node; 
		
		/* since we are adding at the beginning, prev is always NULL */
		new_Node.prev = null; 
		
		/* move the head to point to the new node */
		head = new_Node; 
	} 
	
	/* Driver program to test above function */
	public static void main(String[] args){ 
			QuickSort_using_Doubly_LinkedList list = new QuickSort_using_Doubly_LinkedList(); 
			
			
			list.push(5); 
			list.push(20); 
			list.push(4); 
			list.push(3); 
			list.push(30); 
			
			
			System.out.println("Linked List before sorting "); 
			list.printList(list.head); 
			System.out.println("\nLinked List after sorting"); 
			list.quickSort(list.head); 
			list.printList(list.head); 
		
	} 
} 



Output :

Linked List before sorting
30  3  4  20  5
Linked List after sorting
3  4  5  20  30
