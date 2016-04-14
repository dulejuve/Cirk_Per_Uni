#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define NumMatrxFix 51

using namespace std;

char ch = '?', a;
int k[NumMatrxFix], n[NumMatrxFix], p[NumMatrxFix], br = 0, brCir = 0;

void readFromFileResm(string filename)
{
	string line;
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//  cout << line << '\n';
			for (unsigned int i = 0; i<line.length(); i++)
			{
				// cout <<line[i]<<endl; // print one character per line
				if (line[i] == ch)
				{
					k[br] = line[i + 2] - 48;
					//n[br]=line[i+4]-48;
					//p[br]=line[i+6]-48;
					//getline(myfile,line);
					p[br] = line[i + 4] - 48;
					// cout << k[br] <<n[br] <<p[br] << '\n';
					//cout << k[br] <<p[br] << '\n';
					br++;
				}
			}
		}
		myfile.close();
	}

	//string str2 ("?"); //check line with "?"
	ifstream fin(filename);
	if (fin.is_open())
	{
		while (getline(fin, line))
		{

			// different member versions of find in the same order as above:
			size_t found = line.find(ch);
			if (found != string::npos)
			{
				//cout << "first '?' found at: " << found << '\n';
				getline(myfile, line);
				// cout << line << "\n";
			}
			else
			{
				CirMatAll[brCir] = atoi(line.c_str());
				// i = atoi(line.c_str());
				cout << CirMatAll[brCir] << " ";
				brCir++;
			}
		}
	}
	fin.close();
}


//void ReadFilePermut(string filename)
//{
//	vector <string> words; // Vector to hold our words we read in.
//	string str; // Temp string to
//	int counterPerFrile = 1;
//	ifstream fin(filename); // Open it up!
//	if (fin.is_open())
//	{
//		//cout << " " << fin.getline(str1, 10,'_') << "\n";
//		//file opened successfully so we are here
//		cout << "\nFile Opened successfully!. Reading data from Permutation file into array." << endl;
//		while (fin >> str) // Will read up to eof() and stop at every
//		{                  // whitespace it hits. (like spaces!)
//			words.push_back(str);
//			//InvPerm1[counterPerFrile]=atoi(str.c_str());
//		}
//		fin.close(); // Close that file!
//
//		for (unsigned int i = 0; i < words.size(); ++i)
//		{
//			//cout << words.at(i) << endl; // Print so I can see this all worked!
//			InvPerm[i + 1] = atoi(words.at(i).c_str());
//		}
//	}
//	else //file could not be opened
//	{
//		cout << "File could not be opened." << endl;
//	}
//
//	//cout << "Print Permutation file:\n";
//	for (int i = 0; i < sizeSbox; ++i)
//		cout << InvPerm[i] << " ";
//}

