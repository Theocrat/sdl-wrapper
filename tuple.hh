#include <vector>

namespace sdlw {
    template <typename t>
    std::vector <t> tuple(t item) {
        std::vector <t> newTuple(0);
        newTuple.push_back(item);
        return newTuple;
    }

    template <typename t, typename... args>
    std::vector <t> tuple(t item, args... remainingItems) {
        auto existingItems = tuple(remainingItems...);
        existingItems.insert(existingItems.begin(), item);
        return existingItems;
    }
}