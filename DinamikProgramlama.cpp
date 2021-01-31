#include <bits/stdc++.h>
using namespace std;

bool dictionary_contain(string str, string* dictionary, int num)
{
    for (int i = 0; i < num; i++) {
       
        if (dictionary[i].compare(str) == 0)
            return true;
    }
    return false;
}

bool word_split(string s, vector<int>& ind, string* dictionary, int num)
{
    int len = s.size();
    if (len == 0)
        return true;
    ind.push_back(-1);
    for (int i = 0; i < len; i++) {
    	
        int size = ind.size();
        int tag = 0;
        
        for (int j = size - 1; j >= 0; j--) {
        	
            string sb = s.substr(ind[j] + 1, i - ind[j]);
            
            if (dictionary_contain(sb, dictionary, num)) {
                tag = 1;
                break;
            }}
            
        if (tag) {
           ind.push_back(i);
        }}}

int main()
{
    string s = "erismekistedikleribirhedefiolmayanlarcalismaktanzevkalmazlar";
    
    string dictionary[] = { "ak","azla","eki","kalma",
                                 "al","azlar","er","kalmaz",
                                 "al","bir","eri","kalmazlar",
                                 "alý","cal","eris","kist",
                                 "alýþ","cali","erisme","kiste",
                                 "alýþma","calis","erismek","maya",
                                 "alýþmak","calisma","ev","ol",
                                 "alýþmakta","calismak","fi","olma",
                                 "alýþmaktan","calismakta","hedef","olmaya",
                                 "alma","calismaktan","hedefi","olmayan",
                                 "almaz","de","is","olmayanla",
                                 "almazlar","def","iste","olmayanlar",
                                 "an","dik","istedi","ta",
                                 "anla","dikler","istedik","tan",
                                 "anlar","dikleri","istedikleri","ya",
                                 "ayan","ede","iþ","yan",
                                 "az","ek","kal","zevk" };
                                 
    int num = sizeof(dictionary) / sizeof(dictionary[0]);
    
    vector<int> ind;
    if (word_split(s, ind, dictionary, num)) {
    	cout<<"erismekistedikleribirhedefiolmayanlarcalismaktanzevkalmazlar"<<endl;
        cout << "True" << endl;
	   vector<int>::iterator it;
        string str = "";
        int last = s.size();
        int len = 0;
        
        int* arr = new int[ind.size()];
        
        for (it = ind.begin(); it != ind.end(); it++) {
        	
            arr[len++] = *it;
        }
        list<string> word;
        for (int i = len - 1; i >= 0; i--) {
        	
            str = s.substr(arr[i] + 1, last - arr[i]);
            
            if (dictionary_contain(str, dictionary, num)) {
            	
                last = arr[i];
                
                word.push_front(str);
                 }}
        list<string>::iterator i;
        for (i = word.begin(); i != word.end(); i++) {
              cout << *i << " ";
           }}
        else {
        cout << "false" << endl;
        }}
