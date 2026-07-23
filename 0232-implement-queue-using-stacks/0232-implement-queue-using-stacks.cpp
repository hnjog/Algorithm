class MyQueue {
public:
	MyQueue() {

	}

	void push(int x) {
		st1.push_back(x);
	}

	int pop() {
		if (st2.empty())
		{
			while (st1.empty() == false)
			{
				st2.push_back(st1.back());
				st1.pop_back();
			}
		}

		int ret = st2.back();
		st2.pop_back();
		return ret;
	}

	int peek() {
		if (st2.empty())
		{
			while (st1.empty() == false)
			{
				st2.push_back(st1.back());
				st1.pop_back();
			}
		}

		return st2.back();
	}

	bool empty() {
		return (st1.size() + st2.size()) == 0;
	}

private:
	vector<int> st1, st2;

};