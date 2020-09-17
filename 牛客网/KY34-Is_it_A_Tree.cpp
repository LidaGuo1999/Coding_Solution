/* 问题描述：A tree is a well-known data structure that is either empty (null, void, nothing) or is a set of one or more nodes connected by directed edges between nodes satisfying the following properties. There is exactly one node, called the root, to which no directed edges point. Every node except the root has exactly one edge pointing to it. There is a unique sequence of directed edges from the root to each node. For example, consider the illustrations below, in which nodes are represented by circles and edges are represented by lines with arrowheads.
 * In this problem you will be given several descriptions of collections of nodes connected by directed edges. For each of these you are to determine if the collection satisfies the definition of a tree or not.
 *
 * 输入描述：The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers. Each test case will consist of a sequence of edge descriptions followed by a pair of zeroes Each edge description will consist of a pair of integers; the first integer identifies the node from which the edge begins, and the second integer identifies the node to which the edge is directed. Node numbers will always be greater than zero and less than 10000.
 *
 * 输出描述：For each test case display the line "Case k is a tree." or the line "Case k is not a tree.", where k corresponds to the test case number (they are sequentially numbered starting with 1)
 */

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int start, end, k = 1;
    map<int, int> from;
    set<int> nodes;
    while (scanf("%d %d", &start, &end) != EOF && start >= 0) {
        if (start == 0) {
            if (nodes.size() == 0) printf("Case %d is a tree.\n", k);
            else if (nodes.size() == from.size()+1) printf("Case %d is a tree.\n", k);
            else printf("Case %d is not a tree.\n", k);
            from.clear();
            nodes.clear();
            k++;
            continue;
        }
        
        nodes.insert(start);
        nodes.insert(end);
        if (start != end && from.find(end) == from.end()) {
            from[end] = start;
        } else {
            printf("Case %d is not a tree.\n", k);
            from.clear();
            nodes.clear();
            k++;
            while (scanf("%d %d", &start, &end) != EOF && start != 0) {}
        }
    }
}
