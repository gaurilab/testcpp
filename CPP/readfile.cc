#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
int main() {
  const char* filename = "ntegerArray.txt";
  std::ifstream inFile(filename);

  // Make sure the file stream is good
  if(!inFile) {
    cout << endl << "Failed to open file " << filename;
    return 1;
  }

  long n = 0;
  while(!inFile.eof()) {
    inFile >> n;
    cout<< n <<endl;
  }
  cout << endl;
  return 0;
}
