//Header file Function: Convert int to string
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Function Int to String Convert and Concatenate
string IntToStringAndConcate ( int number, string str )
{
  ostringstream oss;

  // Works just like cout
  oss<< str << number<<".txt";

  // Return the underlying string
  return oss.str();
 }

//Function retun if filename (string) exist
bool fexists(const string& filename) 
{
	bool exists = false;
  ifstream ifile(filename.c_str());
  if (ifile)
  {
	  exists = true;
  }
  return exists;
  //return ifile;
}

string FexistsNumber(int indexOutputResult, string OutputResultBody, string NameFile_OutputResult) 
{ 
	while(fexists(NameFile_OutputResult)==1)
	{
	indexOutputResult++;
	NameFile_OutputResult = IntToStringAndConcate(indexOutputResult, OutputResultBody);
	}
	return NameFile_OutputResult;
}