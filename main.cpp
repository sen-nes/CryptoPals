#include "CryptoPals.h"

#include <iostream>
#include <string>
#include <vector>

int
main()
{
   std::cout << "====================================================================================" << std::endl;
   CryptoPals cp;

   std::string in = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
   //std::string in = "Hello, Wolrd!";

   std::cout << "IN " << in << std::endl;
   std::string hex = cp.HexEncode(in);
   std::cout << "HEX " << hex << std::endl;

   std::string out = cp.HexDecode(hex);
   std::cout << "OUT " << out << std::endl;

   std::cout << "in == out ? " << (in.compare(out) == 0 ? "YES" : "NO") << std::endl;

   std::string expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
   std::string base64 = cp.HexToBase64(in);
   std::cout << std::endl << "BASE64 " << base64 << std::endl;

   std::cout << "expected == base64 ? " << (expected.compare(base64) == 0 ? "YES" : "NO") << std::endl;

   std::string one = "1c0111001f010100061a024b53535009181c";
   std::string other = "686974207468652062756c6c277320657965";
   std::string expectedXor = "746865206b696420646f6e277420706c6179";

   std::cout << std::endl << "ONE " << one << std::endl;
   std::cout << "OTHER " << other << std::endl;
   std::string xord = cp.FixedXOR(one, other);
   std::cout << "XOR " << xord << std::endl;

   std::cout << "expectedXor == xor ? " << (expectedXor.compare(xord) == 0 ? "YES" : "NO") << std::endl;

   return 0;
}
