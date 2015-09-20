#include <cstdint>
#include <cstdio>

constexpr uint8_t cov_4[] = { 0, 8, 4, 12, 2, 10, 6, 14,
                              1, 9, 5, 13, 3, 11, 7, 15};

uint8_t cov[256] = { 0 };

template<uint8_t n>
struct Mapping {
    static constexpr uint8_t value = cov_4[n >> 4] + (cov_4[n & 0x0f] << 4);

    static void init() {
        Mapping<n-1>::init();
        cov[n] = value;
    }
};

template<>
struct Mapping<128> {
    static constexpr uint8_t value = cov_4[128 >> 4] + (cov_4[128 & 0x0f] << 4);

    static void init() {
        cov[128] = value;
    }
};

template<>
struct Mapping<0> {
    static constexpr uint8_t value = 0;

    static void init() {
        cov[0] = value;
    }
};

class Solution {
    public:

        Solution() {
            Mapping<255>::init();
            Mapping<127>::init();
        }

        uint32_t reverseBits(uint32_t n) {
            // DCBA -> ABCD
            uint8_t a[4] = { 0 };
            uint8_t b[4] = { 0 };
            for (auto i=0; i<4; ++i) {
                a[i] = *(reinterpret_cast<uint8_t*>(&n) + i);
                b[3-i] = cov[a[i]];
            }
            return *reinterpret_cast<uint32_t*>(b);
        }
};

int main()
{
    Solution s;
    printf("%u\n", s.reverseBits(43261596));
    return 0;
}
