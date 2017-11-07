#pragma once

#include "CryptoPals.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;
using std::runtime_error;
using std::ifstream;
using std::ios;
using std::istreambuf_iterator;
using std::istringstream;


bool
TestToUpper()
{
   string test = "TestToUpper";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "A1B2C3D4";
   string in = "a1b2c3d4";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->ToUpper(in);
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexEncode()
{
   string test = "TestHexEncoding";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "4A75727261736963205061726B";
   string in = "Jurrasic Park";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->ToUpper(cp->HexEncode(in));
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexDecode()
{
   string test = "TestHexDecoding";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "Jurrasic Park";
   string in = "4A75727261736963205061726B";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->HexDecode(in);
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexToBase64()
{
   string test = "TestHexToBase64";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
   string in = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->HexToBase64(in);
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestFixedXORA()
{
   string test = "TestFixedXORA";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "746865206b696420646f6e277420706c6179";
   string one = "1c0111001f010100061a024b53535009181c";
   string other = "686974207468652062756c6c277320657965";
   cout << "ONE      " << one << endl;
   cout << "OTHER    " << other << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->FixedXOR(one, other);
   string out = cp->HexEncode(outRaw);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestFixedXORB()
{
   string test = "TestFixedXORB";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "1c0111001f010100061a024b53535009181c";
   string one = "746865206b696420646f6e277420706c6179";
   string other = "686974207468652062756c6c277320657965";
   cout << "ONE      " << one << endl;
   cout << "OTHER    " << other << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->FixedXOR(one, other);
   string out = cp->HexEncode(outRaw);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestFixedXORC()
{
   string test = "TestFixedXORC";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "686974207468652062756c6c277320657965";
   string one = "746865206b696420646f6e277420706c6179";
   string other = "1c0111001f010100061a024b53535009181c";
   cout << "ONE      " << one << endl;
   cout << "OTHER    " << other << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->FixedXOR(one, other);
   string out = cp->HexEncode(outRaw);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestSingleByteXOR()
{
   string test = "TestSingleByteXOR";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "Cooking MC's like a pound of bacon";
   string in = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   unsigned char cipher = cp->ScoreText(in);
   string out = cp->SingleByteXOR(in, cipher);

   cout << "CIPHER   " << cipher << endl;
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool TestXORFile()
{
   string test = "TestXORFile";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   ifstream file;
   file.open("./tmp/task4.in", ios::in);

   if(!file)
   {
      cout << "Cannot open file." << endl;
      return false;
   }

   CryptoPals *cp = new CryptoPals();

   cout << "SCANNING FILE..." << endl;
   string strings((istreambuf_iterator<char>(file)),
                  istreambuf_iterator<char>());
   istringstream iss(strings);

   double bestCoverage = 0.0f;
   string best;
   unsigned char bestCipher;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   cout << "PRINTING 75+% COVERAGE" << endl;
   int count = 0;
   string tmp;
   while (getline(iss, tmp))
   {
      unsigned char cipher = cp->ScoreText(tmp);
      double coverage = cp->GetCharFrequency(cp->SingleByteXOR(tmp, cipher));
      if (coverage > bestCoverage) {
         bestCoverage = coverage;
         bestCipher = cipher;
         best = cp->SingleByteXOR(tmp, bestCipher);
      }

      if (coverage > 0.75f) {
         cout << coverage << "%   " << cp->SingleByteXOR(tmp, cipher) << endl;
         count++;
      }
   }
   cout << "BEST CANDIDATE " << best << endl;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;
   pass = count > 1;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexDecodeInvalidLength()
{
   string test = "TestHexDecodeInvalidLength";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "EXCEPTION";
   string in = "4A75727261736963205061726";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   try {
      string out = cp->HexDecode(in);
      cout << "OUT      " << out << endl;
      cout << "EXPECTED " << expected << endl;
   } catch(const exception& e) {
      cout << "EXCEPTION " << e.what() << endl;
      pass = true;
   }

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexDecodeInvalidCharacter()
{
   string test = "TestHexDecodeInvalidCharacter";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "EXCEPTION";
   string in = "4A757272v1736963205061726W";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   try {
      string out = cp->HexDecode(in);
      cout << "OUT      " << out << endl;
      cout << "EXPECTED " << expected << endl;
   } catch(const exception& e) {
      cout << "EXCEPTION " << e.what() << endl;
      pass = true;
   }

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestRepeatingKeyXOREncode()
{
   string test = "TestRepeatingKeyXOREncode";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a2622632427276527"
                     "2a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
   string in = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
   string key = "ICE";
   cout << "IN       " << in << endl;
   cout << "KEY      " << key << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->RepeatingKeyXOR(in, key);
   string out = cp->HexEncode(outRaw);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;
   pass = expected.compare(out) == 0;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestRepeatingKeyXORDecode()
{
   string test = "TestRepeatingKeyXORDecode";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
   string in = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a2622632427276527"
                     "2a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
   string key = "ICE";
   cout << "IN       " << in << endl;
   cout << "KEY      " << key << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string inDec = cp->HexDecode(in);
   string out = cp->RepeatingKeyXOR(inDec, key);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;
   pass = expected.compare(out) == 0;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestBase64Decode()
{
   string test = "TestBase64Decode";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
   string in = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->Base64Decode(in);
   string out = cp->HexEncode(outRaw);
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


void
RunTests()
{
   vector<bool> tests;
   int success = 0;

   tests.push_back(TestToUpper());
   tests.push_back(TestHexEncode());
   tests.push_back(TestHexDecode());
   tests.push_back(TestHexToBase64());
   tests.push_back(TestFixedXORA());
   tests.push_back(TestFixedXORB());
   tests.push_back(TestFixedXORC());
   tests.push_back(TestSingleByteXOR());
   tests.push_back(TestXORFile());
   tests.push_back(TestHexDecodeInvalidLength());
   tests.push_back(TestHexDecodeInvalidCharacter());
   tests.push_back(TestRepeatingKeyXOREncode());
   tests.push_back(TestRepeatingKeyXORDecode());
   tests.push_back(TestBase64Decode());

   for (bool test : tests)
   {
      success += test;
   }

   cout << "Success: " << success << " / " << tests.size() << endl;
}
