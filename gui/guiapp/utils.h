#ifndef UTILS_H
#define UTILS_H

#include <type_traits>

struct V16_FLAG {
    static constexpr int size = 16;
};
struct V9_FLAG {
    static constexpr int size = 9;
};

template <class T>
constexpr int size = T::size;

template <class T>
constexpr int cells_count = T::size * T::size;

template <class V16, class V9>
struct V16_V9_Switcher {
    static V16 judge(V16_FLAG&&);
    static V9 jedge(V9_FLAG&&);

    template<class T>
    struct SwitchBy {
        using type = decltype (jedge(T{}));
    };

};

#endif // UTILS_H
