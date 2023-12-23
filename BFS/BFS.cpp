#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <string>

void AddToDequeFromVector
(
    std::deque<char>& dq,
    const std::vector<char>& vec,
    const char& currentNode,
    std::vector<char>& visited
)
{
    auto it = std::find(visited.begin(), visited.end(), currentNode);

    if (it == visited.end())
    {
        visited.push_back(currentNode);
        for (const auto value : vec)
        {
            dq.push_back(value);
        }
    }
}

void ShowPath
(
    std::unordered_map<char, char> parents,
    char startNode,
    char destinationNode
)
{
    std::vector<char> path;
    std::cout << "Path: ";
    char currentNode = destinationNode;
    
}

bool IsDestinationNode(const char& currentNode, const char& destinationNode)
{
    return currentNode == destinationNode;
}

bool SearchQueue
(
    std::unordered_map<char, std::vector<char>> graph, 
    char startNode, 
    char destinationNode
)
{
    std::deque<char> dq;
    std::vector<char> visited;
    std::unordered_map<char, char> parents;

    AddToDequeFromVector(dq, graph[startNode], startNode, visited);
    

    while (!dq.empty())
    {
        char currentNode = dq.front();
        dq.pop_front();
        if (IsDestinationNode(currentNode, destinationNode))
        {
            std::cout << "We have found the path to the destination!" << std::endl;
            //ShowPath(parents, startNode, destinationNode);
            return true;
        }
        else
        {
            AddToDequeFromVector(dq, graph[currentNode], currentNode, visited);
        }
    }

    std::cout << "We haven't found the path to the destination." << std::endl;
    return false;
}

int main()
{

    std::unordered_map <char, std::vector<char>> graph;
    graph['a'] = { 'b' };
    graph['b'] = { 'c', 'h' };
    graph['h'] = { 'j', 'b'};
    graph['c'] = { 'j', 'd','k'};
    graph['j'] = { 'o', 'f','e', 'd', 'c', 'h'};
    graph['k'] = { 'c', 'l'};
    graph['f'] = { 'g', 'e'};
    graph['e'] = { 'f', 'j', 'm', 'd'};
    graph['d'] = { 'c', 'j', 'e', 'l'};
    graph['l'] = { 'k', 'n', 'm'};
    graph['m'] = { 'l', 'e'};

    char startNode;
    char destinationNode;

    std::cout << "startNode: ";
    std::cin >> startNode;

    std::cout << "destinationNode: ";
    std::cin >> destinationNode;

    SearchQueue(graph, startNode, destinationNode);

    return 0;
}
