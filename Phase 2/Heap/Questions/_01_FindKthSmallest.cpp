// l : starting index of array 0
// r : ending index of array size-1
// k : find smallest element using this function kthSmallest
#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;

    // step 1: first k elements(0 ---> k-1)
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step 2: remaining element (k ---> r)
    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step 3: return root
    int ans = pq.top();
    return ans;
}

int main()

{
    int arr[] = {7, 10, 4, 20, 15};
    int size = 5;
    int k = 4;
    int small = kthSmallest(arr, 0, size - 1, k);
    cout << k << "th smallest element is " << small << endl;

    return 0;
}

 
 
// void InsertAtPosition(Node *&head, Node *&tail, int d, int positon)
// {
//     if (positon == 1)
//     {
//         InsertAtHead(head, d);
//     }
//     else
//     {

//         Node *temp = head;
//         int count = 1;
//         while (count < positon - 1)
//         {
//             temp = temp->next;
//             count++;
//         }
//         if (temp->next == NULL)
//         {
//             InsertAtTail(tail, d);
//         }
//         Node *nodeToInsert = new Node(d);
//         nodeToInsert->next = temp->next;
//         temp->next = nodeToInsert;
//     }
// }
