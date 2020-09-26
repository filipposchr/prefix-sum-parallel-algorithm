#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

class Node {
    public:
        int sum; //sum for each node
        int left;
        int index;
        
        Node(int s, int idx) {
            sum = s;
            index = idx;
            left = 0; //starting with 0 value for the root
        } 
};

/* Traverse balanced binary tree from Leaves to Nodes */
void up_traverse(vector<Node> & node)
{
    int size = node.size();
    int level = log2(size) - 1;
    for (unsigned int d = 0; d <= log2(size)-1; ++d) {
        int r = pow(2, d+1);
        int k = (size - 1) % r + 1;
        int j = 0;
       
        cout << endl << "Level: " << level-- << endl;
        while (j < size - 1) {
            node[j + pow(2, d + 1) - 1].sum += node[j + pow(2, d) - 1].sum;
            cout << "Sum node: " << node[j + pow(2, d + 1) - 1].sum << endl;
            j = j + k;
        }
    }
    cout << endl;
}

/* Traverse balanced binary tree from node to leaves */
void down_traverse(vector<Node> & node)
{
    int size = node.size();
    int d = (log2(size) - 1);
    
    for (d ; d >= 0; --d) {
        int r =  pow(2, d + 1);
        int k = (size - 1) % r ;
        int j = 0;

        /* pass left value to left child, and sum value of its left value plus 
           the sum value of left child to the right child
        */
        while (j < size - 1) {
            node[j + pow(2, d) - 1].left = node[j + pow(2, d + 1) - 1].left; //left child
            node[j + pow(2, d + 1) - 1].left += node[j + pow(2, d) - 1].sum; //right child
            j = j + k;
        }
    }
}

int main() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> random_number(0,1000); //produce random numbers from [0,1000]

    int numbers = 8; //set how many numbers for input sequence
    int arr_ran_numbers[numbers]; //array to add the produced random numbers

    cout << "Input Numbers: ";

   //Numbers from [1,numbers]
    for(unsigned int i = 0; i < numbers; i++) {
        arr_ran_numbers[i] = i+1;
        cout << arr_ran_numbers[i] << ", ";
    }
   
    /*Random Numbers
    for(unsigned int i = 0; i < numbers; i++) {
        arr_ran_numbers[i] = random_number(rng);
        cout << arr_ran_numbers[i] << ", ";
    }
    */

    cout << endl << endl;

    vector<Node> vec; //create vector that takes Nodes type
    vec.reserve(numbers);
    for (size_t i = 0; i != numbers; ++i) 
        vec.push_back(Node(arr_ran_numbers[i],i)); //add the nodes to the vector

    unsigned int size = vec.size();
    unsigned int depth = log2(size) - 1;
    unsigned int steps = 2 * depth + 1;
    unsigned int level = log2(size);
    cout << "Level: " << level-- << endl;
    cout << "Leaves: ";

    for(unsigned int i = 0; i < numbers; i++)
       cout << arr_ran_numbers[i] << " ";
    
    cout << endl;
    up_traverse(vec);
    down_traverse(vec);
    
    cout << "Number of steps: " << steps << endl << endl;

    return 0;
}