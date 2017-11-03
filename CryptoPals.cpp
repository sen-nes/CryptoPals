#include "CryptoPals.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

Res
CryptoPals::StringToHex(const string& in)
{
   const char *hexChars = "0123456789ABCDEF";
   Res out;
   out.hexString.reserve(in.size() * 2);
   for (int i = 0; i < in.size(); ++i)
   {
      const unsigned char c = in[i];
      out.hexString.push_back(hexChars[c >> 4]);
      out.hex.push_back(c >> 4);
      out.hexString.push_back(hexChars[c & 15]);
      out.hex.push_back(c & 15);
   }

   return out;
}


#include <iostream>
using std::cout;
using std::endl;

vector<unsigned char>
CryptoPals::HexStringToVector(const string& in)
{
   vector<unsigned char> hex(in.size());
   for (int i = 0; i < in.size(); ++i)
   {
      unsigned char tmp = in[i] - 48;
      if (tmp > 9) {
         tmp = in[i] - 87;
      }
      hex[i] = tmp;
   }

   return hex;
}


string
CryptoPals::HexBase64Encode(const string& inS)
{
   const char *base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz"
                             "0123456789";

   vector<unsigned char> in = HexStringToVector(inS);
   string out;
   // out.reserve(in.size())
   for (int i = 2; i < in.size(); i += 3)
   {
      const unsigned char a = in[i - 2];
      const unsigned char b = in[i - 1];
      const unsigned char c = in[i];

      out.push_back(base64Chars[(a << 2) | (b >> 2)]);
      out.push_back(base64Chars[((b & 3) << 4) | (c)]);
   }

   if (in.size() % 3 != 0) {
      unsigned char a = 0;
      unsigned char b = 0;
      if (in.size() % 3 == 1) {
         a = in[in.size() - 2];
         b = in[in.size() - 1];
      } else {
         a = in[in.size() - 1];
         b = 0;
      }
      const unsigned char c = 0;
   
      out.push_back(base64Chars[(a << 2) | (b >> 2)]);
      out.push_back(base64Chars[((b & 3) << 4) | (c)]);
   }

   return out;
}