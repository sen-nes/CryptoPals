#include "CryptoPals.h"

#include <iostream>
#include <string>
#include <vector>

int
main()
{
   std::cout << "====================================================================================" << std::endl;
   CryptoPals cp;
   Res hex = cp.StringToHex("Hello World");
   std::cout << hex.hexString << std::endl;

   std::string inHex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
   std::cout << inHex << std::endl;

   std::string expectedb64 = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
   std::string b64 = cp.HexBase64Encode(inHex);
   std::cout << b64 << std::endl;
   

   std::cout << "SUCCESS : " << (expectedb64.compare(b64) == 0) << std::endl;
   return 0;
}
