// n^2 + 2n runtime
// aka poop

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char* argv[])
{
	stack<int> s;
	queue<int> q;

	// create stack
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	// push stack to queue
	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}

	int n_min, n_max;
	while (!q.empty())
	{
		// push first onto stack
		s.push(q.front());
		q.pop();

		// Check if empty
		if (q.empty())
			break;

		// rotate queue to last value
		n_max = q.size() - 1;
		while (n_max > 0)
		{
			q.push(q.front());
			q.pop();

			n_max--;
		}

		// Check if empty
		if (q.empty())
			break;

		// push first onto stack
		s.push(q.front());
		q.pop();
	}

	// reverse order of stack
	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	while (!q.empty())
	{
		s.push(q.front());
		q.pop();
	}


	// print stack
	cout << "\nStack: \n";
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	// print queue
	cout << "\nQueue: \n";
	while (!q.empty())
	{
		cout << q.front();
		q.pop();
	}

	// wait
	cin.get();
	return 0;
}