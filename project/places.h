#ifndef PLACES_H
#define PLACES_H

#include <vector>
// RM_BEGIN
struct State {
    int budget;
    int gas;
    int max_gas;
    int gpm;
    int ppg;
};
// RM_END

class Place {
    int id;

    // This is a list of places you can get to from this place
    std::vector<Place *> adjacent;

public:
    Place(int id) : id(id) {
    }

    int get_id() const {
        return id;
    }

    std::vector<Place *> &get_adjacent() {
        return adjacent;
    }

    void add_adj(Place *place) {
        adjacent.push_back(place);
    }
    // RM_BEGIN
    bool seen = false;
    virtual bool visit(State &s) {
        if (s.gas < s.gpm) {
            return false;
        }

        s.gas -= s.gpm;
        return true;
    }
    // RM_END
};

class GasStation : public Place {
public:
    GasStation(int id) : Place(id) {
    }
    // RM_BEGIN
    bool visit(State &s) override {
        if (s.gas < s.gpm) {
            return false;
        }

        s.gas -= s.gpm;

        if ((s.max_gas - s.gas) * s.ppg > s.budget) {
            s.gas += s.budget / s.ppg;
            s.budget %= s.ppg;
        } else {
            s.budget -= (s.max_gas - s.gas) * s.ppg;
            s.gas = s.max_gas;
        }

        return true;
    }
    // RM_END
};

class TollGate : public Place {
    int fee;

public:
    TollGate(int id, int fee) : Place(id), fee(fee) {
    }

    int get_fee() const {
        return fee;
    }
    // RM_BEGIN
    bool visit(State &s) override {
        if (s.gas < s.gpm || s.budget < fee) {
            return false;
        }

        s.gas -= s.gpm;
        s.budget -= fee;
        return true;
    }
    // RM_END
};

#endif
