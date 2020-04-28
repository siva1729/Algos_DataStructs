// myPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <string>
#include <cstdint>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>




using namespace std;

// Util functions
void print2DArray(int* a[], int nrows, int ncols) {
    int index = 0;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            cout << a[i][j] << ", ";
        }
        cout << endl;
    }
}


 class LLNode {
    int value;
 public:
    LLNode* next;
    LLNode(int x) : value(x), next(NULL) {};

    void PrintList(LLNode* head) {
        
        LLNode* node = head;
        while (node != NULL)
        {
            cout << node->value << endl;
            node = node->next;
        }
   }

#if 0
    LLNode* InsertNode(LLNode* head, int position)
    {
        LLNode* node = head;

        while (node != NULL && node->value != position)
        {
            node = node->next;
        }

        if (node->value = 
        {

        }

    }
#endif

};

#if 0
 LLNode* InsertNode(LLNode* head, int ival)
 {
     LLNode* prev_ptr = head;

     while (prev_ptr->next != NULL)
     {
         if (prev->value == )
     }
 }
#endif
 void FindDiffPairs(int (&a)[4])
 {
     for (int i = 0; i < 4; i++)
         cout << a[i] << endl;
 }


 void Log(const char* message)
 {  
     std::cout << message << std::endl;
 }

 int sum(int param1, int& param2)
 {
     cout << "Sum of " << param1 << "and " << param2 << " is " << param1 + param2 << endl;
     return 0;
 }

 class tClass {

    public:
     void operator()(int a, int b) {
         cout << "tClass sum is " << a + b << endl;
     }

 };


 void testChar()
 {
     char c = 'b';
     char s[] = "hello world";
     const char*  k = "hello567";

     k = "jim";
     c = 'a';
     //strcpy(p, "wen");

     printf("c = %c, k = %s. size s = %ld\n", c, k, sizeof(k));


     for (; *k; k++)
     {
         printf("%c\n", *k);
     }
     puts("k end");

 }

 void func(int i)
 {
     printf("I am int %d\n", i);
 }

 void func(const char* s)
 {
     printf(" I am char pointer %s", s);
 }

 int& retRef(int& i)
 {
     
     return ++i;
 }

void refTut()
 {
     int i = 9;
     int& rf = i;
     int& of = i;
     rf = 56;

     printf("rf = %d, i = %d, of = %d\n", rf, i, of);
     int& p = retRef(i);
     printf("rf = %d, i = %d, p = %d\n", rf, i, p);

     auto x = 2.0;
     printf("x = %f\n", x);



 }

/******************************************************/
// Class functions:
//
//
/*****************************************************/

class Cex {
    int _ai;
    string _si;

public:
    string name = "None";

    Cex(int ai = 0, const string si = "hello") : _ai(ai), _si(si) { puts("ctor: called\n"); };
    Cex(const Cex& rhs) : _ai(rhs._ai), _si(rhs._si) { puts("copy ctor called\n"); printValues(); }; // copy constructor

    Cex& operator = (const Cex& rhs) {
        printf("rhs name: %s, operator = called\n", rhs.name.c_str());
        this->_ai = rhs._ai;
        this->_si = rhs._si;
        return *this;
    }

    Cex operator + (const Cex& rhs) {
        printf("rhs name: %s, operator + called\n", rhs.name.c_str());
        this->_ai += rhs._ai;
        this->_si += rhs._si;
        return *this;
    }

    void printValues() const
    {
        printf("Object %s: ai = %d, si = %s\n",name.c_str(), _ai, _si.c_str());
    }

};

#if 0
void FileIO() {

    const char* fn1 = "file1.txt";
    const char fn2[] = "file2.txt";

    FILE** fp1; fopen_s(fp1, fn1, "w");
    FILE** fp2; fopen_s(fp2, fn2, "w+");

    
    
    const char* s = "My first string";

    for(auto p: {1, 2, 3, 4, 5}) {
        fprintf(*fp1, "%d: %s", p, s);
    }
   
}
#endif

/********************************************************/
// Topics: Algorithms & DataStructures
// 
/********************************************************/

//--------------------------------------------
// MergeSort Algorithm
//-------------------------------------------
void MergeArrays(int* a, int left, int mid, int right, int* numOfInversions) {
    static int count = 0;

    printf("Merge Arrays, count:%d, left:%d, mid:%d, right:%d\n", count++, left, mid, right);

    // Copy the left and right into temp arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* LArray = new int[n1];
    int* RArray = new int[n2];

    int i, j, k;

    for (i = 0; i < n1; i++) LArray[i] = a[left + i];
    
    for (i = 0; i < n2; i++) RArray[i] = a[mid + 1 + i];
        
    // Merger then into main array
    i = j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (LArray[i] <= RArray[j]) { a[k++] = LArray[i++]; }
        else  { a[k++] = RArray[j++]; 
                *numOfInversions += (n1 - i);
        }
    }

    while (i < n1) { a[k++] = LArray[i++]; }
    while (j < n2) { a[k++] = RArray[j++]; }

}


void MergeSort(int* a, int left, int right, const char * s, int* numOfInversions) {
    static int count = 0;
    printf("MergeSort %s count: %d. left: %d, right : %d\n", s, count++, left, right);

    if (left < right) {
        int mid = left + (right-left)/2;

        // Sort the two halves left and right
        MergeSort(a, left, mid, "left", numOfInversions);
        MergeSort(a, mid+1, right, "right", numOfInversions);

        MergeArrays(a, left, mid, right, numOfInversions);
    }
}


// Print size of variables/data-types
 void printIntSizes()
 {
     constexpr size_t bytes = 8;
     printf("size of char %d:\n", sizeof(char) * bytes);
     printf("size of short int %d:\n", sizeof(short int) * bytes);
     printf("size of int %d:\n", sizeof(int) * bytes);
     printf("size of float %d: \n", sizeof(float) * bytes);
     printf("size of long int %d: \n", sizeof(long int) * bytes);
     printf("size of long long int %d: \n", sizeof(long long int) * bytes);

     float f = 9.80f;
     double df = 9.809880;

     printf("f = %lf", f);
     printf("df = %lf", df);

     size_t jk = sizeof(int);
     printf("size of jk is %zd\n", jk);

     //f(NULL);
 }

 /*
 Cex& operator = (const Cex& rhs) {
     this->id = rhs.id;
     this->si = rhs.si;
     return *this;
 }
 */

 void testRef(int& i, int)
 {
     ++i;
 }

 typedef struct {
     bool wa : 1;
     bool wb : 1;
     unsigned int ai : 4;

 } mystruct;



 /********************************************/
 // Recursive Algorithms
 /********************************************/

 // Fibonacci number
 int fib(int n) {
     if (n <= 1) return 1;
     else return (fib(n - 1) + fib(n - 2));
 }

 int fibfor(int n) {

     int prevfib = 0;
     int fib = 1;
     for (int k = 0; k < n; k++)
     {
         int temp = fib;
         fib += prevfib;
         prevfib = temp;
     }
     return fib;
 }
 
 // Find Factorial 
 int factorial(int n)
 {
     if (n < 2) return 1;
     else return (n * factorial(n - 1));
 }

 
 

 //---------------------------------------------
 // Convert Binary to Hexadecimal
 //---------------------------------------------
 string getHexVal(const string& a) {
     string out;
     if (a == "0000") out = "0";
     else if (a == "0001") out = "1";
     else if (a == "0010") out = "2";
     else if (a == "0011") out = "3";
     else if (a == "0100") out = "4";
     else if (a == "0101") out = "5";
     else if (a == "0110") out = "6";
     else if (a == "0111") out = "7";
     else if (a == "1000") out = "8";
     else if (a == "1001") out = "9";
     else if (a == "1010") out = "A";
     else if (a == "1011") out = "B";
     else if (a == "1100") out = "C";
     else if (a == "1101") out = "D";
     else if (a == "1110") out = "E";
     else if (a == "1111") out = "F";
     else out = "ERR";

     return out;
 }

 int CharToDigit(char c) {
     int digit = int(c);
     if (digit >= '0' && digit <= '9') {
         digit = digit - '0';
     }
     else if (digit >= 'A' && digit <= 'F') {
         digit = digit - 'A' + 10;
     }
     else if (digit >= 'a' && digit <= 'f') {
         digit = digit - 'a' + 10;
     }
     else {
         digit = -1;
     }

     return digit;
 }

 int ConvToBase(string number, int base) {

     if (base < 2 || (base > 10 && base != 16) || number.length() == 0)  return -1;

     int value = 0;
     for (int i = number.length() - 1; i >= 0; i--) {
         char c  = number.at(i);
         int digit = CharToDigit(c);
         cout << "digit: " << digit << endl;
         if (digit < 0 || digit >= base) return -1;
         value += digit * pow(base, number.length() - 1 - i);
     }

     return value;
 }
 

 string convBin2Hex(string& s) {

     string outString("");

     if (s == "") return outString;
     cout << "s.len" << s.length() << endl;
     cout << "ceil: " << ceil(s.length() / 4.0) << endl;

     int k = (ceil(s.length() / 4.0) * 4) - s.length();

     cout << "k: " << k << endl;

     if (k != 0) {
         s.insert(0, k, '0');
     }
     cout << s << endl;

     int index = s.length();
     while (index > 0) {
         outString.insert(0, getHexVal(s.substr(index - 4, 4)));
         index -= 4;
     }
     outString.insert(0, "0x");
     return outString;
 }

 // convert String to Char Array
 char* convStringToCharArray(string& s) {
     char cArray[80];

     int i = 0;
     for (; i < s.length(); i++) {
         cArray[i] = s.at(i);
     }
     cArray[i] = '\0';

     return cArray;

 }

 void printArray(int* a, int count, int inv) {
     printf("Num of Inversions %d \n", inv);
     for (int i = 0; i < count; i++) {
         printf("%d, ", a[i]);
    }
     puts("\n");
 }

 //-----------------------------------------------------------
 // #20: Unique Characters
 //-----------------------------------------------------------
 bool UniqueString(string& s) {

     int slen = s.length();  
     if (slen == 0) return true;

     bool isUnique = true;

#if 0
     for (int i = 0; i < slen; i++) {
         for (int j = i+1; j < slen; j++) {
             if (s.at(i) == s.at(j)) {
                 isUnique = false; break;
             }
         }
     }
#endif

#if 0
     unordered_set<char> uset;
     for (int i = 0; i < s.length(); i++) {
         if (uset.find(s.at(i)) != uset.end()) {
             isUnique = false; break;
         }
         else {
             uset.insert(s.at(i));
         }
     }
#endif

#if 1
     std::sort(s.begin(), s.end());
     for (int i = 0; i < slen-1; i++) {
         if (s.at(i) == s.at(i + 1)) {
             isUnique = false; break;
         }
     }
         
#endif

     return isUnique;

 }

 //---------------------------------------------------------------
 // #21 String Permutation
 //----------------------------------------------------------------
 bool StringPermutation(string& s1, string& s2) {

     int s1Len = s1.length();
     int s2Len = s2.length();

     if (s1Len != s2Len) return false;

     bool isPermutation = true;

     cout << "space value: " << int(' ') << endl;

     // Method 1 O(n)
#if 0
     // assuming '8-bit' ascii characters in string take array of size 256
     // Initialized character count to "0"
     int Counts[256];
     memset(Counts, 0, sizeof(Counts));

     int a[5];
     memset(a, -1, sizeof(a));
     cout << "\na[0]: " << a[0] << endl;

     // increment based on s1 char and decrement for s2 char
     // If they are permutations eventually the Counts array should be all "0"s
     for (int i = 0; i < s1Len; i++) {
         int s1Char = int(s1.at(i));
         int s2Char = int(s2.at(i));
         Counts[s1Char] = Counts[s1Char] + 1;
         Counts[s2Char] = Counts[s2Char] - 1;
         cout << "-1 int value: " << '5' << endl;
     }
 
     // Check if all the values are "0"
     for (int i = 0; i < 256; i++) {
         if (Counts[i] != 0) { isPermutation = false; break; }
     }
#endif

     // Method 2 O(nLogn)
     sort(s1.begin(), s1.end());
     sort(s2.begin(), s2.end());

     for (int i = 0; i < s1.length(); i++) {
         if (s1.at(i) != s2.at(i)) {
             isPermutation = false; break;
         }
     }

     return isPermutation;

 }


 //---------------------------------------------------------------
 // #22 a3+B3 = c3 + d3 from 1 to N.
 //----------------------------------------------------------------
void PrintPair(pair<int, int> p1, pair<int, int> p2) {
    cout << p1.first << ", " << p1.second <<" "
         << p2.first << ", " << p2.second << endl;

 }

void PrintListPairs(list<pair<int, int>> lpair) {
    for (auto it = lpair.begin(); it != lpair.end(); it++) {
        cout << it->first << ", " << it->second << " ";
    }
    cout << endl;
}

void FindCubePairs(int K) {

# if 0
     for (int a = 0; a <= N; a++)
         for (int b = 0; b <= N; b++)
             for (int c = 0; c <= N; c++)
                 for (int d = 0; d <= N; d++)
                     if ((pow(a, 3) + pow(b, 3)) == (pow(c, 3) + pow(d, 3))) {
                         cout << a << "," << b << " : " << c << "," << d << endl;
                     }
#endif
     int N = 100;
     //typedef std::pair<int, int> pairs;
     using pairs = pair<int, int>;

     long int resultab;
     unordered_map<long int, list<pairs>> umap;

     for (int a = 0; a <= N; a++)
         for (int b = a+1; b <= N; b++) {
             resultab = pow(a, 3) + pow(b, 3);
             list<pairs> abpair;
             if (umap.find(resultab) != umap.end()) {
                 abpair = umap.at(resultab);
             }      
             abpair.push_back({ a,b });
             umap[resultab] = abpair;
         }

     unordered_map<long int, list<pairs>>::iterator it;
     
     for (it = umap.begin(); it != umap.end(); ++it) {
         list<pairs> mypairs = it->second;
         /*
         if (mypairs.size() > 1) {
             cout << it->first << ": " << endl;
             PrintListPairs(it->second);
         }*/
         
        
         list<pairs>::iterator pit;
         for (auto fit = mypairs.begin(); fit != mypairs.end(); fit++) {
             pair<int, int> firstPair = mypairs.front();
             mypairs.pop_front();
             for (auto sit = mypairs.begin(); sit != mypairs.end(); sit++) {
                 pair<int, int> secondPair = *sit;
                 cout << it->first << ": " << endl;
                 PrintPair(firstPair, secondPair);
             }
         }
     }

 }



 //---------------------------------------------------------------
 // #22 Replace all spaces in a String with ‘%20’
 //----------------------------------------------------------------
 string ReplaceWith(string s ) {

     int sLen = s.length(); 
     std::cout << "sLen: " << sLen << endl;

#if 0
     string out;

     int j = 0;
     for (int i = 0; j < sLen; i++) {
         if (s.at(i) == ' ') {
             out.append("%20"); j += 3;
         }
         else {
             out.push_back(s.at(i)); j++;
         }
     
     }
     return out;
#endif

     cout << "s: " << s << endl;
     int i = sLen -1;
     //while (s.at(i) == ' ') i--;
     //cout << "i at beinging" << i << endl;

     int j = sLen-1;
     while (i > 0 && j > 0) {
         while (s.at(i) == ' ') i--;
         while (s.at(i) != ' ') {
             s[j] = s.at(i); 
             s[i] = ' ';
             --i;
             --j;
         }
         s[j--] = '0';
         s[j--] = '2';
         s[j--] = '%';
         //cout << "int: s: " << s << " i,j" << i << "," << j << endl;

     }
     //cout << "final: s: " << s << "i, j" << i <<"," << j << endl;

     return s;
            
 }


 //---------------------------------------------------------------
 // #23 PALINDROME PERMUTATION
 //----------------------------------------------------------------
 bool PalindromePermutation(string s) {

     int sLen = s.length();
     std::cout << "sLen: " << sLen << endl;

     int sCounts[256] = { 0 };

     bool isValid = true;

     // Count the chars in the string (assumption each char is 8-bit)
     // Count only non-spaces..
     for (int i = 0; i < sLen; i++) {
         int digit = int(s.at(i));
         if (s.at(i) != ' ') sCounts[digit]++;
     }

     bool OddCount = false;
     for (int i = 0; i < 256; i++) {
         if (sCounts[i] % 2 == 1) {
             if (OddCount) { isValid = false; break; }
             else OddCount = true;
         }   
     }

     return isValid;

 }

 
//---------------------------------------------------------------
// #24 One Away
//----------------------------------------------------------------
 bool OneAway(string s1, string s2) {

     int s1Len = s1.length();
     int s2Len = s2.length();

     bool isValid = true;

     if (abs(s1Len - s2Len) > 1) return false;

     // Replace a character works
     if (s1Len == s2Len) {
         bool diffFound = false;
         for (int i = 0; i < s1Len; i++) {
             if (s1.at(i) != s2.at(i)) {
                 if (diffFound) {
                     isValid = false; break;
                 }
                 else diffFound = true;
             }
         }
     }
     else {
         int slLen = (s1Len > s2Len) ? s2Len : s1Len;
         string* sl = (s1Len > s2Len) ? &s2 : &s1;
         string* sg = (s1Len > s2Len) ? &s1 : &s2;

         int j;
         bool diffFound = false;
         for (int i = 0, j=0; j < slLen; ) {
             if (sl->at(i) != sg->at(j)) { 
                 if (diffFound) { isValid = false; break; }
                 else { diffFound = true; i++; }
             }
             else { i++; j++; }
         }

     }

     return isValid;

 }


//---------------------------------------------------------------
// #1.6 String Compression
//----------------------------------------------------------------
 string StringCompression(string s) {

     int sLen = s.length();

     if (sLen < 3) return s;

     string out;

     char prevChar = s.at(0);
     int prevCount = 1;
     for (int i = 1; i < sLen; i++) {
         if (s.at(i) != prevChar) {
             out = out + prevChar + std::to_string(prevCount);
             prevChar = s.at(i);
             prevCount = 1;
         }
         else {
             prevCount++;
         }
     }

     out = out + prevChar + std::to_string(prevCount);
     
     if (out.length() > s.length()) return s;
     else return out;

 }

//---------------------------------------------------------------
// #1.7 Rotatematrix90
//----------------------------------------------------------------
 enum  SWAPPATTERN  { CIRI=0, RICD, CDRD, RDCI };

 void RotateMatrix90(int** a, int N) {
     if (N < 2) return;

     for (int iter = 0; iter < N/2; iter++) {
         int minIndex = iter;
         int maxIndex = N - minIndex - 1;
         int swapLength = maxIndex - minIndex;

         for (int colIndex = minIndex; colIndex < maxIndex; colIndex++) {
             int row = minIndex;
             int col = colIndex;
             int pixelValue = a[row][col];
             int swapPattern = CIRI;
             int swapRow = 0, swapCol = 0;

             for (int sides = 0; sides < 4; sides++) {
                 if (swapPattern == CIRI) {
                    if ((col + swapLength) > maxIndex) {
                         swapRow = row + (col + swapLength - maxIndex);
                         swapCol = maxIndex;
                     }
                     else {
                         swapRow = row;
                         swapCol = col + swapLength;
                     }  
                    swapPattern = RICD;
                 }
                 else if (swapPattern == RICD) {
                     if ((row + swapLength) > maxIndex) {
                         swapCol = col - (row + swapLength - maxIndex);
                         swapRow = maxIndex;
                     }
                     else {
                         swapRow = row + swapLength;
                         swapCol = col;
                     }
                     swapPattern = CDRD;
                 }
                 else if (swapPattern == CDRD) {
                     if ((col - swapLength) < minIndex) {
                         swapRow = row - (minIndex - (col - swapLength));
                         swapCol = minIndex;
                     }
                     else {
                         swapRow = row;
                         swapCol = col - swapLength;
                     }
                     swapPattern = RDCI;
                 }
                 else if (swapPattern == RDCI) {
                     if ((row - swapLength) < minIndex) {
                         swapCol = col + (minIndex - (row - swapLength));
                         swapRow = minIndex;
                     }
                     else {
                         swapRow = row - swapLength;
                         swapCol = col;
                     }
                     swapPattern = CIRI;
                 }

                 // Update/swap pixel value
                 int temp = a[swapRow][swapCol];
                 a[swapRow][swapCol] = pixelValue;
                 pixelValue = temp;

                 // Update (row,col), incrRowCol
                 row = swapRow;
                 col = swapCol;

             }
         }
     }


 }

//---------------------------------------------------------------
// #1.8 ZeroMatrix
//----------------------------------------------------------------
 void ZeroMatrix(int** a, int M, int N) {

     // Mark the rows and Cols with "0"s
     unordered_set<int> rowSet;
     unordered_set<int> colSet;

     for (int i = 0; i < M; i++) {
         bool zeroFound = false;
         for (int j = 0; j < N; j++) {
             if (a[i][j] == 0) {
                 rowSet.insert(i);
                 colSet.insert(j);
                 zeroFound = true;
             }
             else if (zeroFound) {
                 a[i][j] = 0;
             }
         }
     }

     // Set the input matrix
     for (int i = 0; i < M; i++) {
         for (int j = 0; j < N; j++) {
             if (a[i][j] == 0) break;
             else if (rowSet.find(i) != rowSet.end() || colSet.find(j) != colSet.end())
                 a[i][j] = 0;
         }
     }


 }
        

//---------------------------------------------------------------
// #1.9 StringRotation
//----------------------------------------------------------------

 bool StringRotation(string s1, string s2) {

     if (s1.length() != s2.length()) return false;

#if 0 
     // s1 = s1 + s1, then look for s2 in s1
     s1.append(s1);
     if (s1.find(s2)) return true;
     else return false;
#endif

     int i = 0;
     int j = 0;
     bool valid = false;

     int k = 0;
     for (int i = 0; i < s1.length();) {
         if (s1.at(i) == s2.at(j)) {
             i++; j++; valid = true;
             ++k;
         }
         else {
             j++; valid = false;
             k = 0;
         }
         if (j >= s1.length()) j = 0;
     }

     if (k != s1.length()) valid = false;

     return valid;

 }


 //---------------------------------------------------------------
// GCD of two integers
//----------------------------------------------------------------

 int GCDIntegers(int a, int b) {

    if (a == 0 || b == 0) return -1;

    int Num = (a > b) ? a : b;
    int Den = (a > b) ? b : a;

    int gcd = 1;
    while (Num % Den != 0) {
            int temp = Den;
            Den = Num % Den;
            Num = temp;
            gcd = Den;     
    } 

    return gcd;

 }
     
#if 0
 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 // Main function()
 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
    std::cout << "Hello World!\n";
    Log("Hello World\n");


//#20
#if 0
    string s1 = "abc defik";
    string s2 = "abcdefgha";
    cout << "s1: " << s1 << " " << (UniqueString(s1) ? "true": "false") << endl;
    cout << "s2: " << s2 << " " << (UniqueString(s2) ? "true": "false") << endl;
#endif

//#21
#if 0
    //string s1 = "abcad"; string s2 = "dcaba";
    string s1 = "ddbdca"; string s2 = "cabdda";
    cout << "s1: " << s1 << " s2: " << s2 << (StringPermutation(s1, s2) ? " true" : " false") << endl;
#endif

//#22
#if 0
    //string s1 = "abcad"; string s2 = "dcaba";
    string s1 = " am Sumit Jain      ";
    cout << "s1: " << s1 << " Replace with %20: " << ReplaceWith(s1) << endl;
#endif

//#23
#if 0
    //string s1 = "abcad"; string s2 = "dcaba";
    string s1 = "tacocat";
    string s2 = "taco cat";
    string s3("atco cta");

    cout << "string: " << s3 << " isValid: " << (PalindromePermutation(s3) ? "true": "false") << endl;
#endif

//#24
#if 0
    //string s1 = "pale"; string s2 = "ple";
    //string s1 = "pales"; string s2 = "pale";
    //string s1 = "pale"; string s2 = "bale";
    string s1 = "pale"; string s2 = "bake";
     
    cout << "s1: " << s1 << " s2: " << s2 << " isValid: " << (OneAway(s1, s2) ? "true" : "false") << endl;
#endif

//#1.6
#if 0

    //string s1 = "aabcccccaaa";
    string s1 = "ABABAB";

    cout << "string: " << s1 << " out: " << StringCompression(s1) << endl;
#endif

//#1.7
#if 0
    int nrows = 5;
    int ncols = 5;

    int** a = new int* [nrows];

    int index = 0;
    for (int i = 0; i < nrows; i++) {
        a[i] = new int [ncols];
        for (int j = 0; j < ncols; j++) {
           a[i][j] = index++;
        }
        cout << "a[][]: " << a[i][ncols-1] << endl;
    }

   print2DArray(a, nrows, ncols);
   RotateMatrix90(a, nrows);
   printf("-------------------------\n");
   print2DArray(a, nrows, ncols);

#endif

//#1.8
#if 0
   string s1 = "ACDBAA";
   string s2 = "BAAACD";

   cout << "StringRotation: s1, s2" << s1 << ", " << s2 << (StringRotation(s1, s2) ? " true" : " false") << endl;

#endif

#if 0
   int num1 = 20, num2 = 31;
   cout << "gcd of integers " << num1 << ", " << num2 << ": " << GCDIntegers(num1, num2) << endl;

#endif

#if 1
   int N = 10;
   FindCubePairs(N);

#endif



#if 0
    const char* myName = "Sreedhar";
    char c;

    string s("C++String");
    printf("Char Array: %s\n", convStringToCharArray(s));
    
    int a[9] = { 8,0, 1, 4, 5, 6, 9, 0, 5 };
    int sizea = sizeof(a) / sizeof(a[0]);
#endif

#if 0
    printArray(a, sizea, 0);
    int inv = 0;
    MergeSort(a, 0, sizea - 1, "start", &inv
    printArray(a, sizea, inv);
#endif

#if 0
    string number1 = "01001";
    string number2 = "A";
    string number3 = "";
    printf("I am Here..\n");
    printf("convToBase(%s, %d): %d\n", number1.c_str(), 2, ConvToBase(number1, 2));
    printf("convToBase(%s, %d): %d\n", number2.c_str(), 16, ConvToBase(number2, 16));
    printf("convToBase(%s, %d): %d\n", number3.c_str(), 2, ConvToBase("", 2));

#endif



#if 0
    int fn = 5;
    printf("Factorial(%d) = %d\n", fn, factorial(fn));
    printf("Fib(%d) = %d\n", fn, fib(fn));

    for (int k = 1; k < 10; k++)
        if (fib(k) != fibfor(k)) printf("Error not matching %d", k);
#endif


#if 0
    string bins = "010001101111000110110";
    cout << "HexString: " << convBin2Hex(bins) << endl;

    string k = "234";
    cout << "substr: " << k.substr(0, 1) << endl;

    puts("c5 = c2 + c3\n");
    c5 = c2 + c3;

    c1.printValues();
    c2.printValues();
    c3.printValues();
#endif


    

  }

#endif
