//Guillermo García
#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <functional>
#include <sstream>

int main()
{
	stack<int> miStack;
	queue<int> miQueue;
	priority_queue<int, vector<int>, greater<int>> miPQ; //Con MIN-HEAP

	string data, d;
	getline(cin, data);

	int x, y, res;

	while (data != "#") {
		stringstream ss;
		ss << data;
		while (ss >> d) {
			//PROCESOS
			if (d == "+") {
				//STACK
				x = miStack.top();
				miStack.pop();
				y = miStack.top();
				miStack.pop();

				miStack.push(y + x);

				//QUEUE
				x = miQueue.front();
				miQueue.pop();
				y = miQueue.front();
				miQueue.pop();

				miQueue.push(y + x);

				//PRIORITY QUEUE
				x = miPQ.top();
				miPQ.pop();
				y = miPQ.top();
				miPQ.pop();

				miPQ.push(y + x);
			}
			else if (d == "-") {
				//STACK
				x = miStack.top();
				miStack.pop();
				y = miStack.top();
				miStack.pop();

				miStack.push(y - x);

				//QUEUE
				x = miQueue.front();
				miQueue.pop();
				y = miQueue.front();
				miQueue.pop();

				miQueue.push(y - x);

				//PRIORITY QUEUE
				x = miPQ.top();
				miPQ.pop();
				y = miPQ.top();
				miPQ.pop();

				miPQ.push(y - x);
			}
			else if (d == "*") {
				//STACK
				x = miStack.top();
				miStack.pop();
				y = miStack.top();
				miStack.pop();

				miStack.push(y * x);

				//QUEUE
				x = miQueue.front();
				miQueue.pop();
				y = miQueue.front();
				miQueue.pop();

				miQueue.push(y * x);

				//PRIORITY QUEUE
				x = miPQ.top();
				miPQ.pop();
				y = miPQ.top();
				miPQ.pop();

				miPQ.push(y * x);
			}
			else {
				miStack.push(stoi(d));
				miQueue.push(stoi(d));
				miPQ.push(stoi(d));
			}
		}
		cout << miStack.top() << " " << miQueue.front() << " " << miPQ.top() << endl;
		miStack.pop();
		miQueue.pop();
		miPQ.pop();

		getline(cin, data);
	}
}