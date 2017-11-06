#include "CryptoPals.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

string
CryptoPals::HexEncode(const string& in)
{
   const char *hexChars = "0123456789abcdef";

   string out;
   out.reserve(in.size() * 2); // + 1
   for (int i = 0; i < in.size(); ++i)
   {
      const unsigned char c = in[i];
      out.push_back(hexChars[c >> 4]);
      out.push_back(hexChars[c & 15]);
   }

   return out;
}


// TODO: Ensure in length is an even number
string
CryptoPals::HexDecode(const string& in)
{
   string hex;
   hex.reserve(in.size());
   for (int i = 0; i < in.size(); ++i)
   {
      unsigned char c = in[i];
      c -= 48;
      if (c > 9) {
         c -= 7;
         if (c > 15) {
            c -= 32;
         }
      }

      hex.push_back(c);
   }

   string out;
   for (int i = 1; i < hex.size(); i += 2)
   {
      out.push_back(((hex[i - 1] << 4) | (hex[i])));
   }

   return out;
}


string
CryptoPals::HexToBase64(const string& in)
{
   const char *base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz"
                             "0123456789+/";

   string hexDecode = HexDecode(in);
   string out;
   // out.reserve(in.size())
   for (int i = 2; i < hexDecode.size(); i += 3)
   {
      const unsigned char a = hexDecode[i - 2];
      const unsigned char b = hexDecode[i - 1];
      const unsigned char c = hexDecode[i];

      out.push_back(base64Chars[a >> 2]);
      out.push_back(base64Chars[((a & 3) << 4) | (b >> 4)]);
      out.push_back(base64Chars[((b & 15) << 2) | (c >> 6)]);
      out.push_back(base64Chars[c & 63]);
   }

   // TODO: REWORK
   if (hexDecode.size() % 3 != 0) {
      unsigned char a = 0;
      unsigned char b = 0;
      if (hexDecode.size() % 3 == 1) {
         a = hexDecode[hexDecode.size() - 2];
         b = hexDecode[hexDecode.size() - 1];
      } else {
         a = hexDecode[hexDecode.size() - 1];
         b = 0;
      }
      const unsigned char c = 0;

      out.push_back(base64Chars[a >> 2]);
      out.push_back(base64Chars[((a & 3) << 4) | (b >> 4)]);

      unsigned char tmp = (((b & 15) << 2) | (c >> 6));
      if (tmp != 0)
      {
         out.push_back(base64Chars[((b & 15) << 2) | (c >> 6)]);
      } else {
         out.push_back('=');
      }
      out.push_back('=');
   }

   return out;
}

string
CryptoPals::FixedXOR(const string& aHex, const string& bHex)
{
   string out;
   if (aHex.size() == bHex.size()) {
      string a = HexDecode(aHex);
      string b = HexDecode(bHex);
      for (int i = 0; i < a.size(); ++i)
      {
         unsigned char mask = 1;
         unsigned char tmp = 0;
         for (int bit = 0; bit < 8; ++bit)
         {
            if ((a[i] & mask) != (b[i] & mask)) {
               tmp = tmp | mask;
            }
            mask = mask << 1;
         }
         out.push_back(tmp);
      }
   }
   return HexEncode(out);
}