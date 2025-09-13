#include "route.h"
// RM_BEGIN
#include <deque>
#include <stack>

bool dfs(std::vector<int> &ans, std::vector<Place *> &places, State s, Place *start, Place *curr, Place *dest) {
    if (!(curr == start || curr->visit(s))) {
        return false;
    }

    ans.push_back(curr->get_id());

    if (curr == dest) {
        return true;
    }

    places.push_back(curr);
    curr->seen = true;

    for (auto a : curr->get_adjacent()) {
        if (!a->seen) {
            if (dfs(ans, places, s, start, a, dest)) {
                return true;
            }
        }
    }

    curr->seen = false;
    ans.pop_back();
    return false;
}
// RM_END

std::vector<int> find_route(Place *start, Place *dest) {
    // RM_BEGIN
    std::vector<int> ans;
    std::vector<Place *> places;

    dfs(ans, places, State{100, 10, 10, 3, 5}, start, start, dest);

    for (auto p : places) {
        p->seen = false;
    }

    return ans;
    // RM_END
}
