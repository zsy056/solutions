#include <cstdint>
#include <cstdio>

class Solution {
    public:

        uint8_t cov[256];
        uint8_t cov_4[16] = { 0, 8, 4, 12, 2, 10, 6, 14,
                              1, 9, 5, 13, 3, 11, 7, 15};

        Solution() {
            for (uint16_t i=0; i<256; ++i) {
                cov[i] = cov_4[i >> 4] + (cov_4[i & 0x0f] << 4);
            }
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
