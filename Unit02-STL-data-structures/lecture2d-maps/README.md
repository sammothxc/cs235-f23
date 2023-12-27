# sets
In this learning activity, we will become familiar with sets, pairs and maps.  These containers are associative containers that do not reveal the order of insertion of items.  So, a number of items can be inserted into a set, but the set can use a binary search tree to store the items in the order that will be fastest to access.  Determining if an item is in the set can then be performed in O(logn) time.

Lets start with the basic syntax.  
```c++
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
    // Sets
    set <string> strset;
    strset.insert("bug");
    strset.insert("horse");
    strset.insert("horse");
    set<string>::iterator findit;
    findit = strset.find("horse");
    cout << "Found horse "<< *findit<<endl;
    for (set<string>::iterator it=strset.begin(); it!=strset.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
```
Notice that since the set container is a template class, we can have a set of any object.  When we insert two copies of the same object, the set retains only one of them.  You can use an iterator to access items in a set.  You can also determine the union, intersection or difference between sets.

Lets look at how we can use sets to determine the number of unique words from a document.  In this git repository, you can find a text file with all of the verses in 1 Nephi.  First, read the file into a vector of strings.  Notice the code to strip out anything that is not alphabetical.  Then we push the string into the vector and insert it into the set.  Notice the order of items in the set.  Unless you configure the set to use another order, it will arrange items alphabetically or numerically in the Binary Search Tree.  You should also notice that the vector is much bigger than the set because the set only keeps one copy of each item. 
```c++
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
```
You may wonder why you would want to use a set.  To answer that question, lets look at another container.  You can create a pair which will associate a first element with a second element.  In this case, we will associate a string with an integer.  Now, you can create a set of pairs that will contain relationships between keys in the first part of the pair with the integer value in the second part of the pair.  This is still not all that useful because you can only find the whole key-value pair. What you would really like is a container that allows you to look up keys and return values.
```c++
    // pairs
    pair <string,int> mypair;
    mypair.first = "Hello";
    mypair.second = 8;
    cout << mypair.first<<" "<<mypair.second<<endl;
    set <pair <string, int>> pairset;
    pairset.insert(mypair);
    set<pair <string, int>>::iterator findpair;
    findpair = pairset.find(mypair);
    cout << "found First "<<findpair->first<<" second "<<findpair->second<<endl;
```
Maps allow you to have a fully associative container using almost anything as a key and almost anything as a value.  Notice that you can index into a map using a string or any other object.  Maps are implemented with a balanced binary search tree in the same way that sets are, but they can be searched using the first element of the pair.  Notice that we can insert a pair directly into the map, or we can use the [] notation to add an element.  Iterators are used in all of the associative containers to 
```c++
    // maps
    map <string, int> wordcount;
    wordcount["foo"] = 5;
    cout << "wordcount for foo "<<wordcount["foo"]<<endl;
    wordcount.insert(mypair);
    cout << "wordcount for Hello "<<wordcount["Hello"]<<endl;
```
Lets put all of the words from 1 Nephi into the map, and increment the count associated with each word to get a count of how many times each word is used.
```c++
    wordcount.clear();
    for(auto s:tokens) {
        wordcount[s]++;
    }
    for (map<string,int>::iterator it=wordcount.begin(); it!=wordcount.end(); ++it)
        cout << it->first<<' ' << it->second<<endl;
    cout << endl;
```
Maps are an amazing container that can be used to look up any kind of key and return a value.  They are implemented in an efficient manner that can make your job as a programmer so much easier.
