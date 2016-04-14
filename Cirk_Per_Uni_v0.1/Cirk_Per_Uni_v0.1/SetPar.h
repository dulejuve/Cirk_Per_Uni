#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//======Function set parametar Size of S-box and Binary===========
void SetPar(string filename)
{
	vector <string> words; // Vector to hold our words we read in.
	string str; // Temp string to
	ifstream fin(filename); // Open it up!
	if (fin.is_open())
	{
		//cout << " " << fin.getline(str1, 10,'_') << "\n";
		//file opened successfully so we are here
		cout << "Permutation File Opened successfully!.\n";
		while (fin >> str) // Will read up to eof() and stop at every
		{                  // whitespace it hits. (like spaces!)
			words.push_back(str);
			//InvPerm1[counterPerFrile]=atoi(str.c_str());
		}
		fin.close(); // Close that file!

		sizeSbox = words.size() + 1;
	}
	else //file could not be opened
	{
		cout << "File could not be opened." << endl;
	}

	//Set Binary for 4 bit S-box
	if (sizeSbox == 16)
		binary = 5;
	//Set Binary for 8 bit S-box
	if (sizeSbox == 256)
		binary = 9;
}
//==================================================================

//====Function count number of circulant matrix=====================
void readNumOfMatrix(string filename)
{
	char ch = '?';
	int br = 0;

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
					br++;
				}
			}
		}
		myfile.close();
		NumMatrx = br;
	}
}
//====================================================================
