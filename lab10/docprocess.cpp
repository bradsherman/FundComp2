// Brad Sherman
// Fundamentals of Computing 2
// Lab 10
// Document Processor
//

#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cctype>

int main(){
	
	string fileone, filetwo;
	// Get first file name
	cout << "What is the name of your first file?" << endl;
	cin >> fileone;
	
	vector<string> words;
	
	// Open file 
	ifstream file1(fileone.c_str());
	string temp;
	while(!file1.eof()){
		if(file1 >> temp) {
			// Erase non-letters and make lowercase
			int i;
			for( i = 0; i < temp.size(); i++ ){
				if( !isalpha(temp[i]) || ispunct(temp[i])) {
					temp.erase(i,1); 
					i--;
				}
				else temp[i] = tolower(temp[i]);
			}
			words.push_back(temp);
		}
	}

	file1.close();

	// Sort, get rid of unique entries, and display
	sort(words.begin(),words.end());
	vector<string>::iterator it;
	it = unique(words.begin(),words.end());
	words.resize(distance(words.begin(),it));
//	for( it = words.begin(); it != words.end(); ++it ){
//		cout << *it << endl;
//	}
	cout << words.size() << " words in " << fileone << endl << endl;

	// Get second file
	cout << "What is the name of your second file?" << endl;
	cin >> filetwo;

	ifstream file2(filetwo.c_str());
	map<string,int> word_count;

	while(!file2.eof()){
		if(file2 >> temp){
			int i;
			// Erase non-letters and make lowercase
			for( i = 0; i < temp.size(); i++ ){
				if( !isalpha(temp[i]) || ispunct(temp[i])) {
					temp.erase(i,1);
					i--;
				}
				else temp[i] = tolower(temp[i]);

			}
			// Add entries to dictionary
			word_count.insert(pair<string,int>(temp,word_count[temp]++));
		}
	}
	file2.close();
	// Display contents
	map<string,int>::iterator j = word_count.begin();
	for( j = word_count.begin(); j!=word_count.end(); ++j ){
		cout << j->first << " => " << j->second << endl;
	}
	
////////////////////////////////////////////////////////////////////////////
/////  
/////             Post-lab Part 1
/////
////////////////////////////////////////////////////////////////////////////

	// Get files
	cout << "What is the name of the text file you are analyzing? " << endl;
	string textfile;
	cin >> textfile;

	cout << "What is the first language you are comparing it to? " << endl;
	string lang1;
	cin >> lang1;
	cout << "What is the name of the file containing the dictionary for this language?"<< endl;
	string lang1dict;
	cin >> lang1dict;

	cout << "What is the second language you are comparing it to? " << endl;
	string lang2;
	cin >> lang2;
	cout << "What is the name of the file containing the dictionary for this language?" << endl;
	string lang2dict;
	cin >> lang2dict;

	ifstream tf(textfile.c_str());
	ifstream l1(lang1dict.c_str());
	ifstream l2(lang2dict.c_str());
	vector<string> Dict1;
	vector<string> Dict2;

	// Read in dictionary words for both languages
	string line;
	while( !l1.eof() ){
		getline(l1,line);
		Dict1.push_back(line);
	}
	l1.close();
	sort(Dict1.begin(),Dict1.end());
	while( !l2.eof() ){
		getline(l2,line);
		Dict2.push_back(line);
	}
	l2.close();
	sort(Dict2.begin(),Dict2.end());

	int lang1count = 0;
	int lang2count = 0;

	string temp2;

	// Use binary search to find words in target document
	int i,k;
	while( !tf.eof() ){
		if( tf >> temp ) {
			for( i = 0; i < temp.size(); i++ ){
				if( !isalpha(temp[i]) || ispunct(temp[i])) {
					temp.erase(i,1);
					i--;
				}
				else temp[i] = tolower(temp[i]);
			}
			int s,e,mid,res,found,comps;
			s = 0;
			e = Dict1.size() - 1;
			mid = s + ((e - s + 1)/2);
			comps = 0;
			found = 0;
			while( s < e ) {
				res = temp.compare(Dict1[mid]);
				comps++;
				if( res == 0 ) {
					found = 1;
					s = e;
				}
				else if( res < 0 ) {
					e = mid-1;
					mid = s + ((e - s + 1)/2);
				}
				else{
					s = mid + 1;
					mid = s + ((e - s + 1)/2);
				}
			}
			if( found == 1 ) lang1count++;
			s = 0;
			e = Dict2.size() - 1;
			mid = s + ((e - s + 1)/2);
			comps = 0;
			found = 0;
			while( s < e ) {
				res = temp.compare(Dict2[mid]);
				comps++;
				if( res == 0 ) {
					found = 1;
					s = e;
				}
				else if( res < 0 ) {
					e = mid-1;
					mid = s + ((e - s + 1)/2);
				}
				else{
					s = mid + 1;
					mid = s + ((e - s + 1)/2);
				}
			}
			if( found == 1 ) lang2count++;

		}
	}
	tf.close();
	// Display number of matching words for each language and determine language of document
	cout << lang1 << " count: " << lang1count << endl;
	cout << lang2 << " count: " << lang2count << endl;
	if( lang2count > lang1count ) cout << "The document was written in " << lang2 << "." << endl;
	else if( lang1count > lang2count ) cout << "The document was written in " << lang1 << "." << endl;
	else if( lang2count == lang1count ) cout << "The document must have elements of " << lang1 << " and " << lang2 << "!" << endl;

///////////////////////////////////////////////////////////////////////////////////////////////
/////
/////         Jaccard Similarity
/////
///////////////////////////////////////////////////////////////////////////////////////////////

	// Get files
	cout << "Now we will compute the Jaccard Similarity of two documents." << endl;
	cout << "Enter the name of your first document." << endl;
	cin >> fileone;
	cout << "Enter the name of your second document." << endl;
	cin >> filetwo;

	vector<string> doc1;
	vector<string> doc2;
	set<string> intersection;
	set<string> un;

	// Read in words
	ifstream file11(fileone.c_str());
	while(!file11.eof()){
		if(file11 >> temp) {
			// Erase non-letters and make lowercase
			for( i = 0; i < temp.size(); i++ ){
				if( !isalpha(temp[i]) || ispunct(temp[i])) {
					temp.erase(i,1); 
					i--;
				}
				else temp[i] = tolower(temp[i]);
			}
			doc1.push_back(temp);
			un.insert(temp);
		}
	}
	file11.close();
	
	ifstream file22(filetwo.c_str());
	while(!file22.eof()){
		if(file22 >> temp) {
			// Erase non-letters and make lowercase
			for( i = 0; i < temp.size(); i++ ){
				if( !isalpha(temp[i]) || ispunct(temp[i])) {
					temp.erase(i,1); 
					i--;
				}
				else temp[i] = tolower(temp[i]);
			}
			doc2.push_back(temp);
			un.insert(temp);
		}
	}
	file2.close();

	// Add to intersection
	for( i = 0; i < doc1.size(); i++ ){
		for( k = 0; k < doc2.size(); k++ ){
			if( doc1[i] == doc2[k] ) intersection.insert(doc1[i]);
		}
	}
	// Compute Jaccard Similarity
	double intersectionsize,unionsize;
	intersectionsize = intersection.size();
	unionsize = un.size();
	cout << "Intersection size: " << intersectionsize << endl;
	cout << "Union size: " << unionsize << endl;
	double similarity;
	similarity = intersectionsize/unionsize;
	cout << "The Jaccard Similarity for " << fileone << " and " << filetwo << " is " << similarity << endl;

}
