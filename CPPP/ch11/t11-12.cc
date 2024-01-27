#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

vector<pair<string, int>> into_pair(vector<string> &vs, vector<int> &vi)
{
	auto i_iter = vi.begin();
	vector<pair<string, int>> vpsi;
	for (auto &rs : vs) {
		vpsi.push_back({rs, *i_iter++});
	}
	return vpsi;
}