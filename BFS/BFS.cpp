#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

void AddToQueueFromVector
(
	std::queue<char>& q,
	const std::vector<char>& vec,
	const char& currentNode,
	std::vector<char>& visited,
	std::unordered_map<char, char>& parents
)
{

	for (const auto& value : vec)
	{
		auto it = std::find(visited.begin(), visited.end(), value);
		if (it == visited.end())
		{
			parents[value] = currentNode;
			q.push(value);
			visited.push_back(value);
		}
	}
}

const void ShowPath
(
	std::unordered_map<char, char>& parents,
	char startNode,
	char currentNode,
	int& cnt
)
{
	if (currentNode == startNode)
	{
		std::cout << currentNode;
		return;
	}
	ShowPath(parents, startNode, parents[currentNode], cnt);
	std::cout << " -> " << currentNode;
	cnt++;
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
	std::queue<char> q;
	std::vector<char> visited;
	std::unordered_map<char, char> parents;

	q.push(startNode);
	visited.push_back(startNode);

	while (!q.empty())
	{
		char currentNode = q.front();
		q.pop();
		if (IsDestinationNode(currentNode, destinationNode))
		{
			std::cout << "We have found the path to the destination!" << std::endl;
			int cnt = 0;
			ShowPath(parents, startNode, destinationNode, cnt);
			std::cout << " " << cnt << std::endl;
			return true;
		}
		else
		{
			AddToQueueFromVector(q, graph[currentNode], currentNode, visited, parents);
		}
	}

	std::cout << "We haven't found the path to the destination." << std::endl;
	return false;
}

int main()
{
	std::unordered_map <char, std::vector<char>> graph;
	graph['a'] = { 'b' };
	graph['b'] = { 'h', 'c' };
	graph['h'] = { 'j', 'b' };
	graph['c'] = { 'j', 'd','k' };
	graph['j'] = { 'o', 'f','e', 'd', 'c', 'h' };
	graph['k'] = { 'c', 'l' };
	graph['f'] = { 'g', 'e' };
	graph['e'] = { 'f', 'j', 'm', 'd' };
	graph['d'] = { 'c', 'j', 'e', 'l' };
	graph['l'] = { 'k', 'n', 'm' };
	graph['m'] = { 'l', 'e' };

	char startNode;
	char destinationNode;

	std::cout << "startNode: ";
	std::cin >> startNode;

	std::cout << "destinationNode: ";
	std::cin >> destinationNode;

	SearchQueue(graph, startNode, destinationNode);

	return 0;
}
