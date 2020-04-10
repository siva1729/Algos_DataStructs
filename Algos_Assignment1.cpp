//===============================================================================
// Karasuba Multiply Algorithm (C++)
// Compare with Regular Multiply
//===============================================================================

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdint>

using namespace std;

// constants and defines
#define ADDSUBFTOR 12
#define MULTFTOR 3

typedef long long unsigned int lli_t;


//----------------------------------------------------
// Make two strings of equal length by pre-pending "0"s
//
//----------------------------------------------------
void MakeSameLengths (string& x, string& y, int& len) {
  int xlen = x.length();
  int ylen = y.length();
  len = (xlen > ylen) ? xlen : ylen;
  
  if (xlen < len) x = x.insert(0, len-xlen, '0');
  else if (ylen < len) y = y.insert(0, len-ylen, '0');

}

//----------------------------------------------------
// Add or Sub Strings based on flag
//   params: (string, string, bool)
//   return: string
// Assumption for subtraction x >= y
//----------------------------------------------------
string AddSubStrings (string x, string y, const bool& addop)
{

  int len = 0;
  MakeSameLengths (x,y,len);

  string out;
  int index = len - 1;
  int carry = 0;

  while (index >= 0) {

     int subLen = (index >= ADDSUBFTOR - 1) ? ADDSUBFTOR : (index + 1);
     lli_t xSub = stoull(x.substr(index - subLen + 1, subLen));
     lli_t ySub = stoull(y.substr(index - subLen + 1, subLen));

     string sumStr;

     // Addition
     if (addop) {
       sumStr = std::to_string(xSub + ySub + carry);
       if (sumStr.length() < (subLen + 1)) {
         sumStr.insert(0, subLen + 1 - sumStr.length(), '0');
       }
       carry = stoi(sumStr.substr(0,1));
       out.insert(0, sumStr.substr(1,16));
     }
     // Subtraction
     else {
       xSub -= carry;
       if (xSub < ySub) {
         xSub += pow(10,subLen);
         sumStr = std::to_string(xSub - ySub);
         carry = 1;
       }
       else {
         sumStr = std::to_string(xSub - ySub);
         carry = 0;
       }
       if (sumStr.length() < subLen) {
         sumStr.insert(0, subLen - sumStr.length(), '0');
       }
      out.insert(0, sumStr);
     }

     index -= subLen;
  }
  
  if (addop && carry > 0) out.insert(0, std::to_string(carry)); 

  return out;
  
}

//----------------------------------------------------
// RegularMultiply:
// Multiply input Strings 
//   params: (string, string)
//   return: string
//----------------------------------------------------
string RowMultiply (const string& x, const int& len, const int& y) {
  int index = len-1;
  string outStr("0");

  while (index >= 0) {
    int subLen  = (index >= MULTFTOR - 1) ? MULTFTOR : (index + 1);
    string multStr = std::to_string(y * stoull(x.substr(index-subLen+1, subLen)));
    multStr.insert(multStr.length(), len-index-1, '0');
    outStr = AddSubStrings(multStr, outStr, true);
    index -= subLen;
  }

  return outStr;
}
    

string RegularMultiply(string x, string y)
{
    int len = 0;
    MakeSameLengths (x,y,len);
    int xlen = x.length();
    int ylen = y.length();

    string outStr("0");

    for (int i=ylen-1; i >= 0 ; i--) {
      int ymult = stoi(y.substr(i,1));
      string rowStrProd = RowMultiply (x, xlen, ymult);
      rowStrProd.insert(rowStrProd.length(), ylen-i-1, '0');
      outStr = AddSubStrings(rowStrProd, outStr, true);
    } 

   return outStr;

}
		
//----------------------------------------------------
// KarasubaMultiply:
// Multiply input Strings 
//   params: (string, string)
//   return: string
//----------------------------------------------------
string KaratsubaMultiply(string x, string y)
{
    int len = 0;
    MakeSameLengths (x,y,len);

    if (len <= 1) {
        return std::to_string(stoi(x) * stoi(y));
    }

    size_t m = ceil(float(len) / 2);

    // get sub-strings
    string x_H = x.substr(0, len - m);
    string x_L = x.substr(len - m, m);
    string y_H = y.substr(0, len - m);
    string y_L = y.substr(len - m, m);

    // recursion
    string a = KaratsubaMultiply(x_H, y_H);
    string b = KaratsubaMultiply(x_L, y_L);
    string c = KaratsubaMultiply(AddSubStrings(x_H, x_L, true), AddSubStrings(y_H, y_L, true));
    string e = AddSubStrings(AddSubStrings(c,b,false), a, false);
    
    string empty_str;
    string asft = a + empty_str.assign(2*m, '0'); 
    string esft = e + empty_str.substr(0, m);
    
    return (AddSubStrings(AddSubStrings(asft, esft,true), b, true));

}

//----------------------------------------------------
// Main function
// tests for KarasubaMultiply and Regular Multiply
//----------------------------------------------------
int main(void)
{
    std::cout << "Hello World!\n";

#if 0
    string x = "5678";
    string y = "1234";
#endif

#if 1
    string x = "3141592653589793238462643383279502884197169399375105820974944592";
    string y = "2718281828459045235360287471352662497757247093699959574966967627";
    string refAddResult = "5859874482048838473822930854632165381954416493075065395941912219";
    string refSubResult = "0423310825130748003102355911926840386439922305675146246007976965";
    string refMulResult = "8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184";
#endif

#if 0
    string x = "944599999999999999092";
    string y = "9676299999999999887";
    string refMulResult = "9140232979999999884474119600000000102604";
#endif

#if 0
    string x = "9676000000000000000000000000000007";
    string y = "9440000000000000000000000092";
    string refAddResult = "9676009440000000000000000000000099";

#endif


    string mulResult;
    string addResult;
    string subResult;

    cout << "x size: " << x.size() << ", y size: " << y.size() << endl;
    addResult = AddSubStrings (x, y, true);
    subResult = AddSubStrings (x, y, false);

    cout << "==========================================" << endl;
    cout << "Add Strings: " << addResult << endl;
    if (addResult != refAddResult) cout << "*** !E: Add Strings Error..." << endl;
    else                           cout << "*** Add Strings Match..." << endl;

    cout << "==========================================" << endl;
    cout << "Sub Strings: " << subResult << endl;
    if (subResult != refSubResult) cout << "*** !E: Sub Strings Error..." << endl;
    else                           cout << "*** Sub Strings Match..." << endl;

    cout << "==========================================" << endl;
    mulResult = KaratsubaMultiply(x, y);
    cout << "Karatsub Mult: " << mulResult << endl;
    if (mulResult != refMulResult) cout << "*** !E: Mul Strings Error..." << endl;
    else                           cout << "*** Mul Strings Match..." << endl;

    cout << "==========================================" << endl;
    mulResult = RegularMultiply(x, y);
    cout << "Regular Mult: " << mulResult << endl;
    if (mulResult != refMulResult) cout << "*** !E: Mul Strings Error..." << endl;
    else                           cout << "*** Mul Strings Match..." << endl;

    return 0;

}
