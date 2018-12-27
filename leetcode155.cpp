#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() : _sta(stack<int>()), _min_val(0) {

	}

	void push(int x) {
		if (_sta.empty())
		{
			_min_val = x;
			_sta.push(0);
		}
		else
			_sta.push(x - _min_val);
		if (x < _min_val)
			_min_val = x;
			
	}

	void pop() {
		int top = _sta.top();
		if (top < 0)
			_min_val = _min_val - top;
		_sta.pop();
	}

	int top() {
		if (_sta.top() > 0)
			return _sta.top() + _min_val;
		else
			return _min_val;
	}

	int getMin() {
		return _min_val;
	}

private:
	int _min_val;
	stack<int> _sta;
};