#include "route.h"
// RM_BEGIN
#include <deque>
#include <stack>
#include <iostream>

bool dfs(std::vector<int> &ans, std::vector<Place *> &places, State s, Place *start, Place *curr, Place *dest, int d = 0) {
    // for (int i = 0; i < d; i++) {
    //     std::cout << " ";
    // }

    // std::cout << " " << curr->get_id() << " " << s.budget << " " << s.gas;

    if (!(curr == start || curr->visit(s))) {
        // std::cout << " #" << std::endl;
        return false;
    }

    // std::cout << " -> " << curr->get_id() << " " << s.budget << " " << s.gas;
    // std::cout << std::endl;

    ans.push_back(curr->get_id());

    if (curr == dest) {
        return true;
    }

    places.push_back(curr);
    curr->seen = true;

    for (auto a : curr->get_adjacent()) {
        if (!a->seen) {
            if (dfs(ans, places, s, start, a, dest, d + 1)) {
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

    dfs(ans, places, State{50, 10, 10, 3, 10}, start, start, dest);

    for (auto p : places) {
        p->seen = false;
    }

    return ans;
    // RM_END
}
