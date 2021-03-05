#include <iostream>
#include <bitset>
#include <cstdint>

int main(int argc, char *argv[])
{
    std::cout << "Hello world!";

    std::bitset<4> p1{0b0110};
    std::bitset<4> p2{0b1010};

    std::cout << "<==========================>\nBitwise  'or'\n";
    std::cout << "p1: " << p1 << "\np2: " << p2 << "\n ----------------------- \n";
    std::cout << (p1 | p2) << "\n";

    std::cout << "<==========================>\nBitwise  'and'\n";
    std::cout << "p1: " << p1 << "\np2: " << p2 << "\n ----------------------- \n";
    std::cout << (p1 & p2) << "\n";

    std::cout << "<==========================>\nBitwise  'not'\n";
    std::cout << "p1: " << p1 << "\np2: " << p2 << "\n ----------------------- \n";
    std::cout << "p1: " << (~p1) << "\n";

    std::cout << "<==========================>\nBitwise  'xor'\n";
    std::cout << "p1: " << p1 << "\np2: " << p2 << "\n ----------------------- \n";
    std::cout << (p1 ^ p2) << "\n";

    std::cout << "<==========================>\nBitwise  shif left\n";
    std::cout << "p1: " << p1 << "\np2: " << p2 << "\n ----------------------- \n";
    std::cout << "p1: " << (p1 << 1) << "\n";

    std::cout << "<==========================>\nBitwise  shif right\n";
    std::cout << "p1: " << p1 << "\np2: " << p2 << "\n ----------------------- \n";
    std::cout << "p1: " << (p1 >> 1) << "\n";

    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint_fast8_t subject{ 0b0100'0011 };

    std::cout << "<==========================>\nSetting a bit\n";
    std::cout << "subject[1]: " << ((subject & mask1) ? "1" : "0") << "\n ----------------------- \n";
    subject |= mask1;
    std::cout << "subject[1]: " << ((subject & mask1) ? "1" : "0") << "\n"<< "mask: 0b0000'0010" << '\n';

    std::cout << "<==========================>\nResetting a bit\n";
    std::cout << "subject[1]: " << ((subject & mask1) ? "1" : "0") << "\n ----------------------- \n";
    subject &= ~mask1;
    std::cout << "subject[1]: " << ((subject & mask1) ? "1" : "0") << "\n"<< "mask: 0b0000'0010" << '\n';

    std::cout << "<==========================>\nFlipping a bit\n";
    std::cout << "subject[1]: " << ((subject & mask1) ? "1" : "0") << "\n ----------------------- \n";
    subject ^= mask1;
    std::cout << "subject[1]: " << ((subject & mask1) ? "1" : "0") << "\n";
    subject ^= mask1;
    std::cout << "subject[1]: " << ((subject & mask1) ? "1" : "0") << "\n"<< "mask: 0b0000'0010" << '\n';

    std::cout << "<==========================>\nConversion and cast\n";
    int a = static_cast<int>(p1.to_ulong());
    std::cout << "p1 to int: " << a << "\n";
    std::bitset<4> b = static_cast<std::bitset<4>>(3);
    std::cout << "'3' to bits: " << b << "\n";
}   