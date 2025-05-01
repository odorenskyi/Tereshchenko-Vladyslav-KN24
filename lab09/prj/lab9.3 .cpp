#include <iostream>
#include <bitset>

int task_9_3(int N) {
    if ((N >> 9) & 1) {
        std::bitset<32> bits(N);
        return 32 - bits.count();  
    } else {
        std::bitset<32> bits(N);
        return bits.count();
    }
}
