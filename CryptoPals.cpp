#include "CryptoPals.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;
using std::runtime_error;


string
CryptoPals::ToUpper(const string& str)
{
   string out;
   out.reserve(str.size());
   for (int i = 0; i < str.size(); i++)
   {
      unsigned char c = str[i];
      if (c >= 97 && c <= 122) {
         c -= 32;
      }

      out.push_back(c);
   }

   return out;
}


string
CryptoPals::ToLower(const string& str)
{
   string out;
   out.reserve(str.size());
   for (int i = 0; i < str.size(); i++)
   {
      unsigned char c = str[i];
      if (c >= 65 && c <= 90) {
         c += 32;
      }

      out.push_back(c);
   }

   return out;
}


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


string
CryptoPals::HexDecode(const string& in)
{
   if (in.size() % 2 != 0)
   {
      throw runtime_error("Invalid hex string length.");
   }

   string hex;
   hex.reserve(in.size());
   string lowerIn = ToLower(in);
   for (int i = 0; i < lowerIn.size(); ++i)
   {
      unsigned char c = lowerIn[i];
      c -= 48;
      if (c > 9) {
         c -= 39;
      }

      if (c > 15 || c < 0) {
         throw runtime_error("Hex string contains invalid characters.");
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
   string out;
   try {
      string hexDecode = HexDecode(in);
      out.reserve(hexDecode.size() * 1.25f);
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
            out.push_back(base64Chars[tmp]);
         } else {
            out.push_back('=');
         }
         out.push_back('=');
      }
   } catch (const exception& e) {
      cout << e.what() << endl;
      throw e;
   }

   return out;
}


string
CryptoPals::Base64Decode(const string& str)
{
   if (str.size() % 4 != 0) {
      throw runtime_error("Invalid input string size.");
   }

   // TODO: Turn into a static variable
   const string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz"
                              "0123456789+/";

   string out;
   out.reserve(str.size() * 0.75f);
   for (int i = 3; i < str.size(); i += 4)
   {
      // TODO: Handle '=' correctly
      unsigned char a = base64Chars.find(str[i - 3]);
      unsigned char b = base64Chars.find(str[i - 2]);
      unsigned char c = base64Chars.find(str[i - 1]);
      unsigned char d = base64Chars.find(str[i]);

      out.push_back(a << 2 | b >> 4);
      out.push_back((b & 15) << 4 | c >> 2);
      out.push_back((c & 3) << 6 | d);
   }

   return out;
}

string
CryptoPals::FixedXOR(const string& aHex, const string& bHex)
{
   string out;
   if (aHex.size() != bHex.size()) {
      throw runtime_error("Incompatible string sizes.");
   }

   try {
      string a = HexDecode(aHex);
      string b = HexDecode(bHex);
      for (int i = 0; i < a.size(); ++i)
      {
         unsigned char r = FixedXOR(a[i], b[i]);
         out.push_back(r);
      }
   } catch (const exception& e) {
      cout << e.what() << endl;
      throw e;
   }

   return out;
}


unsigned char
CryptoPals::FixedXOR(const unsigned char& one, const unsigned char& other)
{
   unsigned char mask = 1;
   unsigned char r = 0;

   for (int bit = 0; bit < 8; ++bit)
   {
      if ((one & mask) != (other & mask)) {
         r = r | mask;
      }
      mask = mask << 1;
   }

   return r;
}


string
CryptoPals::SingleByteXOR(const string& str, const unsigned char& key)
{
   string out;
   try {
      string a = HexDecode(str);
      for (int i = 0; i < a.size(); ++i)
      {
         unsigned char mask = 1;
         unsigned char tmp = 0;
         for (int bit = 0; bit < 8; ++bit)
         {
            if ((a[i] & mask) != (key & mask)) {
               tmp = tmp | mask;
            }
            mask = mask << 1;
         }
         out.push_back(tmp);
      }
   } catch (const exception& e) {
      cout << e.what() << endl;
      throw e;
   }

   return out;
}


double
CryptoPals::GetCharFrequency(const string& str)
{
   double letters = 0.0f;
   for (int i = 0; i < str.size(); ++i)
   {
      unsigned char c = str[i];
      if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) {
         letters++;
      }
   }

   return letters / str.size();
}


unsigned char
CryptoPals::ScoreText(const string& str)
{
   double bestCoverage = 0.0f;
   unsigned char best;
   for (unsigned char c = 0; c < 255; ++c)
   {
      string out = SingleByteXOR(str, c);
      double coverage = GetCharFrequency(out);
      if (coverage > bestCoverage) {
         bestCoverage = coverage;
         best = c;
      }
   }

   return best;
}


string
CryptoPals::RepeatingKeyXOR(const string& str, const string& key)
{
   string out;
   out.reserve(str.size());

   size_t keySize = key.size();
   size_t ik = 0;
   for (int is = 0; is < str.size(); ++is)
   {
      unsigned char r = FixedXOR(str[is], key[ik]);
      out.push_back(r);

      ik = (ik + 1) % keySize;
   }

   return out;
}
